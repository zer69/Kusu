#pragma once

#ifdef KS_PLATFORM_WINDOWS

extern Kusu::Application* Kusu::CreateApplication();

int main(int argc, char** argv)
{
	Kusu::Log::Init();
	KS_CORE_WARN("Log initialization: success!");
	int a = 69;
	KS_INFO("Lmao var = {0}", a);
	auto app = Kusu::CreateApplication();
	app->Run();
	delete app;
}

#endif