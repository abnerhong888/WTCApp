#ifndef __gtkaaIBox_H__
#define __gtkaaIBox_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IBox: public IWidget{
INHERIT_FROM(IBox, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation, int spacing){
        return createWidget(gtk_box_new(orientation, spacing));
    }
    virtual void append(IWidget* widget){
        gtk_box_append(GTK_BOX(get()), GTK_WIDGET(widget->get()));
    }
    virtual void prepend(IWidget* widget){
        gtk_box_prepend(GTK_BOX(get()), GTK_WIDGET(widget->get()));
    }
    virtual void remove(IWidget* widget){
        gtk_box_remove(GTK_BOX(get()), GTK_WIDGET(widget->get()));
    }
    virtual void insert_child_after(IWidget* widget, IWidget* sibling){
        gtk_box_insert_child_after(GTK_BOX(get()), GTK_WIDGET(widget->get()), GTK_WIDGET(sibling->get()));
    }
    virtual void reorder_child_after(IWidget* widget, IWidget* sibling){
        gtk_box_reorder_child_after(GTK_BOX(get()), GTK_WIDGET(widget->get()), GTK_WIDGET(sibling->get()));
    }
    virtual void set_homogeneous(gboolean homogeneous){
        gtk_box_set_homogeneous(GTK_BOX(get()), homogeneous);
    }
    virtual void set_spacing(int spacing){
        gtk_box_set_spacing(GTK_BOX(get()), spacing);
    }
    virtual void set_baseline_position(GtkBaselinePosition position){
        gtk_box_set_baseline_position(GTK_BOX(get()), position);
    }
    virtual void set_baseline_child(int child){
        gtk_box_set_baseline_child(GTK_BOX(get()), child);
    }
    virtual gboolean get_homogeneous(){
        return gtk_box_get_homogeneous(GTK_BOX(get()));
    }
    virtual int get_spacing(){
        return gtk_box_get_spacing(GTK_BOX(get()));
    }
    virtual GtkBaselinePosition get_baseline_position(){
        return gtk_box_get_baseline_position(GTK_BOX(get()));
    }
    virtual int get_baseline_child(){
        return gtk_box_get_baseline_child(GTK_BOX(get()));
    }
};

}

#endif