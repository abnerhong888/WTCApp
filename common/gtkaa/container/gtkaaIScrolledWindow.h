#ifndef __gtkaaIScrolledWindow_H__
#define __gtkaaIScrolledWindow_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IScrolledWindow: public IWidget{
INHERIT_FROM_IWIDGET(IScrolledWindow)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_scrolled_window_new());
    }
    virtual void set_policy(GtkPolicyType hscrollbar_policy, GtkPolicyType vscrollbar_policy){
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(get()), hscrollbar_policy, vscrollbar_policy);
    }
    virtual void get_policy(GtkPolicyType *hscrollbar_policy, GtkPolicyType *vscrollbar_policy){
        gtk_scrolled_window_get_policy(GTK_SCROLLED_WINDOW(get()), hscrollbar_policy, vscrollbar_policy);
    }
    virtual void set_hadjustment(GtkAdjustment *adjustment){
        gtk_scrolled_window_set_hadjustment(GTK_SCROLLED_WINDOW(get()), adjustment);
    }
    virtual void set_vadjustment(GtkAdjustment *adjustment){
        gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(get()), adjustment);
    }
    virtual GtkAdjustment *get_hadjustment(){
        return gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(get()));
    }
    virtual GtkAdjustment *get_vadjustment(){
        return gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_placement(GtkCornerType placement){
        gtk_scrolled_window_set_placement(GTK_SCROLLED_WINDOW(get()), placement);
    }
    virtual void unset_placement(){
        gtk_scrolled_window_unset_placement(GTK_SCROLLED_WINDOW(get()));
    }
    virtual GtkCornerType get_placement(){
        return gtk_scrolled_window_get_placement(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_has_frame(gboolean has_frame){
        gtk_scrolled_window_set_has_frame(GTK_SCROLLED_WINDOW(get()), has_frame);
    }
    virtual gboolean get_has_frame(){
        return gtk_scrolled_window_get_has_frame(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_min_content_width(int width){
        gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(get()), width);
    }
    virtual int get_min_content_width(){
        return gtk_scrolled_window_get_min_content_width(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_min_content_height(int height){
        gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(get()), height);
    }
    virtual int get_min_content_height(){
        return gtk_scrolled_window_get_min_content_height(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_kinetic_scrolling(gboolean kinetic_scrolling){
        gtk_scrolled_window_set_kinetic_scrolling(GTK_SCROLLED_WINDOW(get()), kinetic_scrolling);
    }
    virtual gboolean get_kinetic_scrolling(){
        return gtk_scrolled_window_get_kinetic_scrolling(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_overlay_scrolling(gboolean overlay_scrolling){
        gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(get()), overlay_scrolling);
    }
    virtual gboolean get_overlay_scrolling(){
        return gtk_scrolled_window_get_overlay_scrolling(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_max_content_width(int width){
        gtk_scrolled_window_set_max_content_width(GTK_SCROLLED_WINDOW(get()), width);
    }
    virtual int get_max_content_width(){
        return gtk_scrolled_window_get_max_content_width(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_max_content_height(int height){
        gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(get()), height);
    }
    virtual int get_max_content_height(){
        return gtk_scrolled_window_get_max_content_height(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_propagate_natural_width(gboolean propagate){
        gtk_scrolled_window_set_propagate_natural_width(GTK_SCROLLED_WINDOW(get()), propagate);
    }
    virtual gboolean get_propagate_natural_width(){
        return gtk_scrolled_window_get_propagate_natural_width(GTK_SCROLLED_WINDOW(get()));
    }
    virtual void set_propagate_natural_height(gboolean propagate){
        gtk_scrolled_window_set_propagate_natural_height(GTK_SCROLLED_WINDOW(get()), propagate);
    }
    virtual gboolean get_propagate_natural_height(){
        return gtk_scrolled_window_get_propagate_natural_height(GTK_SCROLLED_WINDOW(get()));
    }

};

}

#endif