#include "lcd_driver/lcd_driver.h"

void LCDDriver::rotateText() {
  size_t text_index_line0 = rotation_start;

  for (size_t column = 0; column < 16; ++column) {
    setCursor(column, 0);

    if (text_index_line0 < rotation_text_line0_.size()) {
      writeChar(rotation_text_line0_[text_index_line0]);
    }

    ++text_index_line0;

    if (text_index_line0 >= rotation_text_line0_.size()) {
      text_index_line0 = 0;
    }
  }

  ++rotation_start;

  if (rotation_start >= rotation_text_line0_.size()) {
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
