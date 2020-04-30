#pragma once

#include "Event.h"

namespace Foxgine
{
	class FOXGINE_API KeyEvent : public Event
	{
	protected:
		int m_KeyCode;

		KeyEvent(int keyCode) : m_KeyCode(keyCode) {}

	public:

		virtual EventType GetEventType() const = 0;
		virtual std::string ToString() const = 0;

		virtual int GetCategoryFlags() const override { return EventCategory::Input | EventCategory::Keyboard; }

		inline int GetKeyCode() const { return m_KeyCode; }
	};

	class FOXGINE_API KeyPressedEvent : public KeyEvent
	{
		int m_RepeatedCount;

	public:

		KeyPressedEvent(int keyCode, int repeatedCount) : KeyEvent(keyCode), m_RepeatedCount(repeatedCount) {}

		static EventType GetStaticType() { return EventType::KeyPressed; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		std::string ToString() const override { return "[KeyPressedEvent::ToString] KeyCode: " + std::to_string(m_KeyCode) + ", repeatedCound: " + std::to_string(m_RepeatedCount); }

		inline int GetRepeatedCount() const { return m_RepeatedCount; }
	};

	class FOXGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keyCode) : KeyEvent(keyCode) {}

		static EventType GetStaticType() { return EventType::KeyReleased; }

		virtual EventType GetEventType() const override { return GetStaticType(); }

		std::string ToString() const override { return "[KeyReleasedEvent::ToString] KeyCode: " + std::to_string(m_KeyCode); }
	};
}
