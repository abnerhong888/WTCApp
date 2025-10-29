#ifndef __gtkaaIWidget_H__
#define __gtkaaIWidget_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IWidget: public IEvent{
public:
    gtkaa::sptrGTKWidget m_widget = nullptr;
    std::string m_widget_name = "";
public:
    virtual ~IWidget() = default;
    IWidget(){ }
    IWidget(std::string widgetName){
        m_widget_name = widgetName;
    }
    virtual gtkaa::sptrGTKWidget  createWidget(GtkWidget* widget){
        if(!m_widget) 
            m_widget = gtkaa::make_ptr_release(widget);

        if(!m_widget_name.empty())
            gtk_widget_set_name(GTK_WIDGET(m_widget.get()), m_widget_name.c_str());

        return m_widget;
    }
    virtual gpointer get() { return m_widget.get(); }
};

}
#endif