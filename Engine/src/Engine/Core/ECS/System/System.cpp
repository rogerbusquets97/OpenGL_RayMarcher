#include "System.h"

namespace Engine
{
	namespace ECS
	{
		System::System() :
			mEntities(),
			mECSManager(nullptr)
		{

		}

		System::~System()
		{

		}

		void System::AddEntity(Entity* apEntity)
		{
			mEntities.push_back(apEntity);
		}

		void System::RemoveEntity(Entity* apEntity)
		{
			for (auto EntityIterator = mEntities.begin(); EntityIterator != mEntities.end(); ++EntityIterator)
			{
				if (*EntityIterator == apEntity)
				{
					mEntities.erase(EntityIterator);
					break;
				}
			}
		}

		void System::SetComponentsMask(BitMask aComponentsMask)
		{
			mComponentsMask = aComponentsMask;
		}

		bool System::ComponentFits(tComponentFamilyId aComponentFamilyId) const
		{
			return mComponentsMask.GetPosition(aComponentFamilyId);
		}
	}
}