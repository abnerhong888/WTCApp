#ifndef __gtkaaIStack_H__
#define __gtkaaIStack_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IStack: public IWidget{
INHERIT_FROM(IStack, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_stack_new());
    }
    virtual void add_named(IWidget* widget, std::string name){
        gtk_stack_add_named(GTK_STACK(get()), GTK_WIDGET(widget->get()), name.c_str());
    }
    virtual void set_visable_child(std::string name){
        gtk_stack_set_visible_child_name(GTK_STACK(get()), name.c_str());
    }
    virtual void set_transition_type(GtkStackTransitionType transition){
        gtk_stack_set_transition_type(GTK_STACK(get()), transition);
    }
    virtual GtkStackTransitionType get_transition_type(){
        return gtk_stack_get_transition_type(GTK_STACK(get()));
    }
    virtual void set_transition_duration(guint duration){
        gtk_stack_set_transition_duration(GTK_STACK(get()), duration);
    }
    virtual guint get_transition_duration(){
        return gtk_stack_get_transition_duration(GTK_STACK(get()));
    }
    virtual void set_homogeneous(gboolean homogeneous){
        gtk_stack_set_hhomogeneous(GTK_STACK(get()), homogeneous);
    }
    virtual gboolean get_homogeneous(){
        return gtk_stack_get_hhomogeneous(GTK_STACK(get()));
    }
    virtual void set_vhomogeneous(gboolean vhomogeneous){
        gtk_stack_set_vhomogeneous(GTK_STACK(get()), vhomogeneous);
    }
    virtual gboolean get_vhomogeneous(){
        return gtk_stack_get_vhomogeneous(GTK_STACK(get()));
    }
};

}

#endif