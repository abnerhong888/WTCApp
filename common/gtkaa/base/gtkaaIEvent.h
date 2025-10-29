#ifndef __gtkaaIEVENT_H__
#define __gtkaaIEVENT_H__

#include <gtkaa/base/gtkaaICommon.h>

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

        void operator+= (EventData&& data){
            g_signal_connect(event->get(), data.signal_name.c_str(), GCallback(data.callback), data.user_data);
        }
        void operator+= (EventData& data){
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