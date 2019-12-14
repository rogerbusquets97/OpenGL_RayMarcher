#include "OpenGLBuffer.h"
#include <glad/glad.h>

namespace Engine
{
	Engine::OpenGLVertexBuffer::OpenGLVertexBuffer(float * aVertices, uint32_t aSize) : mRendererID(0), mAttributeArray()
	{
		glCreateBuffers(1, &mRendererID);
		glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
		glBufferData(GL_ARRAY_BUFFER, aSize, aVertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &mRendererID);
	}
	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
	}
	void OpenGLVertexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t * aIndices, uint32_t aSize) : mRendererID(0), mCount(0)
	{
		glCreateBuffers(1, &mRendererID);
		glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
		glBufferData(GL_ARRAY_BUFFER, aSize, aIndices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
		glDeleteBuffers(1, &mRendererID);
	}
	void OpenGLIndexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
	}
	void OpenGLIndexBuffer::Unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}
