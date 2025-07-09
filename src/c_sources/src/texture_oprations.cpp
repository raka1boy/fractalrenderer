#include "texture_oprations.h"

void TextureOperations::SmoothTexture(size_t width, size_t height, size_t radius, uint8_t* pointer) {
    // 0 0
    for (size_t x = 0; x < radius; ++x) {
        for(size_t y = 0; y < radius; ++y) {
            if ((radius - x) * (radius - x) + (radius - y) * (radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }
    
    // height 0
    for (size_t x = height - radius - 1; x < height; ++x) {
        for(size_t y = 0; y < radius; ++y) {
            if ((height - radius - x) * (height - radius - x) + (radius - y) * (radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }

    // 0 width
    for (size_t x = 0; x < radius; ++x) {
        for(size_t y = width - radius - 1; y < width; ++y) {
            if ((radius - x) * (radius - x) + (width - radius - y) * (width - radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }

    // height width
    for (size_t x = height - radius - 1; x < height; ++x) {
        for(size_t y = width - radius - 1; y < width; ++y) {
            if ((height - radius - x) * (height - radius - x) + (width - radius - y) * (width - radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }
}

void TextureOperations::AddCounture(size_t width, size_t height, size_t radius, size_t thickness, uint8_t* pointer) {

    for (size_t x = 0; x < height; ++x) {
        for(size_t y = 0; y < thickness; ++y) {
            pointer[(x * width + y) * 4] = 0;
            pointer[(x * width + y) * 4 + 1] = 0;
            pointer[(x * width + y) * 4 + 2] = 0;
        }
    }
    // 0 0
    for (size_t x = 0; x < radius; ++x) {
        for(size_t y = 0; y < radius; ++y) {
            if ((radius - x) * (radius - x) + (radius - y) * (radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }
    
    // height 0
    for (size_t x = height - radius - 1; x < height; ++x) {
        for(size_t y = 0; y < radius; ++y) {
            if ((height - radius - x) * (height - radius - x) + (radius - y) * (radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }

    // 0 width
    for (size_t x = 0; x < radius; ++x) {
        for(size_t y = width - radius - 1; y < width; ++y) {
            if ((radius - x) * (radius - x) + (width - radius - y) * (width - radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }

    // height width
    for (size_t x = height - radius - 1; x < height; ++x) {
        for(size_t y = width - radius - 1; y < width; ++y) {
            if ((height - radius - x) * (height - radius - x) + (width - radius - y) * (width - radius - y) >= radius * radius) {
                pointer[(x * width + y) * 4 + 3] = 0;
            }
        }
    }
}