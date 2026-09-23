#ifndef H_LCD_DRIVER__
#define H_LCD_DRIVER__

#include <cstdint>
#include <string>

#include "util/util.h"

class LCDDriver {
  size_t write_offset_{0};
  std::string last_text_;

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

 private:
  void setup();
  void init();

  void writeValue(const uint8_t value, const uint delay_us = 50);
};
#endif
