#ifndef __WTCAPP_H__
#define __WTCAPP_H__

#include <gtkaa/gtkaa.h>
#include "wtcWindow.h"
#include <csignal>

class WTCApp : public gtkaa::IApp{
public:
    
    WTCApp(){ 
        
    }
    ~WTCApp(){ }

    using gtkaa::IApp::init; // expose base overload to avoid hiding warning
    int init(){
        if(gtkaa::IApp::init("abner.wtc")){
            return -1;
        }
        
        event_handler += gtkaa::signal("activate", &WTCApp::on_activate, this);
        return 0;
    }
    
    int run(int argc, char **argv){
        return gtkaa::IApp::run(argc, argv);
    }
public:
    void on_activate(){
        m_main_window.activate(G_OBJECT(get()), this);
    }
private:
    WTCWindow m_main_window{"main_window"};
};

#endif
