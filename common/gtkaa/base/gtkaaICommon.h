#ifndef __gtkaaICommon_H__
#define __gtkaaICommon_H__

#include <gtk/gtk.h>

#include <string>
#include <memory>
#include <unordered_map>
#include <functional>

#define GTKAA_NAMESPACE gtkaa


namespace GTKAA_NAMESPACE{
    template<typename T>
    using sptr = std::shared_ptr<T>;

    #define INFO_LOG(fmt, ...) printf("[gtkaa] " fmt, ##__VA_ARGS__)

}



namespace GTKAA_NAMESPACE{
    
    using sptrGTKBuilder = sptr<GtkBuilder>;
    using sptrGTKCssProvider = sptr<GtkCssProvider>;
    using sptrGTKApp = sptr<GtkApplication>;
    using sptrGTKWidget = sptr<GtkWidget>;
    using sptrGTKEventController = sptr<GtkEventController>;



    template<typename T>
    void object_release(T* obj){
        if(G_IS_OBJECT(obj)){
            INFO_LOG("unref [%s], addr = %p\n", g_type_name(G_OBJECT_TYPE(obj)), obj);
            g_object_unref(obj);
        }
    }

    template<typename T>
    sptr<T> make_ptr(T* v){
        INFO_LOG("make ptr %s\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v);
    }

    template<typename T>
    sptr<T> make_ptr_no_unref(T* v){
        INFO_LOG("make ptr no unref [%s]\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v, [](T* v){});
    }

    template<>
    sptr<GtkWidget> make_ptr_no_unref(GtkWidget* v){
        INFO_LOG("make ptr widget [%s], name = %s, addr = %p\n", g_type_name(G_OBJECT_TYPE(v)), gtk_widget_get_name(v), v);
        return sptr<GtkWidget>(v, [](GtkWidget* v){});
    }

    // make ptr by gtk object new
    template<typename T>
    sptr<T> make_ptr_unref(T* v){
        INFO_LOG("make ptr unref [%s] addr = %p\n", g_type_name(G_OBJECT_TYPE(v)), v);
        return sptr<T>(v, object_release<T>);
    }

}


#endif