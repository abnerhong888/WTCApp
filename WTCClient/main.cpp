
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

#include <gtk/gtk.h>
#include "gio/gio.h"
#include "glib-object.h"
#include "glib.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEBUG
#include "wtcResource.h"
#endif
#ifdef __cplusplus
}
#endif

static void on_paned_position_changed(GtkPaned *paned, gpointer user_data) {
    gtk_paned_set_position(paned, 200);
    g_print("Paned position changed to %d\n", gtk_paned_get_position(paned));
}

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new ();
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    GError* error = NULL;
#ifdef DEBUG
    gtk_builder_add_from_file(builder, "/home/user/ws/mygit/WTCApp/WTCClient/resources/ui/main_window.ui", &error);
    gtk_css_provider_load_from_path(cssProvider, "/home/user/ws/mygit/WTCApp/WTCClient/resources/css/style.css");
#else
    gtk_builder_add_from_resource(builder, "/abner/wtc/resources/ui/main_window.ui", &error);
    gtk_css_provider_load_from_resource(cssProvider, "/abner/wtc/resources/css/style.css");
#endif

    if(error){
        g_error("Failed to load ui file: %s", error->message);
        g_error_free(error);
        return;
    }

    gtk_style_context_add_provider_for_display(gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
    GObject *window = gtk_builder_get_object (builder, "main_window");

    GtkPaned *paned = GTK_PANED(gtk_builder_get_object(builder, "horizontal_paned"));

    glong signalId = g_signal_connect(paned, "notify::position", G_CALLBACK(on_paned_position_changed), NULL);
    g_print("signalId: %ld\n", signalId);
    //g_signal_handler_block(paned, signalId);

    gtk_window_set_application (GTK_WINDOW (window), app);
    gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv){	
	GtkApplication *app = gtk_application_new("abner.wtc", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
// 	wtc::UDPClient client;
// 	int cnt = 0;
// 	while(1){
// 		client.send(cnt);
// 		++cnt;
// 		au::sleep_ms(1000);
// 	}
// 	return 0;
}
