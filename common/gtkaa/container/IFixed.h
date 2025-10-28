#ifndef __IFIXED_H__
#define __IFIXED_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h>

namespace GTKAA_NAMESPACE{

class IFixed: public IWidget{

public:
    virtual ~IFixed() = default;
    IFixed(){}
    IFixed(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_fixed_new());
    }

    void fix_put(IWidget* widget, double x, double y){
        gtk_fixed_put(GTK_FIXED(get()), GTK_WIDGET(widget->get()), x, y);
    }
};

}

#endif