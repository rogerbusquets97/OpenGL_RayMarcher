#pragma once
#include <Renderer/AttributeArray.h>

namespace Engine
{
	class VertexBuffer
	{
	public:

		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual const AttributeArray& GetAttributeArray() const = 0;
		virtual void SetAttributeArray(const AttributeArray& aArray) = 0;

		static std::shared_ptr<VertexBuffer> Create(float* aVertices, uint32_t aSize);
	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual uint32_t GetCount() const = 0;

		static std::shared_ptr<IndexBuffer> Create(uint32_t* aIndices, uint32_t aSize);
	};
}