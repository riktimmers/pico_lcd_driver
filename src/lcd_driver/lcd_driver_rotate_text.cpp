#include "lcd_driver/lcd_driver.h"

void LCDDriver::rotateText() {
  rotateText(rotation_text_line0_, rotation0_start, 0);
  rotateText(rotation_text_line1_, rotation1_start, 1);
}

void LCDDriver::rotateText(const std::string &text, size_t &rotation_start, const uint line) {
  size_t text_index_line = rotation_start;

  for (size_t column = 0; column < 16; ++column) {
    setCursor(column, line);

    if (text_index_line < text.size()) {
      writeChar(text[text_index_line]);
    }

    ++text_index_line;

    if (text_index_line >= text.size()) {
      text_index_line = 0;
    }
  }

  ++rotation_start;

  if (rotation_start >= text.size()) {
    rotation_start = 0;
  }
}

void LCDDriver::setText(const std::string &text, const uint line) {
  if (line == 0) {
    rotation_text_line0_ = text + " ";
  } else if (line == 1) {
    rotation_text_line1_ = text + " ";
  }
}
