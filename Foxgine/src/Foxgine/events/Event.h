#pragma once

#include <string>

#include "Foxgine/Core.h"

namespace Foxgine
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		Application = BIT(0),
		Input       = BIT(1),
		Keyboard    = BIT(2),
		Mouse       = BIT(3),
		MouseButton = BIT(4)
	};

	class FOXGINE_API Event
	{
		friend class EventDispatcher;

	protected:

		bool m_Handled = false;

	public:

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const = 0;

		inline bool IsInCategory(EventCategory category) { return GetCategoryFlags() & category; }
	};

	class EventDispatcher
	{
		Event& m_Event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		EventDispatcher(Event& event) : m_Event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}
			return false;
		}
	};

}
