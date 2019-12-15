#pragma once
#include <Core.h>
#include <Renderer/Texture.h>
#include <glad/glad.h>

namespace Engine
{
	class OpenGLTexture2D : public Texture2D
	{
	public:
		OpenGLTexture2D(uint32_t aWidth, uint32_t aHeight);
		virtual ~OpenGLTexture2D();

		virtual uint32_t GetWidth() const override { return mWidth; }
		virtual uint32_t GetHeight() const override { return mHeight; }

		virtual void SetData(void* aData, uint32_t aSize) override;
		virtual void Bind(uint32_t aSlot = 0) const override;

	private:
		uint32_t mWidth, mHeight;
		uint32_t mRendererID;
		GLenum mInternalFormat, mDataFormat;
	};

	class OpenGLRenderTexture2D : public RenderTexture2D
	{
	public:
		OpenGLRenderTexture2D(uint32_t aWidth, uint32_t aHeight);
		virtual ~OpenGLRenderTexture2D();

		virtual uint32_t GetWidth() const override { return mWidth; }
		virtual uint32_t GetHeight() const override { return mHeight; }

		virtual void Bind(uint32_t aSlot = 0) const override;

	private:
		uint32_t mWidth, mHeight;
		uint32_t mRendererID;
		GLenum mInternalFormat, mDataFormat, mAccessLevel;
	};
}