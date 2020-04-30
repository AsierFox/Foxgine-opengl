#pragma once

#include "Event.h"

namespace Foxgine
{
	class FOXGINE_API MouseMovedEvent : public Event
	{
		float m_X;
		float m_Y;

	public:

		MouseMovedEvent(float x, float y) : m_X(x), m_Y(y) {}

		static EventType GetStaticType() { return EventType::MouseMoved; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		virtual int GetCategoryFlags() const override { return EventCategory::Input | EventCategory::Mouse; }

		std::string ToString() const override { return "[MouseMovedEvent::ToString] x: " + std::to_string(m_X) + ", y: " + std::to_string(m_Y); }

		inline float GetX() const { return m_X; }
		inline float GetY() const { return m_Y; }
	};

	class FOXGINE_API MouseScrolledEvent : public Event
	{
		float m_OffsetX;
		float m_OffsetY;

	public:

		MouseScrolledEvent(float offsetX, float offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		static EventType GetStaticType() { return EventType::MouseScrolled; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		virtual int GetCategoryFlags() const override { return EventCategory::Input | EventCategory::Mouse; }

		std::string ToString() const override { return "[MouseScrolledEvent::ToString] offsetX: " + std::to_string(m_OffsetX) + ", offsetY: " + std::to_string(m_OffsetY); }

		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }
	};

	class FOXGINE_API MouseButtonEvent : public Event
	{
	protected:

		int m_ButtonCode;

		MouseButtonEvent(int buttonCode) : m_ButtonCode(buttonCode) {}

	public:

		virtual int GetCategoryFlags() const override { return EventCategory::Input | EventCategory::Mouse; }

		inline int GetButtonCode() const { return m_ButtonCode; }
	};

	class FOXGINE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	protected:

		MouseButtonPressedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {}

	public:

		static EventType GetStaticType() { return EventType::MouseButtonPressed; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		std::string ToString() const override { return "[MouseButtonPressedEvent::ToString] buttonCode: " + std::to_string(m_ButtonCode); }
	};

	class FOXGINE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	protected:

		MouseButtonReleasedEvent(int buttonCode) : MouseButtonEvent(buttonCode) {}

	public:

		static EventType GetStaticType() { return EventType::MouseButtonReleased; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		std::string ToString() const override { return "[MouseButtonReleasedEvent::ToString] buttonCode: " + std::to_string(m_ButtonCode); }
	};
}
