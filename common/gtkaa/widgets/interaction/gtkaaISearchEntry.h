#ifndef __gtkaaISearchEntry_H__
#define __gtkaaISearchEntry_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class ISearchEntry: public IWidget{
INHERIT_FROM_IWIDGET(ISearchEntry)
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_search_entry_new());
    }
};

}

#endif