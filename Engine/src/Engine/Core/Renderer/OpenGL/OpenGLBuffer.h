#pragma once
#include <Renderer/Buffer.h>

namespace Engine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* aVertices, uint32_t aSize);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const AttributeArray& GetAttributeArray() const override { return mAttributeArray; }
		virtual void SetAttributeArray(const AttributeArray& aArray) override { mAttributeArray = aArray; }

	private:
		uint32_t mRendererID;
		AttributeArray mAttributeArray;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* aIndices, uint32_t aSize);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual uint32_t GetCount() const override { return mCount; }

	private:
		uint32_t mRendererID;
		uint32_t mCount;
	};
}
