#ifndef __gtkaaISwitch_H__
#define __gtkaaISwitch_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISwitch: public IWidget{
INHERIT_FROM(ISwitch, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_switch_new());
    }
};

}

#endif