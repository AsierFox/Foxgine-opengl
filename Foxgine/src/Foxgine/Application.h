#pragma once

#include "Core.h"

namespace Foxgine
{
	class FOXGINE_API Application
	{
	public:
		
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}
