#ifndef __gtkaaIFLOWBOX_H__
#define __gtkaaIFLOWBOX_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFlowBox: public IWidget{

public:
    virtual ~IFlowBox() = default;
    IFlowBox(){}
    IFlowBox(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_flow_box_new());
    }
};

}

#endif