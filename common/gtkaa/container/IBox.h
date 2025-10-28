#ifndef __IBOX_H__
#define __IBOX_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h>

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