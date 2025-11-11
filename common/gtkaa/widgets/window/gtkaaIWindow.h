#ifndef __gtkaaIWindow_H__
#define __gtkaaIWindow_H__

#include "gtkaa/base/gtkaaIWidget.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IWindow: public IWidget{
INHERIT_FROM_IWIDGET(IWindow)
public:
    virtual void on_activate(GObject *obj, gpointer user_data){}
public:
    virtual gtkaa::sptrGTKWidget create(GtkApplication* app){
        return createWidget(gtk_application_window_new(app));
    }
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_window_new());
    }
    virtual gtkaa::sptrGTKWidget create(gtkaa::sptrGTKWidget widget){
        m_widget = widget;
        return m_widget;
    }
    void set_application(GtkApplication* app){
        gtk_window_set_application(GTK_WINDOW(get()), app);
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
    virtual void set_header_bar(IWidget* widget){
        gtk_window_set_titlebar(GTK_WINDOW(get()), GTK_WIDGET(widget->get()));
    }
    virtual void set_modal(gboolean modal){
        gtk_window_set_modal(GTK_WINDOW(get()), modal);
    }
    virtual void set_resizable(gboolean resizable){
        gtk_window_set_resizable(GTK_WINDOW(get()), resizable);
    }
    virtual void set_decorated(gboolean decorated){
        gtk_window_set_decorated(GTK_WINDOW(get()), decorated);
    }
    virtual void set_deletable(gboolean deletable){
        gtk_window_set_deletable(GTK_WINDOW(get()), deletable);
    }
    virtual void set_hide_on_close(gboolean hide_on_close){
        gtk_window_set_hide_on_close(GTK_WINDOW(get()), hide_on_close);
    }
    virtual void set_mnemonics_visible(gboolean mnemonics_visible){
        gtk_window_set_mnemonics_visible(GTK_WINDOW(get()), mnemonics_visible);
    }
    virtual void set_focus_visible(gboolean focus_visible){
        gtk_window_set_focus_visible(GTK_WINDOW(get()), focus_visible);
    }
    virtual void set_icon_name(std::string icon_name){
        gtk_window_set_icon_name(GTK_WINDOW(get()), icon_name.c_str());
    }
    virtual void set_default_icon_name(std::string icon_name){
        gtk_window_set_default_icon_name(icon_name.c_str());
    }
    virtual void set_auto_startup_notification(gboolean auto_startup_notification){
        gtk_window_set_auto_startup_notification(auto_startup_notification);
    }
    virtual void set_startup_id(std::string startup_id){
        gtk_window_set_startup_id(GTK_WINDOW(get()), startup_id.c_str());
    }
    virtual void set_transient_for(IWindow* transient_for){
        gtk_window_set_transient_for(GTK_WINDOW(get()), GTK_WINDOW(transient_for->get()));
    }
    virtual void set_destroy_with_parent(gboolean destroy_with_parent){
        gtk_window_set_destroy_with_parent(GTK_WINDOW(get()), destroy_with_parent);
    }
    virtual IWidget get_focus(){
        return { gtk_window_get_focus(GTK_WINDOW(get())) };
    }
    virtual IWidget get_default_widget(){
        return { gtk_window_get_default_widget(GTK_WINDOW(get())) };
    }
    virtual void set_default_widget(IWidget* default_widget){
        gtk_window_set_default_widget(GTK_WINDOW(get()), GTK_WIDGET(default_widget->get()));
    }
    virtual IWindow get_transient_for(){
        return { GTK_WIDGET(gtk_window_get_transient_for(GTK_WINDOW(get()))) };
    }
    virtual gboolean get_destroy_with_parent(){
        return gtk_window_get_destroy_with_parent(GTK_WINDOW(get()));
    }
    virtual gboolean get_hide_on_close(){
        return gtk_window_get_hide_on_close(GTK_WINDOW(get()));
    }
    virtual gboolean get_mnemonics_visible(){
        return gtk_window_get_mnemonics_visible(GTK_WINDOW(get()));
    }
    virtual gboolean get_focus_visible(){
        return gtk_window_get_focus_visible(GTK_WINDOW(get()));
    }
    virtual gboolean get_resizable(){
        return gtk_window_get_resizable(GTK_WINDOW(get()));
    }
    virtual gboolean get_is_active(){
        return gtk_window_is_active(GTK_WINDOW(get()));
    }
    virtual gboolean get_decorated(){
        return gtk_window_get_decorated(GTK_WINDOW(get()));
    }
    virtual gboolean get_deletable(){
        return gtk_window_get_deletable(GTK_WINDOW(get()));
    }
    virtual const char* get_icon_name(){
        return gtk_window_get_icon_name(GTK_WINDOW(get()));
    }
    virtual const char* get_default_icon_name(){
        return gtk_window_get_default_icon_name();
    }
    virtual gboolean get_modal(){
        return gtk_window_get_modal(GTK_WINDOW(get()));
    }
    virtual GListModel* get_toplevels(){
        return gtk_window_get_toplevels();
    }
    virtual GList* list_toplevels(){
        return gtk_window_list_toplevels();
    }

    virtual void present(){
        gtk_window_present(GTK_WINDOW(get()));
    }
    virtual void minimize(){
        gtk_window_minimize(GTK_WINDOW(get()));
    }
    virtual void unminimize(){
        gtk_window_unminimize(GTK_WINDOW(get()));
    }
    virtual void maximize(){
        gtk_window_maximize(GTK_WINDOW(get()));
    }
    virtual void unmaximize(){
        gtk_window_unmaximize(GTK_WINDOW(get()));
    }
    virtual void fullscreen(){
        gtk_window_fullscreen(GTK_WINDOW(get()));
    }
    virtual void unfullscreen(){
        gtk_window_unfullscreen(GTK_WINDOW(get()));
    }
    virtual void close(){
        gtk_window_close(GTK_WINDOW(get()));
    }
    virtual void destroy(){
        gtk_window_destroy(GTK_WINDOW(get()));
    }
};

}

#endif