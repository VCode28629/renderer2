#include"window.h"
#include<cstring>
#include<opencv2/opencv.hpp>

Window::Window(std::string name, size_t width, size_t height) : name(name), width(width), height(height) {
    mat = new float[width * height * 3];
    memset(mat, 0, sizeof(float) * width * height * 3);
}

Window::~Window() {
    delete[] mat;
}

void Window::show() {
    auto src = cv::Mat(height, width, CV_32FC3, mat);
    cv::Mat dst;
    cv::flip(src, dst, 0);
    cv::imshow(name, dst);
}

int Window::waitKey(int t) {
    return cv::waitKey(t);
}

void Window::setColor(int x, int y, Vec3f color) {
    mat[(y * width + x) * 3] = color.z;
    mat[(y * width + x) * 3 + 1] = color.y;
    mat[(y * width + x) * 3 + 2] = color.x;
}

void Window::setColor(int x, int y, Vec3i color) {
    mat[(y * width + x) * 3] = color.z / 255.0f;
    mat[(y * width + x) * 3 + 1] = color.y / 255.0f;
    mat[(y * width + x) * 3 + 2] = color.x / 255.0f;
}

void Window::setColor(int x, int y, Vec3uc color) {
    mat[(y * width + x) * 3] = color.z / 255.0f;
    mat[(y * width + x) * 3 + 1] = color.y / 255.0f;
    mat[(y * width + x) * 3 + 2] = color.x / 255.0f;
}
