#include "OpenGLShader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <Log/Log.h>

//https://learnopengl.com/

namespace Engine
{

	OpenGLShader::OpenGLShader() : mID(0), mLoaded(false)
	{
	}
	
	OpenGLShader::~OpenGLShader()
	{
		Unload();
	}

	void Engine::OpenGLShader::Load(const std::string& aPath)
	{
		if (!mLoaded)
		{
			std::string VertexCode;
			std::string FragmentCode;

			std::ifstream ShaderFile;

			ShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

			try
			{
				ShaderFile.open(aPath.c_str());
				std::stringstream ShaderStream;

				ShaderStream << ShaderFile.rdbuf();

				ShaderFile.close();

				VertexCode = "#version 440 core\n#define COMPILING_VERTEX\n" + ShaderStream.str();
				FragmentCode = "#version 440 core\n#define COMPILING_FRAGMENT\n" + ShaderStream.str();
			}
			catch (std::ifstream::failure e)
			{
				ENGINE_CORE_ERROR(e.what());
			}

			Compile(VertexCode.c_str(), FragmentCode.c_str());
			mLoaded = true;
		}
	}

	void OpenGLShader::Unload()
	{
		if (mLoaded)
		{
			glDeleteProgram(mID);
			mLoaded = false;
		}
	}

	void Engine::OpenGLShader::Bind()
	{
		if (mID != 0)
		{
			glUseProgram(mID);
		}
		else
		{
			ENGINE_CORE_ERROR("Tried to use an invalid shader");
		}
	}

	void OpenGLShader::Unbind()
	{
		glUseProgram(0);
	}

	void Engine::OpenGLShader::SetBool(const std::string & aName, bool aValue) const
	{
		glUniform1i(glGetUniformLocation(mID, aName.c_str()), (int)aValue);
	}

	void Engine::OpenGLShader::SetInt(const std::string & aName, int aValue) const
	{
		glUniform1i(glGetUniformLocation(mID, aName.c_str()), aValue);
	}

	void Engine::OpenGLShader::SetFloat(const std::string & aName, float aValue) const
	{
		glUniform1f(glGetUniformLocation(mID, aName.c_str()), aValue);
	}

	void OpenGLShader::SetVec2(const std::string & aName, glm::vec2 aValue) const
	{
		glUniform2fv(glGetUniformLocation(mID, aName.c_str()), 1, &aValue[0]);
	}

	void OpenGLShader::SetMat4(const std::string& aName, const glm::mat4& aValue) const
	{
		glUniformMatrix4fv(glGetUniformLocation(mID, aName.c_str()), 1, GL_FALSE, &aValue[0][0]);
	}

	void OpenGLShader::Compile(const char* aVertex, const char* aFragment)
	{
		unsigned int vertex, fragment;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &aVertex, NULL);
		glCompileShader(vertex);
		CheckCompileErrors(vertex, "VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &aFragment, NULL);
		glCompileShader(fragment);
		CheckCompileErrors(fragment, "FRAGMENT");

		mID = glCreateProgram();
		glAttachShader(mID, vertex);
		glAttachShader(mID, fragment);

		glLinkProgram(mID);
		CheckCompileErrors(mID, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void OpenGLShader::CheckCompileErrors(unsigned int aShader, std::string aType)
	{
		GLint Success;
		GLchar Logs [1024];

		glGetShaderiv(aShader, aType != "PROGRAM" ? GL_COMPILE_STATUS : GL_LINK_STATUS, &Success);
		if (!Success)
		{
			glGetShaderInfoLog(aShader, 1024, NULL, Logs);
			ENGINE_CORE_ERROR("Shader error: ");
			ENGINE_CORE_ERROR(Logs);
		}
	}
}
