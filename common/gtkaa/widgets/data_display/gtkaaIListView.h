#ifndef __gtkaaIListView_H__
#define __gtkaaIListView_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IListView: public IWidget{
INHERIT_FROM_IWIDGET(IListView)
public:
    virtual gtkaa::sptrGTKWidget create(GtkSelectionModel *model, GtkListItemFactory *factory){
        return createWidget(gtk_list_view_new(model, factory));
    }
};

}

#endif