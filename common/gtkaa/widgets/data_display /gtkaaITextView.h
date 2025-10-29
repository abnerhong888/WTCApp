#ifndef __gtkaaITextView_H__
#define __gtkaaITextView_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ITextView: public IWidget{
public:
    virtual ~ITextView() = default;
    ITextView(){ }
    ITextView(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_text_view_new());
    }
};

}

#endif