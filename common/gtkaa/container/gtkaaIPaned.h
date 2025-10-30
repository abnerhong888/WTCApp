#ifndef __gtkaaIPaned_H__
#define __gtkaaIPaned_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPaned: public IWidget{
INHERIT_FROM_IWIDGET(IPaned)
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation){
        return createWidget(gtk_paned_new(orientation));
    }
    virtual void set_start_child(IWidget* widget){
        gtk_paned_set_start_child(GTK_PANED(get()), GTK_WIDGET(widget->get()));
    }
    virtual void set_end_child(IWidget* widget){
        gtk_paned_set_end_child(GTK_PANED(get()), GTK_WIDGET(widget->get()));
    }
    virtual void set_position(int position){
        gtk_paned_set_position(GTK_PANED(get()), position);
    }
    virtual void set_wide_handle(gboolean wide){
        gtk_paned_set_wide_handle(GTK_PANED(get()), wide);
    }
    virtual void set_resize_start_child(gboolean resize){
        gtk_paned_set_resize_start_child(GTK_PANED(get()), resize);
    }
    virtual void set_resize_end_child(gboolean resize){
        gtk_paned_set_resize_end_child(GTK_PANED(get()), resize);
    }
    virtual void set_shrink_start_child(gboolean shrink){
        gtk_paned_set_shrink_start_child(GTK_PANED(get()), shrink);
    }
    virtual void set_shrink_end_child(gboolean shrink){
        gtk_paned_set_shrink_end_child(GTK_PANED(get()), shrink);
    }
    virtual IWidget get_start_child(){
        return {gtk_paned_get_start_child(GTK_PANED(get()))};
    }
    virtual IWidget get_end_child(){
        return {gtk_paned_get_end_child(GTK_PANED(get()))};
    }
    virtual int get_position(){
        return gtk_paned_get_position(GTK_PANED(get()));
    }
    virtual gboolean get_wide_handle(){
        return gtk_paned_get_wide_handle(GTK_PANED(get()));
    }
    virtual gboolean get_resize_start_child(){
        return gtk_paned_get_resize_start_child(GTK_PANED(get()));
    }
    virtual gboolean get_resize_end_child(){
        return gtk_paned_get_resize_end_child(GTK_PANED(get()));
    }
    virtual gboolean get_shrink_start_child(){
        return gtk_paned_get_shrink_start_child(GTK_PANED(get()));
    }
    virtual gboolean get_shrink_end_child(){
        return gtk_paned_get_shrink_end_child(GTK_PANED(get()));
    }
    
};

}

#endif
