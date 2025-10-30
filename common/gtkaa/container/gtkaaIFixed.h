#ifndef __gtkaaIFixed_H__
#define __gtkaaIFixed_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFixed: public IWidget{
INHERIT_FROM_IWIDGET(IFixed)
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