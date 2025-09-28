#ifndef __WTCAPP_H__
#define __WTCAPP_H__

#include "gtkaa/gtkaa.h"
#include "wtcWindow.h"

class WTCApp : public gtkaa::IApp{
public:
    
    WTCApp(){ }
    ~WTCApp(){ }

    using gtkaa::IApp::init; // expose base overload to avoid hiding warning
    int init(){
        m_main_window.init();
        if(gtkaa::IApp::init("abner.wtc", G_CALLBACK(m_main_window.on_activate), &m_main_window)){
            return -1;
        }

        return 0;
    }
    
    int run(int argc, char **argv){
        return gtkaa::IApp::run(argc, argv);
    }
private:
    WTCWindow m_main_window;
};

#endif
