#include "OpenGLComputeShader.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <Log/Log.h>

namespace Engine
{
	OpenGLComputeShader::OpenGLComputeShader() : mID(0)
	{
	}


	OpenGLComputeShader::~OpenGLComputeShader()
	{
	}

	void OpenGLComputeShader::Load(const char * aSource)
	{
		std::string SourceCode;

		std::ifstream ShaderFile;

		ShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

		try
		{
			ShaderFile.open(aSource);
			std::stringstream ShaderStream;

			ShaderStream << ShaderFile.rdbuf();

			ShaderFile.close();

			SourceCode = ShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			ENGINE_CORE_ERROR(e.what());
		}

		Compile(SourceCode.c_str());
	}

	void OpenGLComputeShader::Bind()
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

	void OpenGLComputeShader::Unbind()
	{
		glUseProgram(0);
	}

	void OpenGLComputeShader::Dispatch(unsigned int aSizeX, unsigned int aSizeY, unsigned int aSizeZ)
	{
		glDispatchCompute((GLuint)aSizeX, (GLuint)aSizeY, (GLuint)aSizeZ);
	}

	void OpenGLComputeShader::SetBool(const std::string & aName, bool aValue) const
	{
		glUniform1i(glGetUniformLocation(mID, aName.c_str()), (int)aValue);
	}

	void OpenGLComputeShader::SetInt(const std::string & aName, int aValue) const
	{
		glUniform1i(glGetUniformLocation(mID, aName.c_str()), aValue);
	}

	void OpenGLComputeShader::SetFloat(const std::string & aName, float aValue) const
	{
		glUniform1f(glGetUniformLocation(mID, aName.c_str()), aValue);
	}

	void OpenGLComputeShader::SetVec2(const std::string & aName, glm::vec2 aValue) const
	{
		glUniform2fv(glGetUniformLocation(mID, aName.c_str()), 1, &aValue[0]);
	}

	void OpenGLComputeShader::SetiVec2(const std::string& aName, glm::ivec2 aValue) const
	{
		glUniform2iv(glGetUniformLocation(mID, aName.c_str()), 1, &aValue[0]);
	}

	void OpenGLComputeShader::Compile(const char* aSource)
	{
		unsigned int Source;
		Source = glCreateShader(GL_COMPUTE_SHADER);
		glShaderSource(Source, 1, &aSource, NULL);
		glCompileShader(Source);
		CheckCompileErrors(Source, "COMPUTE");

		mID = glCreateProgram();
		glAttachShader(mID, Source);

		glLinkProgram(mID);
		CheckCompileErrors(mID, "PROGRAM");

		glDeleteShader(Source);
	}

	void OpenGLComputeShader::CheckCompileErrors(unsigned int aShader, std::string aType)
	{
		GLint Success;
		GLchar Logs[1024];

		glGetShaderiv(aShader, aType != "PROGRAM" ? GL_COMPILE_STATUS : GL_LINK_STATUS, &Success);
		if (!Success)
		{
			glGetShaderInfoLog(aShader, 1024, NULL, Logs);
			ENGINE_CORE_ERROR(Logs);
		}
	}


}
