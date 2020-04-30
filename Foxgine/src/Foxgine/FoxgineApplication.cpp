#include "FoxgineApplication.h"

Foxgine::FoxgineApplication::FoxgineApplication()
{
}

Foxgine::FoxgineApplication::~FoxgineApplication()
{
}

void Foxgine::FoxgineApplication::Run()
{
	WindowResizeEvent e(1280, 720);

	if (e.IsInCategory(EventCategory::Keyboard))
	{
		FOXGINE_LOGGER_TRACE(e.ToString());
	}

	int a;
}
