#ifndef __gtkaaIListBox_H__
#define __gtkaaIListBox_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IListBox: public IWidget{
INHERIT_FROM_IWIDGET(IListBox)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_list_box_new());
    }
};

}

#endif