#ifndef __gtkaaIStack_H__
#define __gtkaaIStack_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IStack: public IWidget{
INHERIT_FROM_IWIDGET(IStack)
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
};

}

#endif