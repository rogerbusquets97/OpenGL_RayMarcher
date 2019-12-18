#pragma once
#include <Log/Log.h>

namespace Engine
{
	enum class eShaderDataType
	{
		None = 0, Float, Vec2, Vec3, Vec4, Mat3, Mat4, Int, IVec2, IVec3, IVec4, Bool
	};

	static uint32_t Sizeof_ShaderDataType(eShaderDataType aType)
	{
		switch (aType)
		{
		case eShaderDataType::Float: return sizeof(float);
		case eShaderDataType::Vec2: return sizeof(float) * 2;
		case eShaderDataType::Vec3: return sizeof(float) * 3;
		case eShaderDataType::Vec4: return sizeof(float) * 4;
		case eShaderDataType::Mat3: return sizeof(float) * 3 * 3;
		case eShaderDataType::Mat4: return sizeof(float) * 4 * 4;
		case eShaderDataType::Int: return sizeof(int);
		case eShaderDataType::IVec2: return sizeof(int) * 2;
		case eShaderDataType::IVec3: return sizeof(int) * 3;
		case eShaderDataType::IVec4: return sizeof(int) * 4;
		case eShaderDataType::Bool: return sizeof(bool);
		}

		ENGINE_CORE_ERROR("Unknown shader data type");
		return 0;
	}

	struct sArrayAttribute
	{
		std::string Name;
		eShaderDataType Type;
		uint32_t Size;
		size_t Offset;

		sArrayAttribute() = default;
		sArrayAttribute(eShaderDataType aType, const std::string& aName) : Name(aName), Type(aType), Size(Sizeof_ShaderDataType(aType)), Offset(0)
		{
		}

		uint32_t GetCount() const
		{
			switch (Type)
			{
			case eShaderDataType::Bool: return 1;
			case eShaderDataType::Int: return 1;
			case eShaderDataType::Float: return 1;
			case eShaderDataType::Vec2: return 2;
			case eShaderDataType::Vec3: return 3;
			case eShaderDataType::Vec4: return 4;
			case eShaderDataType::IVec2: return 2;
			case eShaderDataType::IVec3: return 3;
			case eShaderDataType::IVec4: return 4;
			case eShaderDataType::Mat3: return 3 * 3;
			case eShaderDataType::Mat4: return 4 * 4;
			}

			ENGINE_CORE_ERROR("Unknown shader data type");
			return 0;
		}
	};

	class AttributeArray
	{
	public:
		AttributeArray() : mAttributes(), mStride(0U) {}
		AttributeArray(const std::initializer_list<sArrayAttribute>& aAttributes) : mAttributes(aAttributes), mStride(0U)
		{
			CalculateStride();
		}

		inline uint32_t GetStride() const { return mStride; }
		inline const std::vector<sArrayAttribute>& GetArray() const { return mAttributes; }

		std::vector<sArrayAttribute>::iterator begin() { return mAttributes.begin(); }
		std::vector<sArrayAttribute>::iterator end() { return mAttributes.end(); }
		std::vector<sArrayAttribute>::const_iterator begin() const { return mAttributes.begin(); }
		std::vector<sArrayAttribute>::const_iterator end() const { return mAttributes.end(); }

	private:

		void CalculateStride()
		{
			size_t offset = 0;
			mStride = 0;

			for (auto& Attribute : mAttributes)
			{
				Attribute.Offset = offset;
				offset += Attribute.Size;
				mStride += Attribute.Size;
			}
		}

		std::vector<sArrayAttribute> mAttributes;
		uint32_t mStride;
	};


}

