#ifndef __gtkaaIColumnView_H__
#define __gtkaaIColumnView_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IColumnView: public IWidget{
public:
    virtual ~IColumnView() = default;
    IColumnView(){ }
    IColumnView(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GtkSelectionModel *model){
        return createWidget(gtk_column_view_new(model));
    }
};

}

#endif