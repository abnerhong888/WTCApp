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



    template<typename T>
    void object_release(T* obj){
        if(G_IS_OBJECT(obj)){
            INFO_LOG("release %s\n", g_type_name(G_OBJECT_TYPE(obj)));
            g_object_unref(obj);
        }
    }

    template<>
    void object_release(GtkWidget* obj){
        if(G_IS_OBJECT(obj)){
            INFO_LOG("release [%s], name = %s\n", g_type_name(G_OBJECT_TYPE(obj)), gtk_widget_get_name(obj));
            g_object_unref(obj);
        }
    }

    template<typename T>
    sptr<T> make_ptr(T* v){
        INFO_LOG("make ptr %s\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v);
    }

    template<typename T>
    sptr<T> make_ptr_no_release(T* v){
        INFO_LOG("make ptr from builder [%s]\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v, [](T* v){});
    }

    // make ptr by gtk object new
    template<typename T>
    sptr<T> make_ptr_release(T* v){
        INFO_LOG("make ptr release [%s]\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v, object_release<T>);
    }

    template<>
    sptr<GtkWidget> make_ptr_release(GtkWidget* v){
        INFO_LOG("make ptr release [%s], name = %s, %p\n", g_type_name(G_OBJECT_TYPE(v)), gtk_widget_get_name(v), v);
        return sptr<GtkWidget>(v, object_release<GtkWidget>);
    }
}


#endif