#pragma once
#include <raylib.h>
#include "stdafx.h"
#include "texture_oprations.h"
class ShadowEffect {
    private:
        size_t x;
        size_t y;
        size_t width;
        size_t height;
        std::shared_ptr<Texture2D> shadow = nullptr;
    public:
        ShadowEffect(size_t x, size_t y, size_t width, size_t height, float roundness, size_t iterations);
        void Draw();

};