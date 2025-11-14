#ifndef __WTCMENUBTN_H__
#define __WTCMENUBTN_H__

#include "wtcSubMenu.h"
#include <gtkaa/gtkaa.h>
#include <vector>

class WTCMenuBtn : public gtkaa::IButton{
public:
    WTCMenuBtn(): gtkaa::IButton(""){
    }
    WTCMenuBtn(std::string widgetName): gtkaa::IButton(widgetName){
    }
    ~WTCMenuBtn(){
    }

    gtkaa::IBox m_vbox;
    gtkaa::IPopover m_popover;
    std::vector<gtkaa::IWidget> widgets;

    virtual gtkaa::sptrGTKWidget create(std::string label) override{
        gtkaa::IButton::create(label);
        this->add_css_class("wtc-menu-button");
        this->event += gtkaa::g_event("clicked", &WTCMenuBtn::onMenuBtnClicked, this);

        m_vbox.create(GTK_ORIENTATION_VERTICAL, 0);
        m_popover.create();
        m_popover.set_child(&m_vbox);
        m_popover.set_position(GTK_POS_BOTTOM);
        m_popover.set_has_arrow(FALSE);
        m_popover.set_parent(this);
        m_popover.add_css_class("wtc-menu-button-popover");

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

    virtual void add_submenu(WTCSubMenu* submenu){
        m_vbox.append(submenu);
    }

    void onMenuBtnClicked(){
        m_popover.popup(); 
    }
};
#endif