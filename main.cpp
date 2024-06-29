#include "raylib.h"
#include <iostream>
#include <cstdlib>

int main(int argc, char **argv) {
    unsigned char darkness = 128;
    int monitor = 0;
    int width = 1920;
    int height = 1080;

    if (argc == 5) {
        darkness = static_cast<unsigned char>(std::atoi(argv[1]));
        monitor = std::atoi(argv[2]);
        width = std::atoi(argv[3]);
        height = std::atoi(argv[4]);
    } else if (argc == 1) {
        std::cout << "Enter brightness (0-255): ";
        std::cin >> darkness;
        std::cout << "Enter monitor number: ";
        std::cin >> monitor;
        std::cout << "Enter width: ";
        std::cin >> width;
        std::cout << "Enter height: ";
        std::cin >> height;
    } else {
        std::cerr << "Usage: " << argv[0] << " <brightness> <monitor_number> <width> <height>\n"
                  << "Example: 128 0 1920 1080 for a fullscreen darkener\n"
                  << "<brightness> 0-255, 0 is nothing, 255 is black\n";
        return 1;
    }

    SetConfigFlags(FLAG_WINDOW_MOUSE_PASSTHROUGH | FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
    InitWindow(width, height, "Darker Darker");
    SetTargetFPS(5);
    SetExitKey(KEY_ESCAPE);
    SetWindowMonitor(monitor);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({0, 0, 0, darkness});
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
