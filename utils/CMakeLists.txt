add_library(utils STATIC list_utils.cpp mylog.cpp)

set_target_properties(utils PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(utils PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)