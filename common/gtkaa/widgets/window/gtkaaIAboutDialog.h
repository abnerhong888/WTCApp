#ifndef __gtkaaIAboutDialog_H__
#define __gtkaaIAboutDialog_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IAboutDialog: public IWidget{
INHERIT_FROM(IAboutDialog, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_about_dialog_new());
    }
};

}

#endif