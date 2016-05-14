set(TEST_COMMON test-common)
set(PACKAGE_NAME mytests)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES main-test.cpp)

include_directories($ENV{GTEST_ROOT})
message(GTEST $ENV{GTEST_ROOT})
add_executable(${PACKAGE_NAME} ${SOURCES} )

target_link_libraries (${PACKAGE_NAME} gtest)
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})




file(GLOB CONF_FILES ${PROJECT_SOURCE_DIR}/tests/data/*.conf)
file(COPY ${CONF_FILES} DESTINATION ${EXECUTABLE_OUTPUT_PATH})