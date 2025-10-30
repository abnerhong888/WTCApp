#ifndef __gtkaaIHeaderBar_H__
#define __gtkaaIHeaderBar_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IHeaderBar: public IWidget{
INHERIT_FROM_IWIDGET(IHeaderBar)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_header_bar_new());
    }
};

}

#endif