#ifndef __gtkaaEventController_H__
#define __gtkaaEventController_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class EventController: public IEvent{
public:
    gtkaa::sptrGTKEventController m_event_controller = nullptr;
public:
    EventController(){
    }
    virtual ~EventController() = default;
    virtual gpointer get(){
        return m_event_controller.get();
    }

    virtual gtkaa::sptrGTKEventController create(){
        m_event_controller = gtkaa::make_ptr_unref(gtk_event_controller_motion_new());
        return m_event_controller;
    }
    virtual gboolean contains_pointer(){
        return gtk_event_controller_motion_contains_pointer(GTK_EVENT_CONTROLLER_MOTION(get()));
    }
    virtual gboolean is_pointer(){
        return gtk_event_controller_motion_is_pointer(GTK_EVENT_CONTROLLER_MOTION(get()));
    }
};

}

#endif