#ifndef __gtkaaIPopover_H__
#define __gtkaaIPopover_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPopover: public IWidget{
INHERIT_FROM_IWIDGET(IPopover)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_popover_new());
    }
};

}

#endif