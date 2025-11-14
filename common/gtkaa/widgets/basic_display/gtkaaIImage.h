#ifndef __gtkaaIImage_H__
#define __gtkaaIImage_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IImage: public IWidget{
INHERIT_FROM(IImage, IWidget)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_image_new());
    }
};

}

#endif