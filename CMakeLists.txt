cmake_minimum_required(VERSION 3.20)

# ARM Toolchain
if(NOT CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/arm-toolchain.cmake)
endif()

project(RTOS C ASM)

# Sources
add_executable(${PROJECT_NAME}
    startup.s
    os.c 
)
set_target_properties(RTOS PROPERTIES OUTPUT_NAME "RTOS.elf")
# Convert ELF to BIN after build
add_custom_command(TARGET RTOS POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary $<TARGET_FILE:RTOS> $<TARGET_FILE:RTOS>.bin
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Compile options for ARM Cortex-M
target_compile_options(${PROJECT_NAME} PRIVATE
    -mcpu=cortex-m4
    -mthumb
    -ffreestanding
    -nostdlib
    -O0
    -g
)

# Linker options
target_link_options(${PROJECT_NAME} PRIVATE
    -T${CMAKE_SOURCE_DIR}/linker.ld
    -nostdlib
    -Wl,--gc-sections
)