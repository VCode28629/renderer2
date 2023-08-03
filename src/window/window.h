#pragma once

#include<string>
#include"matrix/matrix.h"

class Window {
private:
    std::string name;
    float *mat;
    size_t width;
    size_t height;
public:
    Window(std::string name, size_t width, size_t height);
    ~Window();
    void show();
    int waitKey(int t);
    // RGB [0~1]
    void setColor(int x, int y, Vec3f color);
    // RGB [0~255]
    void setColor(int x, int y, Vec3i color);
    // RGB [0~255]
    void setColor(int x, int y, Vec3uc color);
};
