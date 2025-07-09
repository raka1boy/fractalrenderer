#pragma once
#include <raylib.h>
#include "stdafx.h"
#include "raygui.h" 
class ProgressBar {
    private: 
    size_t width = 50;
    size_t height = 10;
    float value = 0.0f;
    public:
    void draw(int x, int y);
    void setValuse(float v);
    ProgressBar(size_t w, size_t h);
};