#ifndef __gtkaaIScrolledWindow_H__
#define __gtkaaIScrolledWindow_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IScrolledWindow: public IWidget{

public:
    virtual ~IScrolledWindow() = default;
    IScrolledWindow(){}
    IScrolledWindow(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_scrolled_window_new());
    }
};

}

#endif