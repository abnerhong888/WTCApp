#ifndef __gtkaaIMenuButton_H__
#define __gtkaaIMenuButton_H__

#include "gtkaa/widgets/window/gtkaaIPopover.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IMenuButton: public IWidget{
INHERIT_FROM(IMenuButton, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_menu_button_new());
    }
    virtual void set_popover(IWidget* popover){
        gtk_menu_button_set_popover(GTK_MENU_BUTTON(get()), GTK_WIDGET(popover->get()));
    }
    virtual IPopover get_popover(){
        return { GTK_WIDGET( gtk_menu_button_get_popover(GTK_MENU_BUTTON(get())))};
    }
    virtual void set_direction(GtkArrowType direction){
        gtk_menu_button_set_direction(GTK_MENU_BUTTON(get()), direction);
    }
    virtual GtkArrowType get_direction(){
        return gtk_menu_button_get_direction(GTK_MENU_BUTTON(get()));
    }
    virtual void set_menu_model(GMenuModel* menu_model){
        gtk_menu_button_set_menu_model(GTK_MENU_BUTTON(get()), menu_model);
    }
    virtual GMenuModel* get_menu_model(){
        return gtk_menu_button_get_menu_model(GTK_MENU_BUTTON(get()));
    }
    virtual void set_icon_name(const char* icon_name){
        gtk_menu_button_set_icon_name(GTK_MENU_BUTTON(get()), icon_name);
    }
    virtual const char* get_icon_name(){
        return gtk_menu_button_get_icon_name(GTK_MENU_BUTTON(get()));
    }
    virtual void set_always_show_arrow(gboolean always_show_arrow){
        gtk_menu_button_set_always_show_arrow(GTK_MENU_BUTTON(get()), always_show_arrow);
    }
    virtual gboolean get_always_show_arrow(){
        return gtk_menu_button_get_always_show_arrow(GTK_MENU_BUTTON(get()));
    }
    virtual void set_label(const char* label){
        gtk_menu_button_set_label(GTK_MENU_BUTTON(get()), label);
    }
    virtual const char* get_label(){
        return gtk_menu_button_get_label(GTK_MENU_BUTTON(get()));
    }
    virtual void set_use_underline(gboolean use_underline){
        gtk_menu_button_set_use_underline(GTK_MENU_BUTTON(get()), use_underline);
    }
    virtual gboolean get_use_underline(){
        return gtk_menu_button_get_use_underline(GTK_MENU_BUTTON(get()));
    }
    virtual void set_has_frame(gboolean has_frame){
        gtk_menu_button_set_has_frame(GTK_MENU_BUTTON(get()), has_frame);
    }
    virtual gboolean get_has_frame(){
        return gtk_menu_button_get_has_frame(GTK_MENU_BUTTON(get()));
    }
    virtual void set_active(gboolean active){
        gtk_menu_button_set_active(GTK_MENU_BUTTON(get()), active);
    }
    virtual gboolean get_active(){
        return gtk_menu_button_get_active(GTK_MENU_BUTTON(get()));
    }
    virtual void set_can_shrink(gboolean can_shrink){
        gtk_menu_button_set_can_shrink(GTK_MENU_BUTTON(get()), can_shrink);
    }
    virtual gboolean get_can_shrink(){
        return gtk_menu_button_get_can_shrink(GTK_MENU_BUTTON(get()));
    }
    virtual void set_child(IWidget* child){
        gtk_menu_button_set_child(GTK_MENU_BUTTON(get()), GTK_WIDGET(child->get()));
    }
    virtual IWidget get_child(){
        return { gtk_menu_button_get_child(GTK_MENU_BUTTON(get())) };
    }
    virtual void set_create_popup_func(GtkMenuButtonCreatePopupFunc func, gpointer user_data, GDestroyNotify destroy_notify){
        gtk_menu_button_set_create_popup_func(GTK_MENU_BUTTON(get()), func, user_data, destroy_notify);
    }
    virtual void set_primary(gboolean primary){
        gtk_menu_button_set_primary(GTK_MENU_BUTTON(get()), primary);
    }
    virtual gboolean get_primary(){
        return gtk_menu_button_get_primary(GTK_MENU_BUTTON(get()));
    }
};

}

#endif