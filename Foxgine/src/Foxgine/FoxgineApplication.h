#pragma once

#include "Core.h"
#include "Logger.h"
#include "events/WindowEvent.h"

namespace Foxgine
{
	class FOXGINE_API FoxgineApplication
	{
	public:
		
		FoxgineApplication();
		virtual ~FoxgineApplication();

		void Run();
	};

	FoxgineApplication* CreateApplication();
}
