#ifndef __gtkaaILEVELBAR_H__
#define __gtkaaILEVELBAR_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ILevelBar: public IWidget{
public:
    virtual ~ILevelBar() = default;
    ILevelBar(){ }
    ILevelBar(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_level_bar_new());
    }
};

}

#endif