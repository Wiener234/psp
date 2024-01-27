cmake_minimum_required(VERSION 3.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Dev)

add_subdirectory(src)
# add_executable(${PROJECT_NAME} src)
# add_executable(${PROJECT_NAME} test.c input.c render.c)

# target_link_libraries(${PROJECT_NAME} PRIVATE
#     pspdebug
#     pspdisplay
#     pspge
#     pspctrl
#     pspgu
# )

# Create an EBOOT.PBP file
# create_pbp_file(
#     TARGET ${PROJECT_NAME}
#     ICON_PATH NULL
#     BACKGROUND_PATH NULL
#     PREVIEW_PATH NULL
#     TITLE ${PROJECT_NAME}
# )
