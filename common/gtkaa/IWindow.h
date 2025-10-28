#ifndef __IWINDOW_H__
#define __IWINDOW_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h>

namespace GTKAA_NAMESPACE{

class IWindow: public IWidget{

public:
    virtual ~IWindow() = default;
    IWindow(){}
    IWindow(std::string widgetName): IWidget(widgetName){}
    virtual void activate(GObject *obj, gpointer user_data){}
public:
    virtual gpointer get(){
        return m_widget.get();
    } 
    virtual gtkaa::sptrGTKWidget createWindow(GtkApplication* app){
        if(!m_widget)
            m_widget = gtkaa::make_ptr_release(gtk_application_window_new(app));

        if(!m_widget_name.empty())
            gtk_widget_set_name(GTK_WIDGET(m_widget.get()), m_widget_name.c_str());

        return m_widget;
    }
    virtual gtkaa::sptrGTKWidget createWindow(){
        if(!m_widget)
            m_widget = gtkaa::make_ptr_release(gtk_window_new());

        if(!m_widget_name.empty())
            gtk_widget_set_name(GTK_WIDGET(m_widget.get()), m_widget_name.c_str());
        return m_widget;
    }
    virtual gtkaa::sptrGTKWidget createWindow(gtkaa::sptrGTKWidget widget){
        m_widget = widget;
        return m_widget;
    }
    void set_application(GtkApplication* app){
        gtk_window_set_application(GTK_WINDOW(this->get()), app);
    }
    void present(){
        gtk_window_present(GTK_WINDOW(this->get()));
    }
    virtual void set_title(std::string title){
        gtk_window_set_title(GTK_WINDOW(this->get()), title.c_str());
    }
    virtual void set_default_size(int width, int height){
        gtk_window_set_default_size(GTK_WINDOW(this->get()), width, height);
    }
    virtual void set_child(gtkaa::sptrGTKWidget child){
        gtk_window_set_child(GTK_WINDOW(this->get()), child.get());
    }

};

}

#endif