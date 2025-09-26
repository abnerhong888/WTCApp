
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

#include <gtk/gtk.h>

static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "wtc");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);
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
