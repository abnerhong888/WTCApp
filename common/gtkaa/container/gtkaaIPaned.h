#ifndef __gtkaaIPaned_H__
#define __gtkaaIPaned_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPaned: public IWidget{

public:
    virtual ~IPaned() = default;
    IPaned(){}
    IPaned(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation){
        return createWidget(gtk_paned_new(orientation));
    }
    void set_start_child(IWidget* widget){
        gtk_paned_set_start_child(GTK_PANED(get()), GTK_WIDGET(widget->get()));
    }
    void set_end_child(IWidget* widget){
        gtk_paned_set_end_child(GTK_PANED(get()), GTK_WIDGET(widget->get()));
    }
    void set_position(int position){
        gtk_paned_set_position(GTK_PANED(get()), position);
    }
};

}

#endif
