include_directories(${Dev_SOURCE_DIR}/include)
add_executable(${PROJECT_NAME} 
    main.c 
    render.c 
    player.c
    input.c
    enviorment.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    pspdebug
    pspdisplay
    pspge
    pspctrl
    pspgu
)

create_pbp_file(
    # TARGET ${PROJECT_NAME}
    TARGET Dev
    ICON_PATH NULL
    BACKGROUND_PATH NULL
    PREVIEW_PATH NULL
    # TITLE ${PROJECT_NAME}
    TITLE Dev
)
