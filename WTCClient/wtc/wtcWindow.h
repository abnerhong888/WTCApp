#ifndef __WTCWINDOW_H__
#define __WTCWINDOW_H__

#include <gtkaa/gtkaa.h>
#include "gio/gio.h"
#include "gio/gmenumodel.h"
#include "gtkaa/container/gtkaaIGrid.h"
#include "gtkaa/container/gtkaaIHeaderBar.h"
#include "gtkaa/widgets/interaction/gtkaaIButton.h"
#include "gtkaa/widgets/window/gtkaaIMenuButton.h"
#include "gtkaa/widgets/window/gtkaaIPopover.h"
#include "wtcCommon.h"

class WTCWindow : public gtkaa::IWindow{
public:
    WTCWindow(): gtkaa::IWindow(""){
    }
    WTCWindow(std::string widgetName): gtkaa::IWindow(widgetName){
    }
    ~WTCWindow(){
    }

    std::string title = "WTC";
    int height = 600;
    int width = 800;


    gtkaa::IBuilder m_builder;
    gtkaa::ICssProvider m_css_provider;

    gtkaa::IPaned m_paned;
    gtkaa::ILabel m_label;
    gtkaa::ILabel m_label2;
    gtkaa::IGrid m_grid;
    
    gtkaa::IMenuButton m_menu_button;
    gtkaa::IPopoverMenu m_popover_menu;
    gtkaa::IButton m_button;
    gtkaa::IHeaderBar m_header_bar;
public:
    void activate(GObject *obj, gpointer user_data) override{
        create(GTK_APPLICATION(obj));     
        set_title(title);
        set_default_size(width, height);

        header_bar_menu();

        m_paned.create(GTK_ORIENTATION_HORIZONTAL);


        m_label.create("Left Pane Content");
        m_label2.create("Right Pane Content");

        // m_paned.set_start_child(&m_label);
        // m_paned.set_end_child(&m_label2);
        // m_paned.set_position(150);
        // m_paned.event += gtkaa::g_event("notify::position", &WTCWindow::on_paned_position_changed, this);
        // set_child(&m_paned);

        // m_grid.create();
        // m_grid.attach(&m_label, 0, 0, 1, 1);
        // m_grid.attach(&m_label2, 0, 1, 1, 1);
        // set_child(&m_grid);

        // BUILDER_LOAD(m_builder, MAIN_WINDOW_UI);
        // create(m_builder.get_object<GtkWidget>("main_window"));
        CSS_LOAD(m_css_provider, MAIN_WINDOW_CSS);
        m_css_provider.apply();

    
        set_application(GTK_APPLICATION(obj));
        present();
    }

    void header_bar_menu(){
        m_menu_button.create();
        m_menu_button.set_label("Menu");

        GMenu* menu_model = g_menu_new();
        g_menu_append(menu_model, "Open", "app.open");
        g_menu_append(menu_model, "Save", "app.save");
        g_menu_append(menu_model, "Quit", "app.quit");

        m_popover_menu.create(G_MENU_MODEL(menu_model));
        g_object_unref(menu_model);
        m_button.create();
        m_button.set_label("Button");
        m_popover_menu.add_child(&m_button, "Button");
        
        m_menu_button.set_popover(&m_popover_menu);

        m_header_bar.create();
        set_header_bar(&m_header_bar);
        m_header_bar.pack_start(&m_menu_button);
    }

    void on_paned_position_changed(){
        printf("456 \n"); 
        // reinterpret_cast<IWindow*>(user_data)->paned_position_changed(obj, user_data);
    }
};

#endif
