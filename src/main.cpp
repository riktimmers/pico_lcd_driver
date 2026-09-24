#include <chrono>
#include <functional>
#include <iostream>
#include <thread>

#include "lcd_driver/lcd_driver.h"
#include "util/util.h"

constexpr uint LED_PIN{PICO_DEFAULT_LED_PIN};

int main() {
  stdio_init_all();
  std::cout << "Startup\n";

  LCDDriver lcd_driver;
  lcd_driver.setText("Hello world! What is going on today?", 0);
  lcd_driver.setText("WoWoWoWoWo", 1);

  while (true) {
    sleep_ms(500);
    lcd_driver.rotateText();
  }

  lcd_driver.writeText("Hello world, how are you doing?");

  while (true) {
    sleep_ms(250);
    lcd_driver.cycleText();

    if (lcd_driver.getCycleCount() == lcd_driver.getTextSize() + 1) {
      lcd_driver.resetCycle();
    }
  }
}
