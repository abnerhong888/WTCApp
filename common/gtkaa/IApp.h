#ifndef __IAPP_H__
#define __IAPP_H__

#include "ICommon.h"
#include "IEvent.h"
#include "IWindow.h"

namespace GTKAA_NAMESPACE{

class IApp: public IEvent
{
public:
    sptrGTKApp m_app = nullptr; 
    std::string m_app_id;
public:
    virtual ~IApp() = default;
    virtual gpointer get(){
        return m_app.get();
    }
    virtual int init(std::string app_id){
        m_app_id = app_id;
        GtkApplication* app = gtk_application_new(app_id.c_str(), G_APPLICATION_DEFAULT_FLAGS);

        m_app = make_ptr_release<GtkApplication>(app);
        return 0;
    }
    virtual int run(int argc, char **argv){
        return g_application_run(G_APPLICATION(m_app.get()), argc, argv);
    }
public:
    static void on_activate(GObject *obj, gpointer user_data){
        reinterpret_cast<IWindow*>(user_data)->activate(obj, user_data);
    }
};

}
#endif