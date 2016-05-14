set(TEST_COMMON test-common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/stress)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/unit)


file(GLOB CONF_FILES ${PROJECT_SOURCE_DIR}/tests/data/*.conf)
file(COPY ${CONF_FILES} DESTINATION ${EXECUTABLE_OUTPUT_PATH})