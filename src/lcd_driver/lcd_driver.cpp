#include "lcd_driver/lcd_driver.h"

#include "lcd_driver/lcd_driver_const.h"
#include "util/util.h"

LCDDriver::LCDDriver() {
  sleep_ms(2000);
  setup();
  init();
}

void LCDDriver::setup() {
  initOutput(REGISTER_SELECT);
  initOutput(READ);
  initOutput(ENABLE);
  initOutput(DATA1);
  initOutput(DATA2);
  initOutput(DATA3);
  initOutput(DATA4);
  initOutput(DATA5);
  initOutput(DATA6);
  initOutput(DATA7);
  initOutput(DATA8);
}

void LCDDriver::init() {
  unsetPin(REGISTER_SELECT);
  writeValue(INIT_VALUE, 50'000);
  writeValue(INIT_VALUE, 50'000);
  writeValue(INIT_VALUE, 50'000);
  writeValue(0x01, 2'000);
  writeValue(0x06);
  writeValue(0x0C, 50'000);
}

void LCDDriver::writeValue(const uint8_t value, const uint delay_us) {
  (value & 1) ? setPin(DATA1) : unsetPin(DATA1);
  (value >> 1 & 1) ? setPin(DATA2) : unsetPin(DATA2);
  (value >> 2 & 1) ? setPin(DATA3) : unsetPin(DATA3);
  (value >> 3 & 1) ? setPin(DATA4) : unsetPin(DATA4);
  (value >> 4 & 1) ? setPin(DATA5) : unsetPin(DATA5);
  (value >> 5 & 1) ? setPin(DATA6) : unsetPin(DATA6);
  (value >> 6 & 1) ? setPin(DATA7) : unsetPin(DATA7);
  (value >> 7 & 1) ? setPin(DATA8) : unsetPin(DATA8);

  pulse(ENABLE);
  sleep_us(delay_us);
}

void LCDDriver::clear() {
  unsetPin(REGISTER_SELECT);
  writeValue(0x01, 2'000);
  setPin(REGISTER_SELECT);
  sleep_ms(5);
}

void LCDDriver::writeChar(const char character) {
  setPin(REGISTER_SELECT);
  writeValue(character);
}

void LCDDriver::writeText(const std::string &text) {
  last_text_ = text;
  size_t count = write_offset_;

  size_t line = 0;
  // for (uint8_t line = 0; line < 2; ++line) {
  for (uint8_t column = 0; column < 16; ++column) {
    if (count < text.size()) {
      if (text[count] == '\n') {
        ++line;
        ++count;
        column = 0;

        if (line >= 2) {
          return;
        }
      }
      setCursor(column, line);
      writeChar(text[count++]);
    } else {
      return;
    }
  }
  //}
}

void LCDDriver::setCursor(const uint column, const uint line) {
  unsetPin(REGISTER_SELECT);
  writeValue((0x80 | (line ? 0x40 : 0x0)) + column);
  setPin(REGISTER_SELECT);
  sleep_us(40);
}

void LCDDriver::cycleText() {
  clear();
  writeText(last_text_);
  ++write_offset_;
}

void LCDDriver::resetCycle() { write_offset_ = 0; }
