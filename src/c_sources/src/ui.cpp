#include "ui.h"

Ui& Ui::GetInstance() {
    static Ui ui;
    return ui;
}

Ui::Ui() {}

Ui::~Ui() {
    CloseWindow();
}

void Ui::StartUi() {


    SetConfigFlags(FLAG_MSAA_4X_HINT);
    
    InitWindow(window_width, window_height, ".");
    SetTargetFPS(60);
    ClearBackground(WHITE);
    initializeMainTexture();

    SetTextureFilter(*main_texture, TEXTURE_FILTER_TRILINEAR);

    progress_bar = std::make_shared<ProgressBar>(500, 20);


    render_button = std::make_shared<Button>(
        render_button_position_x, 
        render_button_position_y, 
        100, 
        25, 
        []() { std::cout << "AAAAAAAAAA" << std::endl; },
        render_button_text);

    open_button = std::make_shared<Button>(
        open_button_position_x, 
        open_button_position_y, 
        100, 
        25, 
        []() { std::cout << "AAAAAAAAAA" << std::endl; },
        open_button_text);

    
    text_field = std::make_shared<TextField>(text_field_position_x, text_field_position_y, 400, 520);
    text_field->SetText("ASDFASFSAFEASDFASDF\nsdfdasf");
    
    ShadowEffect mainShadow(main_text_poisiton_x - 10, main_text_poisiton_y - 10, render_width + 20, render_height + 20, 0.1f, 13);
    ShadowEffect progress_bar_shadow(progress_bar_poisiton_x - 5, progress_bar_poisiton_y - 5, 500 + 10, 20 + 10, 0.9f, 2);
    ShadowEffect render_button_shadow(render_button_position_x - 5, render_button_position_y - 5, 100 + 10, 25 + 10, 0.9f, 13);
    ShadowEffect open_button_shadow(open_button_position_x - 5, open_button_position_y - 5, 100 + 10, 25 + 10, 0.9f, 13);
    ShadowEffect text_field_shadow(text_field_position_x - 5, text_field_position_y - 5, 400 + 10, 520 + 10, 0.1f, 13);

    


    
    size_t counter = 0;
    while (!WindowShouldClose()) {
        ClearBackground(WHITE);
        
        counter = counter > 100 ? 0 : counter + 1;
        for (size_t i = 0; i < 128; ++i) {
            for (size_t j = 0; j < 128; ++j) {
                render_texture[(i * 512 + j) * 4] = (render_texture[(i * 512 + j) * 4] + 5) % 256;
                render_texture[(i * 512 + j) * 4 + 1] = (render_texture[(i * 512 + j) * 4 + 1] + 5) % 256;
            }
        }

        render_button->Update();
        open_button->Update();



        BeginDrawing();

        mainShadow.Draw();
        progress_bar_shadow.Draw();
        render_button_shadow.Draw();
        open_button_shadow.Draw();
        text_field_shadow.Draw();

        drawRenderTexture();
        
        render_button->Draw();
        open_button->Draw();

        text_field->Draw();

        progress_bar->draw(progress_bar_poisiton_x, progress_bar_poisiton_y);
        progress_bar->setValuse(static_cast<float>(counter) / 100.0f);
        EndDrawing();
    }
}

void Ui::drawRenderTexture() {
    if (render_texture != nullptr) {
        uint8_t* data = static_cast<uint8_t*>(malloc(render_height * render_width * 4));
        std::memcpy(data, render_texture, render_height * render_width * 4);
        TextureOperations::SmoothTexture(render_width, render_height, 10, data);
        Image img = {
            .data = data,
            .width = render_width,
            .height = render_height,
            .mipmaps = 1,
            .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8
        };
        Color* pixels = LoadImageColors(img);
        UpdateTexture(*main_texture, pixels);
        UnloadImage(img);
        DrawTexture(*main_texture, main_text_poisiton_x, main_text_poisiton_y, WHITE);
        UnloadImageColors(pixels);
        Rectangle texture_field{
            static_cast<float>(main_text_poisiton_x),
            static_cast<float>(main_text_poisiton_y),
            static_cast<float>(render_width),
            static_cast<float> (render_height)
        };
        DrawRectangleRoundedLinesEx(texture_field, 0.05f, 0, 3, Fade(BLACK, 1.0f));
    }
}

void Ui::initializeMainTexture() {
    uint8_t* data0 = static_cast<uint8_t*>(malloc(render_height * render_width * 4));
    Image img0 = {
        .data = data0,
        .width = render_width,
        .height = render_height,
        .mipmaps = 1,
        .format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8 
    };
    main_texture = std::make_shared<Texture2D>(LoadTextureFromImage(img0));
    UnloadImage(img0);
}

