#ifndef __gtkaaISPINNER_H__
#define __gtkaaISPINNER_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISpinner: public IWidget{
public:
    virtual ~ISpinner() = default;
    ISpinner(){ }
    ISpinner(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_spinner_new());
    }
};

}

#endif