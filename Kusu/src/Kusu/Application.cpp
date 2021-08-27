#include "kspch.h"
#include "Application.h"

#include "Kusu/Events/ApplicationEvent.h"
#include "Kusu/Log.h"

#include <GLFW/glfw3.h>

namespace Kusu 

{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.5, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}