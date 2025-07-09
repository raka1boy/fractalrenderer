#include "ui_progress_bar.h"
ProgressBar::ProgressBar(size_t w, size_t h) : width(w), height(h) {};

void ProgressBar::draw(int x, int y) {
    Rectangle main_field{
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(width),
        static_cast<float> (height)
    };

    Rectangle main_field_line{
        static_cast<float>(x + 1),
        static_cast<float>(y + 1),
        static_cast<float>(width - 1),
        static_cast<float> (height - 1)
    };

    
    Rectangle sub_field{
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(width) * value < static_cast<float> (height) ? static_cast<float>(width) : static_cast<float>(width) * value,
        static_cast<float> (height)
    };

    DrawRectangleRounded(main_field, 0.9f, 0, Fade(WHITE, 0.9f));
    DrawRectangleRounded(sub_field, 0.9f, 0, Fade(BLACK, 0.8f));
    DrawRectangleRoundedLinesEx(main_field_line, 0.9f, 0, 2, Fade(BLACK, 1.0f));
}

void ProgressBar::setValuse(float v) {
    value = v;
}