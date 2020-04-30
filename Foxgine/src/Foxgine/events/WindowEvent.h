#pragma once

#include "Event.h"

namespace Foxgine
{
	class WindowResizeEvent : public Event
	{
		unsigned int m_Width;
		unsigned int m_Height;

	public:

		WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		virtual int GetCategoryFlags() const override { return EventCategory::Application; }

		std::string ToString() const override { return "[WindowResizeEvent::ToString] width: " + std::to_string(GetWidth()) + ", height: " + std::to_string(GetHeight()); }

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }
	};
}
