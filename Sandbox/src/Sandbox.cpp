#include <Engine.h>

class Sandbox : public rubEngine::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

const std::unique_ptr<rubEngine::Application>& rubEngine::CreateApplication()
{
	return Sandbox::GetInstance();
}