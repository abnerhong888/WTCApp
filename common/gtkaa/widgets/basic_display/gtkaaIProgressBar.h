#ifndef __gtkaaIProgressBar_H__
#define __gtkaaIProgressBar_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IProgressbar: public IWidget{
INHERIT_FROM_IWIDGET(IProgressbar)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_progress_bar_new());
    }
};

}

#endif