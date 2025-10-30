#ifndef __gtkaaITextView_H__
#define __gtkaaITextView_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ITextView: public IWidget{
INHERIT_FROM_IWIDGET(ITextView)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_text_view_new());
    }
};

}

#endif