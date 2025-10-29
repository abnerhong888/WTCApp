#ifndef __gtkaaIPopoverMenu_H__
#define __gtkaaIPopoverMenu_H__

#include "gtk/gtk.h"
#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IPopoverMenu: public IWidget{
public:
    virtual ~IPopoverMenu() = default;
    IPopoverMenu(){ }
    IPopoverMenu(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(GMenuModel *model){
        return createWidget(gtk_popover_menu_new_from_model(model));
    }
};

}

#endif