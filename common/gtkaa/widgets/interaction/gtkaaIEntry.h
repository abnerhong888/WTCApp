#ifndef __gtkaaIEntry_H__
#define __gtkaaIEntry_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IEntry: public IWidget{
INHERIT_FROM(IEntry, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_entry_new());
    }
};

}

#endif