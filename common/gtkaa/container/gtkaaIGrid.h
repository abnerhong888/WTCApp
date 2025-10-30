#ifndef __gtkaaIGrid_H__
#define __gtkaaIGrid_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IGrid: public IWidget{
INHERIT_FROM_IWIDGET(IGrid)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_grid_new());
    }

    virtual void attach(IWidget* widget, int column, int row, int width, int height){
        gtk_grid_attach(GTK_GRID(get()), GTK_WIDGET(widget->get()), column, row, width, height);
    }
    virtual void attach_next_to(IWidget* widget, IWidget* sibling, GtkPositionType side, int width, int height){
        gtk_grid_attach_next_to(GTK_GRID(get()), GTK_WIDGET(widget->get()), GTK_WIDGET(sibling->get()), side, width, height);
    }
    virtual IWidget get_child_at(int column, int row){
        return { gtk_grid_get_child_at(GTK_GRID(get()), column, row) };
    }
    virtual void remove(IWidget* widget){
        gtk_grid_remove(GTK_GRID(get()), GTK_WIDGET(widget->get()));
    }
    virtual void insert_row(int position){
        gtk_grid_insert_row(GTK_GRID(get()), position);
    }
    virtual void insert_column(int position){
        gtk_grid_insert_column(GTK_GRID(get()), position);
    }
    virtual void remove_row(int position){
        gtk_grid_remove_row(GTK_GRID(get()), position);
    }
    virtual void remove_column(int position){
        gtk_grid_remove_column(GTK_GRID(get()), position);
    }
    virtual void insert_next_to(IWidget* sibling, GtkPositionType side){
        gtk_grid_insert_next_to(GTK_GRID(get()), GTK_WIDGET(sibling->get()), side);
    }
    virtual void set_row_homogeneous(gboolean homogeneous){
        gtk_grid_set_row_homogeneous(GTK_GRID(get()), homogeneous);
    }
    virtual gboolean get_row_homogeneous(){
        return gtk_grid_get_row_homogeneous(GTK_GRID(get()));
    }
    virtual void set_row_spacing(guint spacing){
        gtk_grid_set_row_spacing(GTK_GRID(get()), spacing);
    }
    virtual guint get_row_spacing(){
        return gtk_grid_get_row_spacing(GTK_GRID(get()));
    }
    virtual void set_column_homogeneous(gboolean homogeneous){
        gtk_grid_set_column_homogeneous(GTK_GRID(get()), homogeneous);
    }
    virtual gboolean get_column_homogeneous(){
        return gtk_grid_get_column_homogeneous(GTK_GRID(get()));
    }
    virtual void set_column_spacing(guint spacing){
        gtk_grid_set_column_spacing(GTK_GRID(get()), spacing);
    }
    virtual guint get_column_spacing(){
        return gtk_grid_get_column_spacing(GTK_GRID(get()));
    }
    virtual void set_row_baseline_position(int row, GtkBaselinePosition pos){
        gtk_grid_set_row_baseline_position(GTK_GRID(get()), row, pos);
    }
    virtual GtkBaselinePosition get_row_baseline_position(int row){
        return gtk_grid_get_row_baseline_position(GTK_GRID(get()), row);
    }
    virtual void set_baseline_row(int row){
        gtk_grid_set_baseline_row(GTK_GRID(get()), row);
    }
    virtual int get_baseline_row(){
        return gtk_grid_get_baseline_row(GTK_GRID(get()));
    }
    virtual void query_child(IWidget* child, int* column, int* row, int* width, int* height){
        gtk_grid_query_child(GTK_GRID(get()), GTK_WIDGET(child->get()), column, row, width, height);
    }
};

}

#endif