#ifndef __WTCAPP_H__
#define __WTCAPP_H__

#include <gtkaa/gtkaa.h>
#include "wtcWindow.h"

class WTCApp : public gtkaa::IApp{
public:
    
    WTCApp(): gtkaa::IApp(""){
    }
    WTCApp(std::string app_id): gtkaa::IApp(app_id){
    }
    ~WTCApp(){ }

    int init(){
        this->event += gtkaa::g_event("activate", &WTCApp::on_activate, this);
        return 0;
    }
    
    int run(int argc, char **argv){
        return gtkaa::IApp::run(argc, argv);
    }
public:
    void on_activate(){
        m_main_window.on_activate(G_OBJECT(get()), this);
    }
private:
    WTCWindow m_main_window{"main_window"};
};

#endif
