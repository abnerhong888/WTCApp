#ifndef __gtkaaIFrame_H__
#define __gtkaaIFrame_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IFrame: public IWidget{
INHERIT_FROM_IWIDGET(IFrame)
public:
    virtual gtkaa::sptrGTKWidget create(std::string label){
        return createWidget(gtk_frame_new(label.c_str()));
    }
};

}

#endif