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
    virtual gpointer get(){
        return m_widget.get();
    }
    virtual gtkaa::sptrGTKWidget create(std::string label_string){
        if(!m_widget)
            m_widget = gtkaa::make_ptr_release(gtk_label_new(label_string.c_str()));
        return m_widget;
    }
};

}

#endif