#ifndef __IGRID_H__
#define __IGRID_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h>

namespace GTKAA_NAMESPACE{

class IGrid: public IWidget{

public:
    virtual ~IGrid() = default;
    IGrid(){}
    IGrid(std::string widgetName): IWidget(widgetName){}
public:
    virtual gtkaa::sptrGTKWidget create(){
        return createWidget(gtk_stack_new());
    }

    virtual void attach(IWidget* widget, int column, int row, int width, int height){
        gtk_grid_attach(GTK_GRID(get()), GTK_WIDGET(widget->get()), column, row, width, height);
    }
};

}

#endif