#include "SandboxApplication.h"

SandboxApplication::SandboxApplication()
{
}

SandboxApplication::~SandboxApplication()
{
}

Foxgine::Application* Foxgine::CreateApplication()
{
	return new SandboxApplication;
}
