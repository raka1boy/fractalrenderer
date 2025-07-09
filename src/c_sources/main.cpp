#include <iostream>
#include <ui.h>

int main() {
  Ui& ui = Ui::GetInstance();
  uint8_t* rend = new uint8_t[512 * 512 * 4];
  std::cout << "AA" << std::endl;
  for (size_t i = 0; i < 512; ++i) {
    for (size_t j = 0; j < 512; ++j) {
      rend[(i * 512 + j) * 4] = i % 256;
      rend[(i * 512 + j) * 4 + 1] = j % 256;
      rend[(i * 512 + j) * 4 + 2] = 0;
      rend[(i * 512 + j) * 4 + 3] = 255;
    }
  }
  //rend[12312312312] = 1;
  std::cout << "BB" << std::endl;
  ui.SetRenderTexture(rend);
  ui.StartUi();
}