set(TEST_COMMON test-common)
set(PACKAGE_NAME stress-test)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES stress-test.cpp)
message(TEST!!! ${GTEST_BOTH_LIBRARIES})
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PACKAGE_NAME} ${SOURCES} )

target_link_libraries (${PACKAGE_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_TIMER_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})


