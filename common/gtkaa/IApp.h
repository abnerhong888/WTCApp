#ifndef __IAPP_H__
#define __IAPP_H__

#include "ICommon.h"

namespace GTKAA_NAMESPACE{

class IApp
{
public:
    virtual ~IApp() = default;
    virtual int init(std::string app_id, GCallback callback, gpointer user_data){
        m_app_id = app_id;
        GtkApplication* app = gtk_application_new(app_id.c_str(), G_APPLICATION_DEFAULT_FLAGS);

        m_app = make_ptr_release<GtkApplication>(app);

        g_signal_connect(m_app.get(), "activate", callback, user_data);
        return 0;
    }
    virtual int run(int argc, char **argv){
        return g_application_run(G_APPLICATION(m_app.get()), argc, argv);
    }

    sptrGTKApp m_app = nullptr; 
    std::string m_app_id;
};

}
#endif