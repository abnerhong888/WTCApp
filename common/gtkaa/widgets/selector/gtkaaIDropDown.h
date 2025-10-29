#ifndef __gtkaaIDropDown_H__
#define __gtkaaIDropDown_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IDropDown: public IWidget{
public:
    virtual ~IDropDown() = default;
    IDropDown(){ }
    IDropDown(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GListModel *model, GtkExpression *expression){
        return createWidget(gtk_drop_down_new(model, expression));
    }
};

}

#endif