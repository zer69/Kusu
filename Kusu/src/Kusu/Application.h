#pragma once

#include "Core.h"

namespace Kusu
{
	class KUSU_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();
}