########################
# Basic project config #
########################

cmake_minimum_required(VERSION 2.8.8)

set(PROJECT_NAME_STR projectName)

project(${PROJECT_NAME_STR} CXX)

# Common include path
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

# Add main sources
add_subdirectory(src)



#########################
# External dependencies #
#########################

set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

# Google Test
#------------
add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
find_package(Threads REQUIRED)

# Boost
#------

# Preferred installation prefix
#set(BOOST_ROOT )

# Preferred iclude directory e.g. <prefix>/include
#set(BOOST_INCLUDEDIR )

# Preferred library directory e.g. <prefix>/lib
#set(BOOST_LIBRARYDIR )

# Only search hinted locations
#set(Boost_NO_SYSTEM_PATHS )

# Look for the library
find_package(Boost)


###########
# Testing #
###########
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})

add_dependencies(${PROJECT_TEST_NAME} googletest)


if(NOT WIN32)
    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

# Test enumeration
add_test(test1 ${PROJECT_TEST_NAME})
