#include "kspch.h"
#include "Application.h"

#include "Kusu/Events/ApplicationEvent.h"
#include "Kusu/Log.h"

namespace Kusu 

{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
			KS_TRACE(e);
		if (e.IsInCategory(EventCategoryInput))
			KS_TRACE(e);
		while (true);
	}
}