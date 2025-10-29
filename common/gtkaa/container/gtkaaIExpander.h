#ifndef __gtkaaIExpander_H__
#define __gtkaaIExpander_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IExpander: public IWidget{

public:
    virtual ~IExpander() = default;
    IExpander(){}
    IExpander(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(std::string label){
        return createWidget(gtk_expander_new(label.c_str()));
    }
    
    void set_child(IWidget* widget){
        gtk_expander_set_child(GTK_EXPANDER(get()), GTK_WIDGET(widget->get()));
    }
};

}

#endif