#ifndef __WTCSUBMENU_H__
#define __WTCSUBMENU_H__

#include "au_common.h"
#include <gtkaa/gtkaa.h>
#include <vector>

gulong g_id = 0;
static gboolean
on_leave(GtkEventControllerMotion *motion, gpointer user_data);

static gboolean
on_enter(GtkEventControllerMotion *motion, gpointer user_data)
{
    gtk_popover_popup(GTK_POPOVER(user_data));

    g_signal_handler_disconnect(motion, g_id);
    g_id = g_signal_connect(motion, "leave", G_CALLBACK(on_leave), user_data);
    return TRUE;
}

static gboolean
on_leave(GtkEventControllerMotion *motion, gpointer user_data)
{
    gtk_popover_popdown(GTK_POPOVER(user_data));

    g_signal_handler_disconnect(motion, g_id);
    g_id = g_signal_connect(motion, "enter", G_CALLBACK(on_enter), user_data);
    return TRUE;
}

class WTCSubMenu : public gtkaa::IButton{
public:
    WTCSubMenu(): gtkaa::IButton(""){
    }
    WTCSubMenu(std::string widgetName): gtkaa::IButton(widgetName){
    }
    ~WTCSubMenu(){
    }

    gtkaa::IBox m_vbox;
    gtkaa::IPopover m_popover;
    std::vector<gtkaa::IWidget> widgets;

    virtual gtkaa::sptrGTKWidget create(std::string label) override{
        gtkaa::IButton::create(label);
        this->add_css_class("wtc-menu-button");

        m_vbox.create(GTK_ORIENTATION_VERTICAL, 0);
        m_popover.create();
        m_popover.set_child(&m_vbox);
        m_popover.set_position(GTK_POS_RIGHT);
        m_popover.set_has_arrow(FALSE);
        m_popover.set_parent(this);
        m_popover.add_css_class("wtc-menu-button-popover");

        GtkEventController *motion = gtk_event_controller_motion_new();
        // this->event += gtkaa::g_event("enter", &WTCSubMenu::onMenuEnter, this);
        // this->event += gtkaa::g_event("leave", &WTCSubMenu::onMenuLeave, this);
        g_id = g_signal_connect(motion, "enter", G_CALLBACK(on_enter), m_popover.get());
        // g_signal_connect(motion, "leave", G_CALLBACK(on_leave), m_popover.get());
        this->add_controller(motion);

        return m_widget;
    }

    virtual void add_button(std::string label, std::function<void()> callback){
        gtkaa::IButton btn(m_widget_name + "_" + label);
        btn.create(label);
        btn.add_css_class("wtc-menu-item-button");

        btn.event += gtkaa::g_event("clicked", callback, btn.get());
        m_vbox.append(&btn);

        widgets.push_back(btn);
    }

    virtual void add_separator(){
        gtkaa::ISeparator separator;
        separator.create(GTK_ORIENTATION_HORIZONTAL);
        separator.add_css_class("wtc-menu-item-separator");
        m_vbox.append(&separator);

        widgets.push_back(separator);
    }

    virtual void add_submenu(){
    }

    void onMenuEnter(){
        m_popover.popup(); 
    }
    void onMenuLeave(){
        m_popover.popdown(); 
    }
};
#endif