#ifndef __WTCWINDOW_H__
#define __WTCWINDOW_H__

#include <gtkaa/gtkaa.h>
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
public:
    void activate(GObject *obj, gpointer user_data) override{
        create(GTK_APPLICATION(obj));     
        set_title(title);
        set_default_size(width, height);

        m_paned.create(GTK_ORIENTATION_HORIZONTAL);


        m_label.create("Left Pane Content");
        m_label2.create("Right Pane Content");

        m_paned.set_start_child(&m_label);
        m_paned.set_end_child(&m_label2);
        m_paned.set_position(150);
        m_paned.event += gtkaa::g_event("notify::position", &WTCWindow::on_paned_position_changed, this);
        set_child(&m_paned);

        // BUILDER_LOAD(m_builder, MAIN_WINDOW_UI);
        // create(m_builder.get_object<GtkWidget>("main_window"));
        CSS_LOAD(m_css_provider, MAIN_WINDOW_CSS);
        m_css_provider.apply();

    
        set_application(GTK_APPLICATION(obj));
        present();
    }
    void on_paned_position_changed(){
        printf("456 \n"); 
        // reinterpret_cast<IWindow*>(user_data)->paned_position_changed(obj, user_data);
    }
};

#endif
