#pragma once

#ifdef FOXGINE_PLATFORM_WINDOWS

extern Foxgine::Application* Foxgine::CreateApplication();

int main(int argc, char** argv)
{
	Foxgine::Logger::Init();
	
	Foxgine::Application* app = Foxgine::CreateApplication();

	app->Run();

	delete app;

	return 0;
}

#endif
