#pragma once

#ifdef FOXGINE_PLATFORM_WINDOWS

extern Foxgine::FoxgineApplication* Foxgine::CreateApplication();

int main(int argc, char** argv)
{
	Foxgine::Logger::Init();
	
	Foxgine::FoxgineApplication* app = Foxgine::CreateApplication();

	app->Run();

	delete app;

	return 0;
}

#endif
