#ifndef __gtkaaIBox_H__
#define __gtkaaIBox_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IBox: public IWidget{

public:
    virtual ~IBox() = default;
    IBox(){}
    IBox(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation, int spacing){
        return createWidget(gtk_box_new(orientation, spacing));
    }
    virtual void append(IWidget* widget){
        gtk_box_append(GTK_BOX(get()), GTK_WIDGET(widget->get()));
    }
};

}

#endif