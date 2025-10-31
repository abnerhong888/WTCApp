#ifndef __gtkaaIEvent_H__
#define __gtkaaIEvent_H__

#include <gtkaa/base/gtkaaICommon.h>

namespace GTKAA_NAMESPACE{

template<typename T>
using EventCallback = void(T::*)();

template<typename T>
struct EventData{
    EventCallback<T> callback;
    std::string signal_name;
    gpointer user_data;

    EventData(std::string signal_name, EventCallback<T> callback, gpointer user_data){
        this->callback = callback;
        this->signal_name = signal_name;
        this->user_data = user_data;
    }
};

template<typename T>
EventData<T> signal(std::string signal_name, EventCallback<T> callback, gpointer user_data){
    return EventData<T>(signal_name, callback, user_data);
}

std::unordered_map<gpointer, std::function<void()>> event_callbacks;

void connect(gpointer user_data, std::function<void()> func){
    event_callbacks[user_data] = func;
}
static void global_event_callback(GObject *obj, gpointer user_data){
    if(event_callbacks.count(obj)){
        event_callbacks[obj]();
    }
}

class IEvent{
public:
    class EventHandler{
    public:
        IEvent* event;
        EventHandler(IEvent* event){
            this->event = event;
        }
        ~EventHandler() = default;

        template<typename T>
        void operator+= (EventData<T>&& data){
            connect(event->get(), [data](){ (reinterpret_cast<T*>(data.user_data)->*data.callback)(); });
            g_signal_connect(event->get(), data.signal_name.c_str(), GCallback(global_event_callback), data.user_data);
        }
        
        template<typename T>
        void operator+= (EventData<T>& data){
            this->operator+= (std::move(data));
        }
    };
public:
    // How to use: event_handler += {"signal_name", callback, user_data};
    EventHandler event_handler{this};
public:
    virtual ~IEvent() = default;
    virtual gpointer get() = 0;
};

}
#endif