#ifndef __gtkaaIHeaderBar_H__
#define __gtkaaIHeaderBar_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IHeaderBar: public IWidget{
INHERIT_FROM_IWIDGET(IHeaderBar)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_header_bar_new());
    }
    virtual void set_title_widget(IWidget* title_widget){
        gtk_header_bar_set_title_widget(GTK_HEADER_BAR(get()), GTK_WIDGET(title_widget->get()));
    }
    virtual IWidget get_title_widget(){
        return { gtk_header_bar_get_title_widget(GTK_HEADER_BAR(get())) };
    }
    virtual void pack_start(IWidget* child){
        gtk_header_bar_pack_start(GTK_HEADER_BAR(get()), GTK_WIDGET(child->get()));
    }
    virtual void pack_end(IWidget* child){
        gtk_header_bar_pack_end(GTK_HEADER_BAR(get()), GTK_WIDGET(child->get()));
    }
    virtual void remove(IWidget* child){
        gtk_header_bar_remove(GTK_HEADER_BAR(get()), GTK_WIDGET(child->get()));
    }
    virtual gboolean get_show_title_buttons(){
        return gtk_header_bar_get_show_title_buttons(GTK_HEADER_BAR(get()));
    }
    virtual void set_show_title_buttons(gboolean setting){
        gtk_header_bar_set_show_title_buttons(GTK_HEADER_BAR(get()), setting);
    }
    virtual void set_decoration_layout(const char* layout){
        gtk_header_bar_set_decoration_layout(GTK_HEADER_BAR(get()), layout);
    }
    virtual const char* get_decoration_layout(){
        return gtk_header_bar_get_decoration_layout(GTK_HEADER_BAR(get()));
    }
};

}

#endif