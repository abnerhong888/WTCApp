#ifndef __gtkaaIListBox_H__
#define __gtkaaIListBox_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IListBoxRow: public IWidget{
INHERIT_FROM_IWIDGET(IListBoxRow)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_list_box_row_new());
    }
    virtual void set_child(IWidget *child){
        gtk_list_box_row_set_child(GTK_LIST_BOX_ROW(get()), GTK_WIDGET(child->get()));
    }
    virtual IWidget get_child(){
        return { gtk_list_box_row_get_child(GTK_LIST_BOX_ROW(get())) };
    }
    virtual void set_header(IWidget *header){
        gtk_list_box_row_set_header(GTK_LIST_BOX_ROW(get()), GTK_WIDGET(header->get()));
    }
    virtual IWidget get_header(){
        return { gtk_list_box_row_get_header(GTK_LIST_BOX_ROW(get())) };
    }
    virtual int get_index(){
        return gtk_list_box_row_get_index(GTK_LIST_BOX_ROW(get()));
    }
    virtual void changed(){
        gtk_list_box_row_changed(GTK_LIST_BOX_ROW(get()));
    }
    virtual void set_selectable(gboolean selectable){
        gtk_list_box_row_set_selectable(GTK_LIST_BOX_ROW(get()), selectable);
    }
    virtual gboolean get_selectable(){
        return gtk_list_box_row_get_selectable(GTK_LIST_BOX_ROW(get()));
    }
    virtual void set_activatable(gboolean activatable){
        gtk_list_box_row_set_activatable(GTK_LIST_BOX_ROW(get()), activatable);
    }
    virtual gboolean get_activatable(){
        return gtk_list_box_row_get_activatable(GTK_LIST_BOX_ROW(get()));
    }
};


class IListBox: public IWidget{
INHERIT_FROM_IWIDGET(IListBox)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_list_box_new());
    }
    virtual void prepend(IWidget *child){
        gtk_list_box_prepend(GTK_LIST_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void append(IWidget *child){
        gtk_list_box_append(GTK_LIST_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void insert(IWidget *child, int position){
        gtk_list_box_insert(GTK_LIST_BOX(get()), GTK_WIDGET(child->get()), position);
    }
    virtual void remove(IWidget *child){
        gtk_list_box_remove(GTK_LIST_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void remove_all(){
        gtk_list_box_remove_all(GTK_LIST_BOX(get()));
    }
    virtual IListBoxRow get_selected_row(){
        return { GTK_WIDGET(gtk_list_box_get_selected_row(GTK_LIST_BOX(get()))) };
    }
    virtual IListBoxRow get_row_at_index(int index_){
        return { GTK_WIDGET(gtk_list_box_get_row_at_index(GTK_LIST_BOX(get()), index_)) };
    }
    virtual IListBoxRow get_row_at_y(int y){
        return { GTK_WIDGET(gtk_list_box_get_row_at_y(GTK_LIST_BOX(get()), y)) };
    }
    virtual void select_row(IListBoxRow *row){
        gtk_list_box_select_row(GTK_LIST_BOX(get()), GTK_LIST_BOX_ROW(row->get()));
    }
    virtual void set_placeholder(IWidget *placeholder){
        gtk_list_box_set_placeholder(GTK_LIST_BOX(get()), GTK_WIDGET(placeholder->get()));
    }
    virtual void set_filter_func(GtkListBoxFilterFunc func, gpointer user_data, GDestroyNotify notify){
        gtk_list_box_set_filter_func(GTK_LIST_BOX(get()), func, user_data, notify);
    }
    virtual void set_sort_func(GtkListBoxSortFunc func, gpointer user_data, GDestroyNotify notify){
        gtk_list_box_set_sort_func(GTK_LIST_BOX(get()), func, user_data, notify);
    }
    virtual void set_header_func(GtkListBoxUpdateHeaderFunc func, gpointer user_data, GDestroyNotify notify){
        gtk_list_box_set_header_func(GTK_LIST_BOX(get()), func, user_data, notify);
    }
    virtual void invalidate_filter(){
        gtk_list_box_invalidate_filter(GTK_LIST_BOX(get()));
    }
    virtual void invalidate_sort(){
        gtk_list_box_invalidate_sort(GTK_LIST_BOX(get()));
    }
    virtual void invalidate_headers(){
        gtk_list_box_invalidate_headers(GTK_LIST_BOX(get()));
    }
};

}

#endif