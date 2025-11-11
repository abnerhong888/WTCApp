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

struct EventData_lambda{
    std::function<void()> callback;
    std::string signal_name;
    gpointer user_data;

    EventData_lambda(std::string signal_name, std::function<void()> callback, gpointer user_data){
        this->callback = callback;
        this->signal_name = signal_name;
        this->user_data = user_data;
    }
};

template<typename T>
EventData<T> g_event(std::string signal_name, EventCallback<T> callback, gpointer user_data){
    return EventData<T>(signal_name, callback, user_data);
}

EventData_lambda g_event(std::string signal_name, std::function<void()> callback, gpointer user_data){
    return EventData_lambda(signal_name, callback, user_data);
}

static std::unordered_map<gpointer, std::function<void()>> g_event_map;

static void g_map_set(gpointer obj, std::function<void()> callback){
    g_event_map[obj] = callback;
}

static void g_event_callback(GObject *obj, gpointer user_data){
    if(g_event_map.count(obj)){
        g_event_map[obj]();
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
            g_map_set(event->get(), [data](){ 
                (reinterpret_cast<T*>(data.user_data)->*data.callback)();
            });
            g_signal_connect(event->get(), data.signal_name.c_str(), GCallback(g_event_callback), data.user_data);
        }
        
        void operator+= (EventData_lambda&& data){
            g_map_set(event->get(), [data](){ 
                data.callback();
            });
            g_signal_connect(event->get(), data.signal_name.c_str(), GCallback(g_event_callback), data.user_data);
        }
        
        template<typename T>
        void operator+= (EventData<T>& data){
            this->operator+= (std::move(data));
        }

        void operator+= (EventData_lambda& data){
            this->operator+= (std::move(data));
        }
    };
public:
    // How to use: event += gtkaa::g_event("signal_name", &class::callback, user_data);
    EventHandler event{this};
public:
    virtual ~IEvent() = default;
    virtual gpointer get() = 0;
};

}
#endif