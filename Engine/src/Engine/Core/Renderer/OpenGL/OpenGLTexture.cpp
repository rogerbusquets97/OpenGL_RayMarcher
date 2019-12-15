#include "OpenGLTexture.h"
#include <Log/Log.h>

namespace Engine
{
	Engine::OpenGLTexture2D::OpenGLTexture2D(uint32_t aWidth, uint32_t aHeight) : mWidth(aWidth), mHeight(aHeight), mRendererID(0), mInternalFormat(GL_RGBA8), mDataFormat(GL_RGBA)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &mRendererID);
		glTextureStorage2D(mRendererID, 1, mInternalFormat, mWidth, mHeight);
		glTextureParameteri(mRendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(mRendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTextureParameteri(mRendererID, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(mRendererID, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &mRendererID);
	}

	void OpenGLTexture2D::SetData(void* aData, uint32_t aSize)
	{
		if (aSize == mWidth * mHeight * (mDataFormat == GL_RGBA ? 4 : 3))
		{
			glTextureSubImage2D(mRendererID, 0, 0, 0, mWidth, mHeight, mDataFormat, GL_UNSIGNED_BYTE, aData);
		}
		else
		{
			ENGINE_CORE_ERROR("Texture: SetData: Data must be the same size as the texture!");
		}
	}

	void OpenGLTexture2D::Bind(uint32_t aSlot) const
	{
		glBindTextureUnit(aSlot, mRendererID);
	}

	OpenGLRenderTexture2D::OpenGLRenderTexture2D(uint32_t aWidth, uint32_t aHeight) : mWidth(aWidth), mHeight(aHeight), mRendererID(0), mInternalFormat(GL_RGBA32F), mDataFormat(GL_RGBA), mAccessLevel(GL_WRITE_ONLY)
	{
		glCreateTextures(GL_TEXTURE_2D, 1, &mRendererID);
		glTextureStorage2D(mRendererID, 1, mInternalFormat, mWidth, mHeight);
		glTextureParameteri(mRendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(mRendererID, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri(mRendererID, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTextureParameteri(mRendererID, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	}
	OpenGLRenderTexture2D::~OpenGLRenderTexture2D()
	{
		glDeleteTextures(1, &mRendererID);
	}
	void OpenGLRenderTexture2D::Bind(uint32_t aSlot) const
	{
		glBindTexture(GL_TEXTURE_2D, mRendererID);
		glBindImageTexture(aSlot, mRendererID, 0, GL_FALSE, 0, mAccessLevel, mInternalFormat);
	}
}
