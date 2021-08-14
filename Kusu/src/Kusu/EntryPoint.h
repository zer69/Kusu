#pragma once

#ifdef KS_PLATFORM_WINDOWS

extern Kusu::Application* Kusu::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Kusu::CreateApplication();
	app->Run();
	delete app;
}

#endif