#ifndef H_LCD_DRIVER_CONST__
#define H_LCD_DRIVER_CONST__

#include <pico/stdlib.h>
constexpr uint REGISTER_SELECT{15};
constexpr uint READ{14};
constexpr uint ENABLE{16};
constexpr uint DATA1{6};
constexpr uint DATA2{7};
constexpr uint DATA3{8};
constexpr uint DATA4{9};
constexpr uint DATA5{10};
constexpr uint DATA6{11};
constexpr uint DATA7{12};
constexpr uint DATA8{13};

constexpr uint INIT_VALUE{0x38};
#endif
