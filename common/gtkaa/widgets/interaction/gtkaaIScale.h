#ifndef __gtkaaIScale_H__
#define __gtkaaIScale_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IScale: public IWidget{
public:
    virtual ~IScale() = default;
    IScale(){ }
    IScale(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation, double min, double max, double step){
        return createWidget(gtk_scale_new_with_range(orientation, min, max, step));
    }
};

}

#endif