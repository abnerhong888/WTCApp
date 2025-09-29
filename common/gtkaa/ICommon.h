#ifndef __ICOMMON_H__
#define __ICOMMON_H__

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

    
    typedef void  (*EventCallback) (GObject*, gpointer);

    struct EventData{
        EventCallback callback;
        std::string signal_name;
        gpointer user_data;

        EventData(std::string signal_name, EventCallback callback, gpointer user_data){
            this->callback = callback;
            this->signal_name = signal_name;
            this->user_data = user_data;
        }
    };
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

    template<typename T>
    sptr<T> make_ptr(T* v){
        INFO_LOG("make ptr %s\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v);
    }

    // make ptr from gtk builder, no need to release
    template<typename T>
    sptr<T> make_ptr_from_builder(T* v){
        INFO_LOG("make ptr from builder %s\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v, [](T* v){});
    }

    // make ptr by gtk object new
    template<typename T>
    sptr<T> make_ptr_release(T* v){
        INFO_LOG("make ptr release %s\n", g_type_name(G_OBJECT_TYPE(v)));
        return sptr<T>(v, object_release<T>);
    }

}


#endif