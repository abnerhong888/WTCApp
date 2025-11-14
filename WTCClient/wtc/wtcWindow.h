#ifndef __WTCWINDOW_H__
#define __WTCWINDOW_H__

#include <gtkaa/gtkaa.h>
#include "gtk/gtk.h"
#include "wtcCommon.h"
#include "wtcMenuBtn.h"
#include "wtcSubMenu.h"

static void on_open_clicked(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
    g_print("Open clicked\n");
}

static void on_quit_clicked(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
    g_print("Quit clicked\n");
    gtk_window_close(GTK_WINDOW(user_data));
}
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
    gtkaa::IHeaderBar m_header_bar;

    WTCMenuBtn m_menu_btn2;
    WTCSubMenu m_sub_menu;
public:
    void on_activate(GObject *obj, gpointer user_data) override{
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
        m_menu_button.set_always_show_arrow(FALSE);

        GMenu *submenu = g_menu_new();
        g_menu_append(submenu, "File A", "app.file_a");
        g_menu_append(submenu, "File B", "app.file_b");

        GMenu* menu_model = g_menu_new();
        g_menu_append(menu_model, "Open", "app.open");
        g_menu_append(menu_model, "Save", "app.save");
        g_menu_append(menu_model, "Quit", "app.quit");
        g_menu_append_submenu(menu_model, "File", G_MENU_MODEL(submenu));

        m_popover_menu.create(G_MENU_MODEL(menu_model));
        m_popover_menu.set_has_arrow(FALSE);
        g_object_unref(menu_model);
        
        m_menu_button.set_popover(&m_popover_menu);

        m_header_bar.create();
        set_header_bar(&m_header_bar);
        m_header_bar.pack_start(&m_menu_button);

        GSimpleActionGroup *actions = g_simple_action_group_new();

        GSimpleAction *open_action = g_simple_action_new("open", NULL);
        g_signal_connect(open_action, "activate", G_CALLBACK(on_open_clicked), NULL);
        g_action_map_add_action(G_ACTION_MAP(actions), G_ACTION(open_action));

        GSimpleAction *quit_action = g_simple_action_new("quit", NULL);
        g_signal_connect(quit_action, "activate", G_CALLBACK(on_quit_clicked), GTK_WINDOW(get()));
        g_action_map_add_action(G_ACTION_MAP(actions), G_ACTION(quit_action));

        gtk_widget_insert_action_group(GTK_WIDGET(get()), "app", G_ACTION_GROUP(actions));


        m_menu_btn2.create("Menu2");
        m_menu_btn2.add_button("OPEN                1", [](){
            g_print("OPEN\n");
        });
        m_menu_btn2.add_button("SAVE        2", [](){
            g_print("SAVE\n");
        });
        m_menu_btn2.add_button("QUIT        3", [](){
            g_print("QUIT\n");
        });

        m_menu_btn2.add_separator();
        m_sub_menu.create("MenuSubbb");
        m_sub_menu.add_button("item1", [](){ g_print("item1\n"); });
        m_sub_menu.add_button("item2", [](){ g_print("item2\n"); });
        m_sub_menu.add_button("item3", [](){ g_print("item3\n"); });
        m_menu_btn2.add_submenu(&m_sub_menu);
        m_menu_btn2.add_separator();
        m_menu_btn2.add_button("QUIT        4", [](){
            g_print("QUIT\n");
        });
        m_header_bar.pack_end(&m_menu_btn2);

    }

    void on_paned_position_changed(){
        printf("456 \n"); 
        // reinterpret_cast<IWindow*>(user_data)->paned_position_changed(obj, user_data);
    }
};

#endif
