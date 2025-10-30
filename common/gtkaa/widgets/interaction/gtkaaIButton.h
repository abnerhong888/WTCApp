#ifndef __gtkaaIButton_H__
#define __gtkaaIButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IButton: public IWidget{
INHERIT_FROM_IWIDGET(IButton)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_button_new());
    }
};

}

#endif