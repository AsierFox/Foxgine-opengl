#include "SandboxApplication.h"

SandboxApplication::SandboxApplication()
{
}

SandboxApplication::~SandboxApplication()
{
}

Foxgine::FoxgineApplication* Foxgine::CreateApplication()
{
	return new SandboxApplication;
}
