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

		void System::AddEntity(std::shared_ptr<Entity> apEntity)
		{
			mEntities.push_back(apEntity);
		}

		void System::RemoveEntity(std::shared_ptr<Entity> apEntity)
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