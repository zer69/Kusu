#include <Kusu.h>

class Sandbox : public Kusu::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Kusu::Application* Kusu::CreateApplication()
{
	return new Sandbox();
}