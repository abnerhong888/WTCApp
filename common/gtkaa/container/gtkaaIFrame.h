#ifndef __gtkaaIFrame_H__
#define __gtkaaIFrame_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFrame: public IWidget{

public:
    virtual ~IFrame() = default;
    IFrame(){}
    IFrame(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(std::string label){
        return createWidget(gtk_frame_new(label.c_str()));
    }
};

}

#endif