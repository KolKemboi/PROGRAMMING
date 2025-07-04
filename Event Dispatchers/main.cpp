#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>

enum class EventType
{
    MouseMoved,
    MouseButtonPressed,
    KeyPressed,
    CustomEvent,
};

struct Event
{
    EventType type;
};

struct MouseEvent: public Event
{
    double x;
    double y;
    int button;

    MouseEvent(EventType type, double x, double y, int button) :
    x(x), y(y), button(button)
    {
        this->type = type;
    }
};

struct KeyboardEvent : public Event
{
    int key;
    int mods;

    KeyboardEvent(EventType type, int key, int mods) :
    key(key), mods(mods)
    {
        this->type = type;
    }
};


struct CustomEvent : public Event
{
    std::string message;

    CustomEvent(const std::string& msg) :
    message(msg)
    {
        this->type = EventType::CustomEvent;
    }
};


class EventDispatcher
{
public:
    using EventCallback = std::function<void(const Event&)>;

    void Subscribe(EventType type, EventCallback callback)
    {
        listeners[type].push_back(callback);
    }

    void Dispatch(const Event& event)
    {
        auto it = listeners.find(event.type);

        if (it != listeners.end())
        {
            for (const auto& callback: it->second)
            {
                callback(event);
            }
        }
    }

    void Unsubscribe(EventType type, EventCallback callback)
    {
        auto it = listeners.find(type);
        
    }


private:
    std::unordered_map<EventType, std::vector<EventCallback>> listeners;
};

