#ifndef __ICSSPROVIDER_H__
#define __ICSSPROVIDER_H__

#include "ICommon.h"
#include "IEvent.h"

namespace GTKAA_NAMESPACE{

class ICssProvider: public IEvent{
public:
    gtkaa::sptrGTKCssProvider m_css_provider = nullptr;
public:
    ICssProvider(){
        m_css_provider = gtkaa::make_ptr_release(gtk_css_provider_new());
    }
    virtual ~ICssProvider() = default;
    virtual gpointer get(){
        return m_css_provider.get();
    }
public:
    virtual int load_from_path(std::string path){
        gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(this->get()), path.c_str());
        return 0;
    }
    virtual int load_from_resource(std::string path){
        gtk_css_provider_load_from_resource(GTK_CSS_PROVIDER(this->get()), path.c_str());
        return 0;
    }
    virtual void apply(GdkDisplay * display = nullptr){
        gtk_style_context_add_provider_for_display(
            display? display : gdk_display_get_default(), 
            GTK_STYLE_PROVIDER(m_css_provider.get()), 
            GTK_STYLE_PROVIDER_PRIORITY_USER
        );
    }
};

}
#endif