#ifndef __WTCCOMMON_H__
#define __WTCCOMMON_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEBUG
    #include "wtcResource.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef DEBUG
    #define MAIN_WINDOW_UI "/home/user/ws/mygit/WTCApp/WTCClient/resources/ui/main_window.ui"
    #define MAIN_WINDOW_CSS "/home/user/ws/mygit/WTCApp/WTCClient/resources/css/style.css"
#else
    #define MAIN_WINDOW_UI "/abner/wtc/resources/ui/main_window.ui"
    #define MAIN_WINDOW_CSS "/abner/wtc/resources/css/style.css"
#endif

#ifdef DEBUG
    #define BUILDER_LOAD(builder, path) builder.load_from_file(path)
    #define CSS_LOAD(cssProvider, path) cssProvider.load_from_path(path)
#else
    #define BUILDER_LOAD(builder, path) builder.load_from_resource(path)
    #define CSS_LOAD(cssProvider, path) cssProvider.load_from_resource(path)
#endif

#endif