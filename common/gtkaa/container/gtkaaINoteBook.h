#ifndef __gtkaaINoteBook_H__
#define __gtkaaINoteBook_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class INoteBook: public IWidget{
INHERIT_FROM_IWIDGET(INoteBook)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_notebook_new());
    }
    virtual void append_page(IWidget *child, IWidget *tab_label){
        gtk_notebook_append_page(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()));
    }
    virtual void append_page_menu(IWidget *child, IWidget *tab_label, IWidget *menu_label){
        gtk_notebook_append_page_menu(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()), GTK_WIDGET(menu_label->get()));
    }
    virtual void prepend_page(IWidget *child, IWidget *tab_label){
        gtk_notebook_prepend_page(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()));
    }
    virtual void prepend_page_menu(IWidget *child, IWidget *tab_label, IWidget *menu_label){
        gtk_notebook_prepend_page_menu(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()), GTK_WIDGET(menu_label->get()));
    }
    virtual void insert_page(IWidget *child, IWidget *tab_label, int position){
        gtk_notebook_insert_page(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()), position);
    }
    virtual void insert_page_menu(IWidget *child, IWidget *tab_label, IWidget *menu_label, int position){
        gtk_notebook_insert_page_menu(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()), GTK_WIDGET(menu_label->get()), position);
    }
    virtual void remove_page(int page_num){
        gtk_notebook_remove_page(GTK_NOTEBOOK(get()), page_num);
    }
    virtual int get_current_page(){
        return gtk_notebook_get_current_page(GTK_NOTEBOOK(get()));
    }
    virtual void set_current_page(int page_num){
        gtk_notebook_set_current_page(GTK_NOTEBOOK(get()), page_num);
    }
    virtual void next_page(){
        gtk_notebook_next_page(GTK_NOTEBOOK(get()));
    }
    virtual void prev_page(){
        gtk_notebook_prev_page(GTK_NOTEBOOK(get()));
    }
    virtual void set_show_border(gboolean show_border){
        gtk_notebook_set_show_border(GTK_NOTEBOOK(get()), show_border);
    }
    virtual gboolean get_show_border(){
        return gtk_notebook_get_show_border(GTK_NOTEBOOK(get()));
    }
    virtual void set_show_tabs(gboolean show_tabs){
        gtk_notebook_set_show_tabs(GTK_NOTEBOOK(get()), show_tabs);
    }
    virtual gboolean get_show_tabs(){
        return gtk_notebook_get_show_tabs(GTK_NOTEBOOK(get()));
    }
    virtual void set_tab_pos(GtkPositionType pos){
        gtk_notebook_set_tab_pos(GTK_NOTEBOOK(get()), pos);
    }
    virtual GtkPositionType get_tab_pos(){
        return gtk_notebook_get_tab_pos(GTK_NOTEBOOK(get()));
    }
    virtual void set_scrollable(gboolean scrollable){
        gtk_notebook_set_scrollable(GTK_NOTEBOOK(get()), scrollable);
    }
    virtual gboolean get_scrollable(){
        return gtk_notebook_get_scrollable(GTK_NOTEBOOK(get()));
    }
    virtual void popup_enable(){
        gtk_notebook_popup_enable(GTK_NOTEBOOK(get()));
    }
    virtual void popup_disable(){
        gtk_notebook_popup_disable(GTK_NOTEBOOK(get()));
    }
    virtual void set_tab_label(IWidget *child, IWidget *tab_label){
        gtk_notebook_set_tab_label(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(tab_label->get()));
    }
    virtual void set_menu_label(IWidget *child, IWidget *menu_label){
        gtk_notebook_set_menu_label(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), GTK_WIDGET(menu_label->get()));
    }
    virtual void reorder_child(IWidget *child, int position){
        gtk_notebook_reorder_child(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), position);
    }
    virtual void set_group_name(const char *group_name){
        gtk_notebook_set_group_name(GTK_NOTEBOOK(get()), group_name);
    }
    virtual const char *get_group_name(){
        return gtk_notebook_get_group_name(GTK_NOTEBOOK(get()));
    }
    virtual void set_tab_label_text(IWidget *child, const char *tab_text){
        gtk_notebook_set_tab_label_text(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), tab_text);
    }
    virtual const char *get_tab_label_text(IWidget *child){
        return gtk_notebook_get_tab_label_text(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()));
    }
    virtual void set_menu_label_text(IWidget *child, const char *menu_text){
        gtk_notebook_set_menu_label_text(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), menu_text);
    }
    virtual const char *get_menu_label_text(IWidget *child){
        return gtk_notebook_get_menu_label_text(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()));
    }
    virtual void set_tab_reorderable(IWidget *child, gboolean reorderable){
        gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), reorderable);
    }
    virtual gboolean get_tab_reorderable(IWidget *child){
        return gtk_notebook_get_tab_reorderable(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()));
    }
    virtual void set_tab_detachable(IWidget *child, gboolean detachable){
        gtk_notebook_set_tab_detachable(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()), detachable);
    }
    virtual gboolean get_tab_detachable(IWidget *child){
        return gtk_notebook_get_tab_detachable(GTK_NOTEBOOK(get()), GTK_WIDGET(child->get()));
    }
};

}

#endif