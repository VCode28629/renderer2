#include<window/window.h>

int main() {
    Window win("window", 800, 600);
    for(int i = 0; i < 400; ++i) {
        for(int j = 0; j < 300; ++j) {
            win.setColor(i, j, Vec3f(1.0, 0.0, 0.0));
        }
    }
    for(int i = 400; i < 800; ++i) {
        for(int j = 300; j < 600; ++j) {
            win.setColor(i, j, Vec3i(0, 255, 0));
        }
    }
    while(true) {
        win.show();
        int key = win.waitKey(0);
        if(key == 27) break;
    }
    return 0;
}
