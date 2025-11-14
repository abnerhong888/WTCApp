#ifndef __gtkaaIRevealer_H__
#define __gtkaaIRevealer_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IRevealer: public IWidget{
INHERIT_FROM(IRevealer, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_revealer_new());
    }
    virtual void set_child(IWidget* widget){
        gtk_revealer_set_child(GTK_REVEALER(get()), GTK_WIDGET(widget->get()));
    }
    virtual void set_reveal_child(bool is_reveal){
        gtk_revealer_set_reveal_child(GTK_REVEALER(get()), is_reveal);
    }
    virtual IWidget get_child(){
        return {gtk_revealer_get_child(GTK_REVEALER(get()))};
    }
    virtual gboolean get_reveal_child(){
        return gtk_revealer_get_reveal_child(GTK_REVEALER(get()));
    }
    virtual guint get_transition_duration(){
        return gtk_revealer_get_transition_duration(GTK_REVEALER(get()));
    }
    virtual void set_transition_duration(guint duration){
        gtk_revealer_set_transition_duration(GTK_REVEALER(get()), duration);
    }
    virtual GtkRevealerTransitionType get_transition_type(){
        return gtk_revealer_get_transition_type(GTK_REVEALER(get()));
    }
    virtual void set_transition_type(GtkRevealerTransitionType transition){
        gtk_revealer_set_transition_type(GTK_REVEALER(get()), transition);
    }
    virtual gboolean get_child_revealed(){
        return gtk_revealer_get_child_revealed(GTK_REVEALER(get()));
    }
};

}

#endif