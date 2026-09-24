#include "lcd_driver/lcd_driver.h"

void LCDDriver::rotateText() {
  size_t text_index_line0 = rotation1_start;
  size_t text_index_line1 = rotation1_start;

  for (size_t column = 0; column < 16; ++column) {
    setCursor(column, 0);

    if (text_index_line0 < rotation_text_line0_.size()) {
      writeChar(rotation_text_line0_[text_index_line0]);
    }

    ++text_index_line0;

    if (text_index_line0 >= rotation_text_line0_.size()) {
      text_index_line0 = 0;
    }

    setCursor(column, 1);

    if (text_index_line1 < rotation_text_line1_.size()) {
      writeChar(rotation_text_line1_[text_index_line1]);
    }

    ++text_index_line1;

    if (text_index_line1 >= rotation_text_line1_.size()) {
      text_index_line1 = 0;
    }
  }

  ++rotation1_start;
  ++rotation2_start;

  if (rotation1_start >= rotation_text_line0_.size()) {
    rotation1_start = 0;
  }

  if (rotation2_start >= rotation_text_line1_.size()) {
    rotation2_start = 0;
  }
}

void LCDDriver::setText(const std::string &text, const uint line) {
  if (line == 0) {
    rotation_text_line0_ = text + " ";
  } else if (line == 1) {
    rotation_text_line1_ = text + " ";
  }
}
