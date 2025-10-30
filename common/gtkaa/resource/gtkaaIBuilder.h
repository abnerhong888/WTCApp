#ifndef __gtkaaIBuilder_H__
#define __gtkaaIBuilder_H__

#include <gtkaa/base/gtkaabase.h>

namespace GTKAA_NAMESPACE{

class IBuilder: public IEvent{
public:
    gtkaa::sptrGTKBuilder m_builder = nullptr;
    GError* error = NULL;
public:
    IBuilder(){
        m_builder = gtkaa::make_ptr_release(gtk_builder_new());
    }
    virtual ~IBuilder() = default;
    virtual gpointer get(){
        return m_builder.get();
    }
public:
    virtual int load_from_file(std::string path){
        if(!gtk_builder_add_from_file(GTK_BUILDER(get()), path.c_str(), &error)){
            INFO_LOG("Failed to load ui file: %s", error->message);
            g_error_free(error);
            return -1;
        }

        return 0;
    }
    virtual int load_from_resource(std::string path){
        if(!gtk_builder_add_from_resource(GTK_BUILDER(get()), path.c_str(), &error)){
            INFO_LOG("Failed to load ui file: %s", error->message);
            g_error_free(error);
            return -1;
        }

        return 0;
    }

    template<typename T>
    sptr<T> get_object(std::string name){

        // m_window = gtkaa::make_ptr_from_builder(
        //     GTK_WINDOW( gtk_builder_get_object(m_builder.get(), "main_window") )
        // );
        
        return gtkaa::make_ptr_from_builder(
            (T*)gtk_builder_get_object(GTK_BUILDER(get()), name.c_str())
        );
    }
};

}
#endif