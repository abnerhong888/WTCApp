#ifndef __gtkaaIApp_H__
#define __gtkaaIApp_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IApp: public IEvent
{
public:
    sptrGTKApp m_app = nullptr; 
    std::string m_app_id;
public:
    virtual ~IApp() = default;
    IApp() = default;
    IApp(std::string app_id){
        createApp(app_id);
    }
    virtual gpointer get(){
        return m_app.get();
    }
    virtual int createApp(std::string app_id){
        m_app_id = app_id;
        GtkApplication* app = gtk_application_new(app_id.c_str(), G_APPLICATION_DEFAULT_FLAGS);

        m_app = make_ptr_release<GtkApplication>(app);
        return 0;
    }
    virtual int run(int argc, char **argv){
        return g_application_run(G_APPLICATION(m_app.get()), argc, argv);
    }
};

}
#endif