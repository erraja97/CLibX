#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "gui.h"

void gui_init() {
    // Initialization code (can be expanded later)
}

void gui_create_window() {
    Display *d;
    Window w;
    XEvent e;
    int s;

    // Open connection to X server
    d = XOpenDisplay(NULL);
    if (d == NULL) {
        fprintf(stderr, "Cannot open display\n");
        exit(1);
    }

    s = DefaultScreen(d);

    // Create window
    w = XCreateSimpleWindow(d, RootWindow(d, s), 10, 10, 640, 480, 1, BlackPixel(d, s), WhitePixel(d, s));

    // Select kind of events we are interested in
    XSelectInput(d, w, ExposureMask | KeyPressMask);

    // Map (show) the window
    XMapWindow(d, w);

    // Event loop
    while (1) {
        XNextEvent(d, &e);
        if (e.type == Expose) {
            // Draw a rectangle in the window (for testing)
            XFillRectangle(d, w, DefaultGC(d, s), 20, 20, 100, 100);
        }
        if (e.type == KeyPress) {
            break; // Exit on key press
        }
    }

    // Close connection to X server
    XCloseDisplay(d);
}

