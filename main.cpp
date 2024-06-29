#include "raylib.h"

int main(void) {
    SetConfigFlags(FLAG_WINDOW_MOUSE_PASSTHROUGH | FLAG_WINDOW_TRANSPARENT | FLAG_WINDOW_UNDECORATED);
    InitWindow(GetScreenWidth(), GetScreenHeight(), "Darker Darker");
    //SetWindowState(FLAG_WINDOW_TOPMOST | FLAG_WINDOW_MAXIMIZED);
    SetTargetFPS(5);
    SetExitKey(KEY_ESCAPE);
    
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground( {0, 0, 0, 128} );

        EndDrawing();
    }

    CloseWindow();
    return 0;
}