#ifndef __gtkaaISeparator_H__
#define __gtkaaISeparator_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISeparator: public IWidget{
INHERIT_FROM(ISeparator, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation){
        return createWidget(gtk_separator_new(orientation));
    }
};

}

#endif