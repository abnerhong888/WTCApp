#ifndef __gtkaaIScrolledWindow_H__
#define __gtkaaIScrolledWindow_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IScrolledWindow: public IWidget{
INHERIT_FROM_IWIDGET(IScrolledWindow)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_scrolled_window_new());
    }
};

}

#endif