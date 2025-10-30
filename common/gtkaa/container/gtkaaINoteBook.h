#ifndef __gtkaaINoteBook_H__
#define __gtkaaINoteBook_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class INoteBook: public IWidget{
INHERIT_FROM_IWIDGET(INoteBook)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_notebook_new());
    }
};

}

#endif