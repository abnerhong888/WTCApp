#ifndef __gtkaaIFixed_H__
#define __gtkaaIFixed_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFixed: public IWidget{
INHERIT_FROM(IFixed, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_fixed_new());
    }

    virtual void fix_put(IWidget* widget, double x, double y){
        gtk_fixed_put(GTK_FIXED(get()), GTK_WIDGET(widget->get()), x, y);
    }
    virtual void fix_remove(IWidget* widget){
        gtk_fixed_remove(GTK_FIXED(get()), GTK_WIDGET(widget->get()));
    }
    virtual void fix_move(IWidget* widget, double x, double y){
        gtk_fixed_move(GTK_FIXED(get()), GTK_WIDGET(widget->get()), x, y);
    }
    virtual void fix_get_child_position(IWidget* widget, double* x, double* y){
        gtk_fixed_get_child_position(GTK_FIXED(get()), GTK_WIDGET(widget->get()), x, y);
    }
    virtual void fix_set_child_transform(IWidget* widget, GskTransform* transform){
        gtk_fixed_set_child_transform(GTK_FIXED(get()), GTK_WIDGET(widget->get()), transform);
    }
    virtual GskTransform* fix_get_child_transform(IWidget* widget){
        return gtk_fixed_get_child_transform(GTK_FIXED(get()), GTK_WIDGET(widget->get()));
    }
};

}

#endif