set(PACKAGE_NAME tsdeque_stress)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES tsdeque_stress.cpp)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PACKAGE_NAME} ${SOURCES} )

target_link_libraries (${PACKAGE_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_TIMER_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
#add_test(NAME ${PACKAGE_NAME}_threadbuffer_as_stack COMMAND ${PACKAGE_NAME} -wa 300000 -ra 100000 -wt 1 -rt 3 --gtest_repeat=300 --gtest_filter=*stack* WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} )
#add_test(NAME ${PACKAGE_NAME}_threadbuffer_as_queue COMMAND ${PACKAGE_NAME} -wa 300000 -ra 100000 -wt 1 -rt 3 --gtest_repeat=300 --gtest_filter=*queue* WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} )
#add_test(NAME ${PACKAGE_NAME}_threadbuffer_as_deque COMMAND ${PACKAGE_NAME} -wa 300000 -ra 100000 -wt 1 -rt 3 --gtest_repeat=300 --gtest_filter=*deque* WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH} )

