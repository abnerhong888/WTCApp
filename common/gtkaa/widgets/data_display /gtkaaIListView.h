#ifndef __gtkaaIListView_H__
#define __gtkaaIListView_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IListView: public IWidget{
public:
    virtual ~IListView() = default;
    IListView(){ }
    IListView(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GtkSelectionModel *model, GtkListItemFactory *factory){
        return createWidget(gtk_list_view_new(model, factory));
    }
};

}

#endif