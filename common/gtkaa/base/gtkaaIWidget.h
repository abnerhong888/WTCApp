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
    IWidget() = default;
    IWidget(std::string widgetName){
        m_widget_name = widgetName;
    }
    IWidget(GtkWidget* widget, std::string widgetName = ""){
        m_widget_name = widgetName;
        createWidget(widget);
    }
    IWidget(gtkaa::sptrGTKWidget widget, std::string widgetName = ""){
        m_widget_name = widgetName;
        m_widget = widget;
    }
    IWidget(IWidget& widget){
        m_widget = widget.m_widget;
        m_widget_name = widget.m_widget_name;
    }
    virtual gtkaa::sptrGTKWidget  createWidget(GtkWidget* widget){
        if(!m_widget_name.empty())
            gtk_widget_set_name(widget, m_widget_name.c_str());

        if(!m_widget) 
            m_widget = gtkaa::make_ptr_release(widget);

        return m_widget;
    }
    virtual gpointer get() { 
        return m_widget.get(); 
    }

    template<typename T>
    void operator=(T& widget){
        m_widget = widget.m_widget;
        m_widget_name = widget.m_widget_name;
    }
};


#define INHERIT_FROM_IWIDGET(CLASSNAME)\
public: \
    virtual ~CLASSNAME() = default; \
    CLASSNAME() = default; \
    CLASSNAME(std::string widgetName): IWidget(widgetName){} \
    CLASSNAME(GtkWidget* widget, std::string widgetName = ""): IWidget(widget, widgetName){}\
    CLASSNAME(gtkaa::sptrGTKWidget widget, std::string widgetName = ""): IWidget(widget, widgetName){}\
    CLASSNAME(IWidget& widget): IWidget(widget){}
}
#endif