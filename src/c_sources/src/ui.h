#pragma once
#include <raylib.h>
#include <raygui.h>
#include "stdafx.h"
#include "ui_progress_bar.h"
#include "texture_oprations.h"
#include "ui_constants.h"
#include "shadow_effect.h"
#include "ui_button.h"
#include "ui_text_field.h"

class Ui : public UiConstants {
    private:
    const size_t window_width = 1000;
    const size_t window_height = 600;

    
    const size_t render_width = 512;
    const size_t render_height = 512;

    uint8_t* render_texture = nullptr;

    std::shared_ptr<Texture2D> main_texture = nullptr;
    std::shared_ptr<ProgressBar> progress_bar = nullptr;
    std::shared_ptr<Button> render_button = nullptr;
    std::shared_ptr<Button> open_button = nullptr;

    std::shared_ptr<TextField> text_field;
    void drawRenderTexture();
    void initializeMainTexture();
    
    public:
    static Ui& GetInstance();
    Ui();
    ~Ui();

    void SetRenderTexture(uint8_t* data) { render_texture = data; };
    void StartUi();
    void SetTexture();

};