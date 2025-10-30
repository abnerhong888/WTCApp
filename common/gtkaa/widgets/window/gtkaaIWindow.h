#ifndef __gtkaaIWindow_H__
#define __gtkaaIWindow_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IWindow: public IWidget{
INHERIT_FROM_IWIDGET(IWindow)
public:
    virtual void activate(GObject *obj, gpointer user_data){}
public:
    virtual gtkaa::sptrGTKWidget createWindow(GtkApplication* app){
        return createWidget(gtk_application_window_new(app));
    }
    virtual gtkaa::sptrGTKWidget createWindow(){
        return createWidget(gtk_window_new());
    }
    virtual gtkaa::sptrGTKWidget createWindow(gtkaa::sptrGTKWidget widget){
        m_widget = widget;
        return m_widget;
    }
    void set_application(GtkApplication* app){
        gtk_window_set_application(GTK_WINDOW(get()), app);
    }
    void present(){
        gtk_window_present(GTK_WINDOW(get()));
    }
    virtual void set_title(std::string title){
        gtk_window_set_title(GTK_WINDOW(get()), title.c_str());
    }
    virtual void set_default_size(int width, int height){
        gtk_window_set_default_size(GTK_WINDOW(get()), width, height);
    }
    virtual void set_child(IWidget* widget){
        gtk_window_set_child(GTK_WINDOW(get()), GTK_WIDGET(widget->get()));
    }

};

}

#endif