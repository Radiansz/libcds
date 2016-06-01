set(PACKAGE_NAME tsdeque_stress)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES tsdeque_stress.cpp)
set(SOURCES1 tsdeque_stress_producer.cpp)
set(SOURCES2 tsdeque_stress_consumer.cpp)

include_directories(${GTEST_INCLUDE_DIRS})
add_executable(${PACKAGE_NAME} ${SOURCES} )

target_link_libraries (${PACKAGE_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_TIMER_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})


set(PACKAGE_NAME tsdeque_stress_producer)
add_executable(${PACKAGE_NAME} ${SOURCES1} )
target_link_libraries (${PACKAGE_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_TIMER_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

set(PACKAGE_NAME tsdeque_stress_consumer)
add_executable(${PACKAGE_NAME} ${SOURCES2} )
target_link_libraries (${PACKAGE_NAME} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${PACKAGE_NAME} ${CDS_SHARED_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_SYSTEM_LIBRARY} ${Boost_TIMER_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
add_test(NAME ${PACKAGE_NAME} COMMAND ${PACKAGE_NAME} WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})

