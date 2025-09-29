#ifndef __WTCAPP_H__
#define __WTCAPP_H__

#include "gtkaa/gtkaa.h"
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
        
        event_handler += {"activate", IApp::on_activate, &m_main_window};
        return 0;
    }
    
    int run(int argc, char **argv){
        return gtkaa::IApp::run(argc, argv);
    }
private:
    WTCWindow m_main_window{"main_window"};
};

#endif
