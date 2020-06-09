#include "OpenGLVertexArray.h"
#include <glad/glad.h>
#include <Log/Log.h>

namespace rubEngine
{
	static GLenum ToGLType(eShaderDataType aType)
	{
		switch (aType)
		{
		case eShaderDataType::Bool: return GL_BOOL;
		case eShaderDataType::Float: return GL_FLOAT;
		case eShaderDataType::Vec2: return GL_FLOAT;
		case eShaderDataType::Vec3: return GL_FLOAT;
		case eShaderDataType::Vec4: return GL_FLOAT;
		case eShaderDataType::Mat3: return GL_FLOAT;
		case eShaderDataType::Mat4: return GL_FLOAT;
		case eShaderDataType::Int: return GL_INT;
		case eShaderDataType::IVec2: return GL_INT;
		case eShaderDataType::IVec3: return GL_INT;
		case eShaderDataType::IVec4: return GL_INT;
		}

		ENGINE_CORE_ERROR("ToGLType: Unknown Shader data type");
		return 0;
	}
	rubEngine::OpenGLVertexArray::OpenGLVertexArray() : mRendererID(0), mCurrentVertexIndex(0), mVertexBuffers(), mIndexBuffer()
	{
		glCreateVertexArrays(1, &mRendererID);
	}
	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &mRendererID);
	}
	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(mRendererID);
	}
	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}
	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& aBuffer)
	{
		Bind();
		aBuffer->Bind();
		const auto& AttribArray = aBuffer->GetAttributeArray();
		for (const auto& Attribute : AttribArray)
		{
			glEnableVertexAttribArray(mCurrentVertexIndex);
			glVertexAttribPointer(mCurrentVertexIndex, Attribute.GetCount(), ToGLType(Attribute.Type), GL_FALSE, AttribArray.GetStride(), (const void*)Attribute.Offset);
			mCurrentVertexIndex++;
		}

		mVertexBuffers.push_back(aBuffer);
	}
	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& aBuffer)
	{
		Bind();
		aBuffer->Bind();
		mIndexBuffer = aBuffer;
	}
}