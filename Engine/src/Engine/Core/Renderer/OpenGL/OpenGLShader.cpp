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

	OpenGLShader::OpenGLShader() : mID(0)
	{
	}
	
	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(mID);
	}

	void Engine::OpenGLShader::Load(const char * aVertex, const char * aFragment)
	{
		std::string VertexCode;
		std::string FragmentCode;

		std::ifstream vShaderFile;
		std::ifstream fShaderFile;

		vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			vShaderFile.open(aVertex);
			fShaderFile.open(aFragment);
			std::stringstream vShaderStream, fShaderStream;

			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();

			vShaderFile.close();
			fShaderFile.close();

			VertexCode = vShaderStream.str();
			FragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			ENGINE_CORE_ERROR(e.what());
		}

		Compile(VertexCode.c_str(), FragmentCode.c_str());
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
			ENGINE_CORE_ERROR(Logs);
		}
	}
}
