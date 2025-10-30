#ifndef __gtkaaICheckButton_H__
#define __gtkaaICheckButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ICheckButton: public IWidget{
INHERIT_FROM_IWIDGET(ICheckButton)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_check_button_new());
    }
};

}

#endif