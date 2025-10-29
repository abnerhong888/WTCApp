#ifndef __gtkaaISpinButton_H__
#define __gtkaaISpinButton_H__

#include "gtk/gtk.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISpinButton: public IWidget{
public:
    virtual ~ISpinButton() = default;
    ISpinButton(){ }
    ISpinButton(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(double min, double max, double step){
        return createWidget(gtk_spin_button_new_with_range(min, max, step));
    }
};

}

#endif