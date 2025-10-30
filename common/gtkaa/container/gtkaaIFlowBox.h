#ifndef __gtkaaIFLOWBOX_H__
#define __gtkaaIFLOWBOX_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFlowBoxChild: public IWidget{
INHERIT_FROM_IWIDGET(IFlowBoxChild)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_flow_box_child_new());
    }
    virtual void set_child(IWidget* child){
        gtk_flow_box_child_set_child(GTK_FLOW_BOX_CHILD(get()), GTK_WIDGET(child->get()));
    }
    virtual IWidget get_child(){
        return { gtk_flow_box_child_get_child(GTK_FLOW_BOX_CHILD(get())) };
    }
    virtual int get_index(){
        return gtk_flow_box_child_get_index(GTK_FLOW_BOX_CHILD(get()));
    }
    virtual gboolean is_selected(){
        return gtk_flow_box_child_is_selected(GTK_FLOW_BOX_CHILD(get()));
    }
    virtual void changed(){
        gtk_flow_box_child_changed(GTK_FLOW_BOX_CHILD(get()));
    }
};

class IFlowBox: public IWidget{
INHERIT_FROM_IWIDGET(IFlowBox)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_flow_box_new());
    }
    virtual void bind_model(GListModel* model, GtkFlowBoxCreateWidgetFunc create_widget_func, gpointer user_data, GDestroyNotify user_data_free_func){
        gtk_flow_box_bind_model(GTK_FLOW_BOX(get()), model, create_widget_func, user_data, user_data_free_func);
    }
    virtual void set_homogeneous(gboolean homogeneous){
        gtk_flow_box_set_homogeneous(GTK_FLOW_BOX(get()), homogeneous);
    }
    virtual void set_row_spacing(guint spacing){
        gtk_flow_box_set_row_spacing(GTK_FLOW_BOX(get()), spacing);
    }
    virtual void set_column_spacing(guint spacing){
        gtk_flow_box_set_column_spacing(GTK_FLOW_BOX(get()), spacing);
    }
    virtual void set_min_children_per_line(guint n_children){
        gtk_flow_box_set_min_children_per_line(GTK_FLOW_BOX(get()), n_children);
    }
    virtual void set_max_children_per_line(guint n_children){
        gtk_flow_box_set_max_children_per_line(GTK_FLOW_BOX(get()), n_children);
    }
    virtual void set_activate_on_single_click(gboolean single){
        gtk_flow_box_set_activate_on_single_click(GTK_FLOW_BOX(get()), single);
    }
    virtual void prepend(IWidget* child){
        gtk_flow_box_prepend(GTK_FLOW_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void append(IWidget* child){
        gtk_flow_box_append(GTK_FLOW_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void insert(IWidget* child, int position){
        gtk_flow_box_insert(GTK_FLOW_BOX(get()), GTK_WIDGET(child->get()), position);
    }
    virtual void remove(IWidget* child){
        gtk_flow_box_remove(GTK_FLOW_BOX(get()), GTK_WIDGET(child->get()));
    }
    virtual void remove_all(){
        gtk_flow_box_remove_all(GTK_FLOW_BOX(get()));
    }
    virtual IFlowBoxChild get_child_at_index(int idx){
        return { GTK_WIDGET(gtk_flow_box_get_child_at_index(GTK_FLOW_BOX(get()), idx)) };
    }
    virtual IFlowBoxChild get_child_at_pos(int x, int y){
        return { GTK_WIDGET(gtk_flow_box_get_child_at_pos(GTK_FLOW_BOX(get()), x, y)) };
    }
    virtual void selected_foreach(GtkFlowBoxForeachFunc func, gpointer user_data){
        gtk_flow_box_selected_foreach(GTK_FLOW_BOX(get()), func, user_data);
    }
    virtual GList* get_selected_children(){
        return gtk_flow_box_get_selected_children(GTK_FLOW_BOX(get()));
    }
    virtual void select_child(IFlowBoxChild child){
        gtk_flow_box_select_child(GTK_FLOW_BOX(get()), GTK_FLOW_BOX_CHILD(child.get()));
    }
    virtual void unselect_child(IFlowBoxChild child){
        gtk_flow_box_unselect_child(GTK_FLOW_BOX(get()), GTK_FLOW_BOX_CHILD(child.get()));
    }
    virtual void select_all(){
        gtk_flow_box_select_all(GTK_FLOW_BOX(get()));
    }
    virtual void unselect_all(){
        gtk_flow_box_unselect_all(GTK_FLOW_BOX(get()));
    }
};

}

#endif