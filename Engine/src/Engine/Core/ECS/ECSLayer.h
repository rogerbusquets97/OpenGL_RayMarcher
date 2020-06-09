#ifndef ENGINE_ECS_LAYER
#define ENGINE_ECS_LAYER

#include "Core.h"
#include "ECSManager.h"

namespace rubEngine
{
	namespace ECS
	{
		/**
		* Class to interact with the ECS system. Users should only use this class
		*/
		class ENGINE_API ECSLayer
		{
		public:
			ECSLayer();
			~ECSLayer();

			void Init();

			void PreUpdate(float aDeltaTime);
			void Update(float aDeltaTime);
			void PostUpdate(float aDeltaTime);

			//TODO functions that read from config files instead of hardcoding
			//...


		private:
			ECSManager		mECSManager;
		};
	}
}

#endif
