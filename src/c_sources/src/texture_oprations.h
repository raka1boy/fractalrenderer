#pragma once
#include "stdafx.h"

class TextureOperations {
    public:
    static void SmoothTexture(size_t width, size_t height, size_t radius, uint8_t* pointer);
    static void AddCounture(size_t width, size_t height, size_t radius, size_t thickness, uint8_t* pointer);
};