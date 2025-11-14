#ifndef __gtkaaISpinner_H__
#define __gtkaaISpinner_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISpinner: public IWidget{
INHERIT_FROM(ISpinner, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_spinner_new());
    }
};

}

#endif