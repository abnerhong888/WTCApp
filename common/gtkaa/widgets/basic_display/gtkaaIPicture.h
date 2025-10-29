#ifndef __gtkaaIPicture_H__
#define __gtkaaIPicture_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPicture: public IWidget{
public:
    virtual ~IPicture() = default;
    IPicture(){ }
    IPicture(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_picture_new());
    }
};

}

#endif