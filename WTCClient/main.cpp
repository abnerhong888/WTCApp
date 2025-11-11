
#include <stdlib.h>
#include <stdio.h>

#include "UDPClient.h"

#include "gtk/gtk.h"
#include "wtc/wtcApp.h"

int main(int argc, char **argv){	
    WTCApp app("abner.wtc");
    if(app.init() != 0){
        return -1;
    }
    return app.run(argc, argv);
}

// static void on_button_clicked(GtkButton *button, gpointer user_data) {
//     GtkWidget *popover = GTK_WIDGET(user_data);
//     gtk_popover_popup(GTK_POPOVER(popover));
// }

// static void activate(GtkApplication *app, gpointer user_data) {
//     GtkWidget *window;
//     GtkWidget *button;
//     GtkWidget *popover;
//     GtkWidget *label;

//     window = gtk_application_window_new(app);
//     gtk_window_set_title(GTK_WINDOW(window), "Popover Example");
//     gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

//     button = gtk_button_new_with_label("Show Popover");
//     gtk_window_set_child(GTK_WINDOW(window), button);

//     // Create the popover
//     popover = gtk_popover_new();
//     gtk_widget_set_parent(GTK_WIDGET(popover), button); // Attach to the button
//     // Add content to the popover
//     label = gtk_label_new("Hello from the Popover!");
//     gtk_popover_set_child(GTK_POPOVER(popover), label);

//     // Connect the button click signal to show the popover
//     g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), popover);

//     gtk_window_present(GTK_WINDOW(window));
// }

// int main(int argc, char **argv) {
//     GtkApplication *app;
//     int status;

//     app = gtk_application_new("org.gtk.example.Popover", G_APPLICATION_DEFAULT_FLAGS);
//     g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
//     status = g_application_run(G_APPLICATION(app), argc, argv);
//     g_object_unref(app);

//     return status;
// }