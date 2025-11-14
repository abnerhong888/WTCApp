#ifndef __gtkaaIButton_H__
#define __gtkaaIButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IButton: public IWidget{
INHERIT_FROM(IButton, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(std::string label = ""){
        if(!label.empty())
            return createWidget(gtk_button_new_with_label(label.c_str()));
        return createWidget(gtk_button_new());
    }
    virtual void set_label(std::string label){
        gtk_button_set_label(GTK_BUTTON(get()), label.c_str());
    }
    virtual void set_use_underline(gboolean use_underline){
        gtk_button_set_use_underline(GTK_BUTTON(get()), use_underline);
    }
    virtual void set_icon_name(const char *icon_name){
        gtk_button_set_icon_name(GTK_BUTTON(get()), icon_name);
    }
    virtual void set_child(IWidget *child){
        gtk_button_set_child(GTK_BUTTON(get()), GTK_WIDGET(child->get()));
    }
    virtual IWidget get_child(){
        return { gtk_button_get_child(GTK_BUTTON(get())) };
    }
    virtual void set_can_shrink(gboolean can_shrink){
        gtk_button_set_can_shrink(GTK_BUTTON(get()), can_shrink);
    }
    virtual gboolean get_can_shrink(){
        return gtk_button_get_can_shrink(GTK_BUTTON(get()));
    }
    virtual void set_has_frame(gboolean has_frame){
        gtk_button_set_has_frame(GTK_BUTTON(get()), has_frame);
    }
    virtual gboolean get_has_frame(){
        return gtk_button_get_has_frame(GTK_BUTTON(get()));
    }
};

}

#endif