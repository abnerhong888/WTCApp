#ifndef __WTCWINDOW_H__
#define __WTCWINDOW_H__

#include "gtkaa/gtkaa.h"
#include "wtcCommon.h"

class WTCWindow : public gtkaa::IWindow{
public:
    WTCWindow(){
    }
    ~WTCWindow(){
    }
    gtkaa::sptrGTKBuilder m_builder = nullptr;
    gtkaa::sptrGTKCssProvider m_css_provider = nullptr;
    gtkaa::sptrGTKWindow m_window = nullptr;
public:
    int init(){
        m_builder = gtkaa::make_ptr_release(gtk_builder_new());
        m_css_provider = gtkaa::make_ptr_release(gtk_css_provider_new());

        
        return 0;
    }
    GtkPaned *paned;
private:
    void activate(GObject *obj, gpointer user_data) override{
        GError* error = NULL;

        BUILDER_LOAD(m_builder.get(), MAIN_WINDOW_UI, &error);
        CSS_LOAD(m_css_provider.get(), MAIN_WINDOW_CSS);

        if(error){
            INFO_LOG("Failed to load ui file: %s", error->message);
            g_error_free(error);
            return;
        }

        m_window = gtkaa::make_ptr_from_builder(
            GTK_WINDOW( gtk_builder_get_object(m_builder.get(), "main_window") )
        );
        
        gtk_style_context_add_provider_for_display(
            gdk_display_get_default(), 
            GTK_STYLE_PROVIDER(m_css_provider.get()), 
            GTK_STYLE_PROVIDER_PRIORITY_USER
        );
        
        

        paned = GTK_PANED(gtk_builder_get_object(m_builder.get(), "horizontal_paned"));
        g_signal_connect(paned, "notify::position", G_CALLBACK(on_paned_position_changed), NULL);
    

        gtk_window_set_application (m_window.get(), (GtkApplication*)obj);
        gtk_window_present(m_window.get());
    }
};

#endif
