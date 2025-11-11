#ifndef __WTCWINDOW_H__
#define __WTCWINDOW_H__

#include <gtkaa/gtkaa.h>
#include "wtcCommon.h"
#include "wtcMenuBtn.h"

static void on_open_clicked(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
    g_print("Open clicked\n");
}

static void on_quit_clicked(GSimpleAction *action, GVariant *parameter, gpointer user_data) {
    g_print("Quit clicked\n");
    gtk_window_close(GTK_WINDOW(user_data));
}
static void on_menu_button_clicked(GtkButton *button, gpointer user_data)
{
    GtkPopover *popover = GTK_POPOVER(user_data);
    gtk_popover_popup(popover); // show popover
    // gtk_popover_present(popover); // show popover
    
    g_print("Open clicked %p\n", popover);
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


        GMenu* menu_model = g_menu_new();
        g_menu_append(menu_model, "Open", "app.open");
        g_menu_append(menu_model, "Save", "app.save");
        g_menu_append(menu_model, "Quit", "app.quit");

        m_popover_menu.create(G_MENU_MODEL(menu_model));
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



        // // Create popover content
        // GtkWidget *popover = gtk_popover_new();
        // GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
        // gtk_box_append(GTK_BOX(vbox), gtk_button_new_with_label("Open"));
        // gtk_box_append(GTK_BOX(vbox), gtk_button_new_with_label("Settings"));
        // gtk_popover_set_child(GTK_POPOVER(popover), vbox);

        // // Create text-only button
        // GtkWidget *text_button = gtk_button_new_with_label("Menu"); 
        // gtk_widget_add_css_class(text_button, "flat"); // optional

        // // Connect button -> popover
        // g_signal_connect(text_button, "clicked", G_CALLBACK(on_menu_button_clicked), popover);

        // // --- Connect popover to button ---
        // gtk_popover_set_has_arrow(GTK_POPOVER(popover), FALSE);
        // gtk_popover_set_position(GTK_POPOVER(popover), GTK_POS_BOTTOM);
        // gtk_widget_set_parent(GTK_WIDGET(popover), text_button);
        
        // // Add to headerbar
        // gtk_header_bar_pack_end(GTK_HEADER_BAR(m_header_bar.get()), text_button);

        m_menu_btn2.create("Menu2");
        m_menu_btn2.add_button("OPEN", [](){
            g_print("OPEN\n");
        });
        m_menu_btn2.add_button("SAVE", [](){
            g_print("SAVE\n");
        });
        m_menu_btn2.add_button("QUIT", [](){
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
