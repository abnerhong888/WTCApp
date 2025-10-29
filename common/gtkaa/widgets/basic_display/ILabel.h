#ifndef __ILABEL_H__
#define __ILABEL_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h> 

namespace GTKAA_NAMESPACE{

class ILabel: public IWidget{
public:
    virtual ~ILabel() = default;
    ILabel(){ }
    ILabel(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(std::string label_string){
        return createWidget(gtk_label_new(label_string.c_str()));
    }
};

}

#endif