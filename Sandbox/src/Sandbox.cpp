#include <Engine.h>

class Sandbox : public Engine::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

const std::unique_ptr<Engine::Application>& Engine::CreateApplication()
{
	return Sandbox::GetInstance();
}