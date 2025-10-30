#ifndef __gtkaaILabel_H__
#define __gtkaaILabel_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ILabel: public IWidget{
INHERIT_FROM_IWIDGET(ILabel)
public:
    virtual gtkaa::sptrGTKWidget create(std::string label_string){
        return createWidget(gtk_label_new(label_string.c_str()));
    }
};

}

#endif