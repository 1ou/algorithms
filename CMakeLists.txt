cmake_minimum_required(VERSION 3.3)
project(test_build)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

#set(BUILD_1 bubble_sort)
#set(SOURCE_FILES_1 ./sort/BubbleSort.cpp ./sort/InsertionSort.cpp)
#add_executable(${BUILD_1} ${SOURCE_FILES_1})
#
#set(BUILD_2 insertion_sort)
#set(SOURCE_FILES_2 ./sort/InsertionSort.cpp)
#add_executable(${BUILD_2} ${SOURCE_FILES_2})
#
#set(BUILD_3 selection_sort)
#set(SOURCE_FILES_3 ./sort/SelectionSort.cpp)
#add_executable(${BUILD_3} ${SOURCE_FILES_3})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests ./sort/TestSort.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runGraphTests ./graph/TestGraph.cpp)
target_link_libraries(runGraphTests ${GTEST_LIBRARIES} pthread)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runQueueTests ./queue/TestQueue.cpp)
target_link_libraries(runQueueTests ${GTEST_LIBRARIES} pthread)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runStackTests ./stack/TestStack.cpp)
target_link_libraries(runStackTests ${GTEST_LIBRARIES} pthread)