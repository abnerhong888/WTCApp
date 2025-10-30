#ifndef __gtkaaIOverlay_H__
#define __gtkaaIOverlay_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IOverlay: public IWidget{
INHERIT_FROM_IWIDGET(IOverlay)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_overlay_new());
    }
    
    void set_child(IWidget* widget){
        gtk_overlay_set_child(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()));
    }
    
    void add_overlay(IWidget* widget){
        gtk_overlay_add_overlay(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()));
    }
};

}

#endif