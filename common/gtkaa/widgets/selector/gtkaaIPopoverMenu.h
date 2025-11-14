#ifndef __gtkaaIPopoverMenu_H__
#define __gtkaaIPopoverMenu_H__

#include "gtk/gtk.h"
#include "gtkaa/widgets/window/gtkaaIPopover.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPopoverMenu: public IPopover{
INHERIT_FROM(IPopoverMenu, IPopover)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_popover_menu_new_from_model(nullptr));
    }
    virtual gtkaa::sptrGTKWidget create(GMenuModel *model){
        return createWidget(gtk_popover_menu_new_from_model(model));
    }
    virtual void set_menu_model(GMenuModel *model){
        gtk_popover_menu_set_menu_model(GTK_POPOVER_MENU(get()), model);
    }
    virtual GMenuModel* get_menu_model(){
        return gtk_popover_menu_get_menu_model(GTK_POPOVER_MENU(get()));
    }
    virtual void set_flags(GtkPopoverMenuFlags flags){
        gtk_popover_menu_set_flags(GTK_POPOVER_MENU(get()), flags);
    }
    virtual GtkPopoverMenuFlags get_flags(){
        return gtk_popover_menu_get_flags(GTK_POPOVER_MENU(get()));
    }
    virtual gboolean add_child(IWidget *child, const char *id){
        return gtk_popover_menu_add_child(GTK_POPOVER_MENU(get()), GTK_WIDGET(child->get()), id);
    }
    virtual gboolean remove_child(IWidget *child){
        return gtk_popover_menu_remove_child(GTK_POPOVER_MENU(get()), GTK_WIDGET(child->get()));
    }
};

}

#endif