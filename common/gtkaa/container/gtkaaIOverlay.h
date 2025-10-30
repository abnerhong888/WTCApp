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
    virtual void set_child(IWidget* widget){
        gtk_overlay_set_child(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()));
    }
    virtual void add_overlay(IWidget* widget){
        gtk_overlay_add_overlay(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()));
    }   
    virtual void remove_overlay(IWidget* widget){
        gtk_overlay_remove_overlay(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()));
    }    
    virtual void set_measure_overlay(IWidget* widget, gboolean measure){
        gtk_overlay_set_measure_overlay(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()), measure);
    }
    virtual void set_clip_overlay(IWidget* widget, gboolean clip){
        gtk_overlay_set_clip_overlay(GTK_OVERLAY(get()), GTK_WIDGET(widget->get()), clip);
    }
    
};

}

#endif