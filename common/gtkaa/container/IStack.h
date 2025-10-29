#ifndef __ISTACK_H__
#define __ISTACK_H__

#include <gtkaa/base/IBase.h>

namespace GTKAA_NAMESPACE{

class IStack: public IWidget{

public:
    virtual ~IStack() = default;
    IStack(){}
    IStack(std::string widgetName): IWidget(widgetName){}
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