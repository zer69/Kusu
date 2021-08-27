#pragma once

#ifdef KS_PLATFORM_WINDOWS

extern Kusu::Application* Kusu::CreateApplication();

int main(int argc, char** argv)
{
	Kusu::Log::Init();
	KS_CORE_INFO("Log initialization: success!");
	auto app = Kusu::CreateApplication();
	app->Run();
	delete app;
}

#endif