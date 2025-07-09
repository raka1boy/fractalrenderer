#pragma once
#include "stdafx.h"
#include <raylib.h>

class Button {
private:
    size_t x;
    size_t y;
    size_t width;
    size_t height;
    std::function<void(void)> binding;
    enum State {
        DEFAULT,
        COVERED, 
        PRESSED
    } state;
    const char* text;
public:
    Button(size_t x, size_t y, size_t width, size_t height, std::function<void(void)> f, const char* text);
    void Update();
    void Draw();
};