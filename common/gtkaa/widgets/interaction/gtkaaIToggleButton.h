#ifndef __gtkaaIToggleButton_H__
#define __gtkaaIToggleButton_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IToggleButton: public IWidget{
public:
    virtual ~IToggleButton() = default;
    IToggleButton(){ }
    IToggleButton(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_toggle_button_new());
    }
};

}

#endif