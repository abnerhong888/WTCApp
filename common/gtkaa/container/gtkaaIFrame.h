#ifndef __gtkaaIFrame_H__
#define __gtkaaIFrame_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFrame: public IWidget{
INHERIT_FROM(IFrame, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(std::string label){
        return createWidget(gtk_frame_new(label.c_str()));
    }
    virtual void set_label(IFrame* frame, std::string label){
        gtk_frame_set_label(GTK_FRAME(frame->get()), label.c_str());
    }
    virtual void set_label_widget(IFrame* frame, IWidget* label_widget){
        gtk_frame_set_label_widget(GTK_FRAME(frame->get()), GTK_WIDGET(label_widget->get()));
    }
    virtual void set_label_align(IFrame* frame, float xalign){
        gtk_frame_set_label_align(GTK_FRAME(frame->get()), xalign);
    }
    virtual void set_child(IFrame* frame, IWidget* child){
        gtk_frame_set_child(GTK_FRAME(frame->get()), GTK_WIDGET(child->get()));
    }
    virtual std::string get_label(IFrame* frame){
        return gtk_frame_get_label(GTK_FRAME(frame->get()));
    }
    virtual IWidget get_label_widget(IFrame* frame){
        return { gtk_frame_get_label_widget(GTK_FRAME(frame->get())) };
    }
    virtual float get_label_align(IFrame* frame){
        return gtk_frame_get_label_align(GTK_FRAME(frame->get()));
    }
    virtual IWidget get_child(IFrame* frame){
        return { gtk_frame_get_child(GTK_FRAME(frame->get())) };
    }
};

}

#endif