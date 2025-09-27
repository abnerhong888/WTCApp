
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

#include <gtk/gtk.h>
#include "gio/gio.h"
#include "glib-object.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DEBUG
#include "wtcResource.h"
#endif
#ifdef __cplusplus
}
#endif

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkBuilder *builder = gtk_builder_new ();
#ifdef DEBUG
    gtk_builder_add_from_file(builder, "/home/user/ws/mygit/WTCApp/WTCClient/resources/ui/main_window.ui", NULL);
#else
    gtk_builder_add_from_resource(builder, "/abner/wtc/resources/ui/main_window.ui", NULL);
#endif
    GObject *window = gtk_builder_get_object (builder, "main_window");

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
