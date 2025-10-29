#ifndef __gtkaaISEPARATOR_H__
#define __gtkaaISEPARATOR_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISeparator: public IWidget{
public:
    virtual ~ISeparator() = default;
    ISeparator(){ }
    ISeparator(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation){
        return createWidget(gtk_separator_new(orientation));
    }
};

}

#endif