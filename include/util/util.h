#ifndef H_UTIL__
#define H_UTIL__

#include "pico/stdlib.h"

inline void initPin(const uint pin_number, gpio_dir direction) {
  gpio_init(pin_number);
  gpio_set_dir(pin_number, direction);
}

inline void initOutput(const uint pin_number) { initPin(pin_number, GPIO_OUT); }

inline void setPin(const uint pin_number) { sio_hw->gpio_set = 1u << pin_number; }

inline void unsetPin(const uint pin_number) { sio_hw->gpio_clr = 1u << pin_number; }

inline void pulse(const uint pin_number, const uint delay_us = 10) {
  setPin(pin_number);
  sleep_us(delay_us);
  unsetPin(pin_number);
}

#endif
