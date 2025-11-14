#ifndef __gtkaaIMenuButton_H__
#define __gtkaaIMenuButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IMenuButton: public IWidget{
INHERIT_FROM(IMenuButton, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_menu_button_new());
    }
};

}

#endif