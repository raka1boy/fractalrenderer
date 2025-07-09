#include "ui_button.h"

namespace {
    Color DEFAULT_c = {255, 255, 255, 255};
    Color COVERED_c = {128, 128, 128, 255};
    Color PRESSED_c = {50, 50, 50, 255};
}
Button::Button(size_t x, size_t y, size_t width, size_t height, std::function<void(void)> f, const char* text) : 
    x(x),
    y(y), 
    width(width), 
    height(height), 
    binding(f),
    state(State::DEFAULT),
    text(text) {};

void Button::Draw() {
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

    Color background_color;
    switch (state)
    {
    case State::DEFAULT:
        background_color = DEFAULT_c;
        break;
    case State::COVERED:
        background_color = COVERED_c;
        break;   
    case State::PRESSED:
        background_color = PRESSED_c;
        break;
    }

    DrawRectangleRounded(main_field, 0.9f, 0, Fade(background_color, 0.9f));
    DrawText(text, x + 15, y + 5, 20, BLACK);
    DrawRectangleRoundedLinesEx(main_field_line, 0.9f, 0, 2, Fade(BLACK, 1.0f));

}

void Button::Update() {
    bool mouse_on_button = CheckCollisionPointRec(GetMousePosition(), Rectangle{
        static_cast<float>(x),
        static_cast<float>(y),
        static_cast<float>(width),
        static_cast<float>(height)
    });
    
    if (mouse_on_button) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            state = State::PRESSED;
            binding();
        } else {
            state = State::COVERED;
        }
    } else {
        state = State::DEFAULT;
    }


}