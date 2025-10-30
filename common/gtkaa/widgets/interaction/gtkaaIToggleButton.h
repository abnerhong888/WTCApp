#ifndef __gtkaaIToggleButton_H__
#define __gtkaaIToggleButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IToggleButton: public IWidget{
INHERIT_FROM_IWIDGET(IToggleButton)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_toggle_button_new());
    }
};

}

#endif