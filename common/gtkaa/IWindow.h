#ifndef __IWINDOW_H__
#define __IWINDOW_H__

#include "ICommon.h"

namespace GTKAA_NAMESPACE{

class IWindow{
public:
    virtual ~IWindow() = default;
    virtual void activate(GObject *obj, gpointer user_data){}
    virtual void paned_position_changed(GObject *obj, gpointer user_data){ }
public:
    static void on_activate(GObject *obj, gpointer user_data){
        reinterpret_cast<IWindow*>(user_data)->activate(obj, user_data);
    }
    static void on_paned_position_changed(GObject *obj, gpointer user_data){
        printf("123 %d\n", user_data);
        // reinterpret_cast<IWindow*>(user_data)->paned_position_changed(obj, user_data);
    }
};

}

#endif