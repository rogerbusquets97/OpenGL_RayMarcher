#pragma once
#include <Core.h>

namespace Engine
{
	class ENGINE_API Texture
	{
	public:
		virtual ~Texture() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void SetData(void* aData, uint32_t aSize) = 0;
		virtual void Bind(uint32_t aSlot = 0) const = 0;
	};

	class ENGINE_API RenderTexture
	{
	public:
		virtual ~RenderTexture() = default;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual void Bind(uint32_t aSlot = 0) const = 0;
	};

	class Texture2D : public Texture
	{
		static std::shared_ptr<Texture2D> Create(uint32_t aWidth, uint32_t aHeight);
		//static std::shared_ptr<Texture2D> Create(const std::string& aPath);
	};

	class RenderTexture2D : public RenderTexture
	{
		static std::shared_ptr<RenderTexture2D> Create(uint32_t aWidth, uint32_t aHeight);
	};
}
