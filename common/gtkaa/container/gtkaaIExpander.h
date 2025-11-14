#ifndef __gtkaaIExpander_H__
#define __gtkaaIExpander_H__

#include "gtkaa/base/gtkaaIWidget.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IExpander: public IWidget{
INHERIT_FROM(IExpander, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(std::string label){
        return createWidget(gtk_expander_new(label.c_str()));
    }
    virtual void set_child(IWidget* widget){
        gtk_expander_set_child(GTK_EXPANDER(get()), GTK_WIDGET(widget->get()));
    }
    virtual IWidget get_child(){
        return { gtk_expander_get_child(GTK_EXPANDER(get())) };
    }
    virtual void set_label(std::string label){
        gtk_expander_set_label(GTK_EXPANDER(get()), label.c_str());
    }
    virtual std::string get_label(){
        return gtk_expander_get_label(GTK_EXPANDER(get()));
    }
    virtual void set_use_underline(gboolean use_underline){
        gtk_expander_set_use_underline(GTK_EXPANDER(get()), use_underline);
    }
    virtual gboolean get_use_underline(){
        return gtk_expander_get_use_underline(GTK_EXPANDER(get()));
    }
    virtual void set_use_markup(gboolean use_markup){
        gtk_expander_set_use_markup(GTK_EXPANDER(get()), use_markup);
    }
    virtual gboolean get_use_markup(){
        return gtk_expander_get_use_markup(GTK_EXPANDER(get()));
    }
    virtual void set_resize_toplevel(gboolean resize_toplevel){
        gtk_expander_set_resize_toplevel(GTK_EXPANDER(get()), resize_toplevel);
    }
    virtual gboolean get_resize_toplevel(){
        return gtk_expander_get_resize_toplevel(GTK_EXPANDER(get()));
    }
    virtual void set_expanded(gboolean expanded){
        gtk_expander_set_expanded(GTK_EXPANDER(get()), expanded);
    }
    virtual gboolean get_expanded(){
        return gtk_expander_get_expanded(GTK_EXPANDER(get()));
    }
    virtual void set_label_widget(IWidget* widget){
        gtk_expander_set_label_widget(GTK_EXPANDER(get()), GTK_WIDGET(widget->get()));
    }
    virtual IWidget get_label_widget(){
        return { gtk_expander_get_label_widget(GTK_EXPANDER(get())) };
    }
    

};

}

#endif