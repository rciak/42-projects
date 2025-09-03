cmake_minimum_required(VERSION 3.10)
project(fractol C)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/inc
    ${PROJECT_SOURCE_DIR}/libft
)

# Collect all source files in src and its subdirectories
file(GLOB_RECURSE FRACTOL_SRC
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/libft/*.c
)

# Create the executable
add_executable(fractol ${FRACTOL_SRC})

# (Optional) Link additional libraries if needed, e.g. for graphics
# target_link_libraries(fractol m) # For math library
# target_link_libraries(fractol X11) # For X11 if using MiniLibX
