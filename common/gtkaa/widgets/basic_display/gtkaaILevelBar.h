#ifndef __gtkaaILevelBar_H__
#define __gtkaaILevelBar_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ILevelBar: public IWidget{
INHERIT_FROM_IWIDGET(ILevelBar)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_level_bar_new());
    }
};

}

#endif