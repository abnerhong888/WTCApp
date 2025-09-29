#ifndef __IWIDGET_H__
#define __IWIDGET_H__

#include "ICommon.h"
#include "IEvent.h"

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
    virtual gpointer get() { return m_widget.get(); }
    virtual gtkaa::sptrGTKWidget getWidget(){ return m_widget; }
};

}
#endif