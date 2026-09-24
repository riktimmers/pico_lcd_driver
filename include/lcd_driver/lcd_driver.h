#ifndef H_LCD_DRIVER__
#define H_LCD_DRIVER__

#include <cstdint>
#include <string>

#include "util/util.h"

class LCDDriver {
  size_t write_offset_{0};
  std::string last_text_;

  std::string rotation_text_line0_;
  std::string rotation_text_line1_;
  size_t rotation0_start = 0;
  size_t rotation1_start = 0;

 public:
  LCDDriver();

  void clear();
  void writeText(const std::string &text);

  void cycleText();
  void resetCycle();
  size_t getCycleCount() const { return write_offset_; }
  size_t getTextSize() const { return last_text_.size(); }

  void setCursor(const uint column, const uint line);
  void writeChar(const char character);

  void setText(const std::string &text, const uint line);
  void rotateText();

 private:
  void setup();
  void init();

  void rotateText(const std::string &text, size_t &rotation_start, const uint line);
  void writeValue(const uint8_t value, const uint delay_us = 50);
};
#endif
