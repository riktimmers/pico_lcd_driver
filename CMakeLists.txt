cmake_minimum_required(VERSION 3.13)

# initialise the SDK based on PICO_SDK_PATH note: this must happen before
# project()
include(pico_sdk_import.cmake)
project(pico_lcd_driver C CXX ASM)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
  add_compile_options(-O3 -Wall -Werror -Wextra)
else()
  add_compile_options(-g -Wall -Werror -Wextra)
endif()

# initialise the Raspberry Pi Pico SDK
pico_sdk_init()

set(CMAKE_EXPORT_COMPILE_COMMANDS On)

include_directories(include)

set(source_lcd_driver src/lcd_driver/lcd_driver.cpp)
set(source_code src/main.cpp ${source_lcd_driver})

add_executable(main ${source_code})

target_link_libraries(main pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(main)
