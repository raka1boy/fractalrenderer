#pragma once
#include "stdafx.h"
#include <raylib.h>

class TextField {
private:
    size_t x;
    size_t y;
    size_t width;
    size_t height;
    std::string text;
public:
    TextField(size_t x, size_t y, size_t width, size_t height);
    void SetText(std::string s);
    void Draw();
};