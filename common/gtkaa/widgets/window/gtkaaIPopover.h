#ifndef __gtkaaIPopover_H__
#define __gtkaaIPopover_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPopover: public IWidget{
INHERIT_FROM(IPopover, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_popover_new());
    }
    virtual void set_child(IWidget* child){
        gtk_popover_set_child(GTK_POPOVER(get()), GTK_WIDGET(child->get()));
    }
    virtual IWidget get_child(){
        return { GTK_WIDGET( gtk_popover_get_child(GTK_POPOVER(get())))};
    }
    virtual void set_pointing_to(const GdkRectangle* rect){
        gtk_popover_set_pointing_to(GTK_POPOVER(get()), rect);
    }
    virtual GdkRectangle get_pointing_to(){
        GdkRectangle rect;
        gtk_popover_get_pointing_to(GTK_POPOVER(get()), &rect);
        return rect;
    }
    virtual void set_position(GtkPositionType position){
        gtk_popover_set_position(GTK_POPOVER(get()), position);
    }
    virtual GtkPositionType get_position(){
        return gtk_popover_get_position(GTK_POPOVER(get()));
    }
    virtual void set_autohide(gboolean autohide){
        gtk_popover_set_autohide(GTK_POPOVER(get()), autohide);
    }
    virtual gboolean get_autohide(){
        return gtk_popover_get_autohide(GTK_POPOVER(get()));
    }
    virtual void set_has_arrow(gboolean has_arrow){
        gtk_popover_set_has_arrow(GTK_POPOVER(get()), has_arrow);
    }
    virtual gboolean get_has_arrow(){
        return gtk_popover_get_has_arrow(GTK_POPOVER(get()));
    }
    virtual void set_mnemonics_visible(gboolean mnemonics_visible){
        gtk_popover_set_mnemonics_visible(GTK_POPOVER(get()), mnemonics_visible);
    }
    virtual gboolean get_mnemonics_visible(){
        return gtk_popover_get_mnemonics_visible(GTK_POPOVER(get()));
    }
    virtual void popup(){
        gtk_popover_popup(GTK_POPOVER(get()));
    }
    virtual void popdown(){
        gtk_popover_popdown(GTK_POPOVER(get()));
    }
    virtual void set_offset(int x_offset, int y_offset){
        gtk_popover_set_offset(GTK_POPOVER(get()), x_offset, y_offset);
    }
    virtual void get_offset(int* x_offset, int* y_offset){
        gtk_popover_get_offset(GTK_POPOVER(get()), x_offset, y_offset);
    }
    virtual void set_cascade_popdown(gboolean cascade_popdown){
        gtk_popover_set_cascade_popdown(GTK_POPOVER(get()), cascade_popdown);
    }
    virtual gboolean get_cascade_popdown(){
        return gtk_popover_get_cascade_popdown(GTK_POPOVER(get()));
    }
    virtual void set_default_widget(IWidget* widget){
        gtk_popover_set_default_widget(GTK_POPOVER(get()), GTK_WIDGET(widget->get()));
    }
    virtual void present(){
        gtk_popover_present(GTK_POPOVER(get()));
    }
};

}

#endif