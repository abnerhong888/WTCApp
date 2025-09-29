#ifndef __IBASE_H__
#define __IBASE_H__

#include "ICommon.h"
#include <string>

namespace GTKAA_NAMESPACE{

class IEvent{
public:
    class EventHandler{
    public:
        IEvent* event;
        EventHandler(IEvent* event){
            this->event = event;
        }
        ~EventHandler() = default;
        
        void operator+= (EventData data){
            event->add_signal_callback(data);
        }
    };
public:
    EventHandler event_handler{this};
public:
    virtual ~IEvent() = default;
    virtual gpointer get() = 0;
    // void signal_conn(EventCallback callback, gpointer user_data){
    //     if(g_signal_callbacks.count(callback)){
    //         std::string signal_name = g_signal_callbacks[callback];
    //         g_signal_connect(get(), signal_name.c_str(), GCallback(callback), user_data);
    //     }
    // }

    void add_signal_callback(EventData data){
        g_signal_connect(get(), data.signal_name.c_str(), GCallback(data.callback), data.user_data);
    }
};

}
#endif