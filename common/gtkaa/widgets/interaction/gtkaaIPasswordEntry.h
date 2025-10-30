#ifndef __gtkaaIPasswordEntry_H__
#define __gtkaaIPasswordEntry_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPasswordEntry: public IWidget{
INHERIT_FROM_IWIDGET(IPasswordEntry)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_password_entry_new());
    }
};

}

#endif