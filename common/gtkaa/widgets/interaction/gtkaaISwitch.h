#ifndef __gtkaaISwitch_H__
#define __gtkaaISwitch_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISwitch: public IWidget{
public:
    virtual ~ISwitch() = default;
    ISwitch(){ }
    ISwitch(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_switch_new());
    }
};

}

#endif