#pragma once

#ifdef FOXGINE_PLATFORM_WINDOWS

	#ifdef FOXGINE_BUILD_DLL

		#define FOXGINE_API __declspec(dllexport)

	#else

		#define FOXGINE_API __declspec(dllimport)

	#endif

#else

	#error Foxgine only supports Windows!

#endif
