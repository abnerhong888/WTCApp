#ifndef __gtkaaILinkButton_H__
#define __gtkaaILinkButton_H__

#include "gtk/gtk.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ILinkButton: public IWidget{
INHERIT_FROM(ILinkButton, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(std::string uri){
        return createWidget(gtk_link_button_new(uri.c_str()));
    }
};

}

#endif