#ifndef __IPANED_H__
#define __IPANED_H__

#include <gtkaa/base/ICommon.h>
#include <gtkaa/base/IWidget.h>

namespace GTKAA_NAMESPACE{

class IPaned: public IWidget{

public:
    virtual ~IPaned() = default;
    IPaned(){}
    IPaned(std::string widgetName): IWidget(widgetName){}
    virtual gpointer get(){
        return m_widget.get();
    }
public:
    virtual gtkaa::sptrGTKWidget create(GtkOrientation orientation){
        if(!m_widget)
            m_widget = gtkaa::make_ptr_release(gtk_paned_new(orientation));
        return m_widget;
    }
    void set_start_child(gtkaa::sptrGTKWidget child){
        gtk_paned_set_start_child(GTK_PANED(m_widget.get()), child.get());
    }
    void set_end_child(gtkaa::sptrGTKWidget child){
        gtk_paned_set_end_child(GTK_PANED(m_widget.get()), child.get());
    }
    void set_position(int position){
        gtk_paned_set_position(GTK_PANED(m_widget.get()), position);
    }
};

}

#endif
