#ifndef __gtkaaIRevealer_H__
#define __gtkaaIRevealer_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IRevealer: public IWidget{

public:
    virtual ~IRevealer() = default;
    IRevealer(){}
    IRevealer(std::string widgetName): IWidget(widgetName){}
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
};

}

#endif