#pragma once
#include <Renderer/VertexArray.h>

namespace Engine
{
	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& aBuffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& aBuffer) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const override { return mVertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const override { return mIndexBuffer; }

	private:
		uint32_t mRendererID;
		uint32_t mCurrentVertexIndex;
		std::vector<std::shared_ptr<VertexBuffer>> mVertexBuffers;
		std::shared_ptr<IndexBuffer> mIndexBuffer;
	};
}
