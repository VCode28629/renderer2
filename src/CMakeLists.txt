add_subdirectory(window)

add_executable(renderer main.cpp)

if(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Debug"))
    target_link_libraries(renderer PRIVATE assimp-vc142-mtd)
elseif(CMAKE_BUILD_TYPE AND (CMAKE_BUILD_TYPE STREQUAL "Release"))
    target_link_libraries(renderer PRIVATE assimp-vc142-mt)
endif()

target_link_libraries(renderer PRIVATE window)

add_custom_command(TARGET renderer POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
    $<TARGET_FILE_DIR:renderer>/res
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${RENDERER_RESOURCES}
    $<TARGET_FILE_DIR:renderer>/res
    COMMENT "Copying res directory"
)
