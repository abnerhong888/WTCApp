#ifndef __gtkaaIAboutDialog_H__
#define __gtkaaIAboutDialog_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IAboutDialog: public IWidget{
public:
    virtual ~IAboutDialog() = default;
    IAboutDialog(){ }
    IAboutDialog(std::string widgetName): IWidget(widgetName){}
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_about_dialog_new());
    }
};

}

#endif