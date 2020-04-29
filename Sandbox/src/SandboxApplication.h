#pragma once

#include <Foxgine.h>

class SandboxApplication : public Foxgine::Application
{
public:

	SandboxApplication();
	~SandboxApplication();
};

Foxgine::Application* Foxgine::CreateApplication();
