#include <Kusu.h>

class ExampleLayer : public Kusu::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		KS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Kusu::Event& event) override
	{
		KS_TRACE("{0}", event);
	}

};

class Sandbox : public Kusu::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Kusu::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Kusu::Application* Kusu::CreateApplication()
{
	return new Sandbox();
}