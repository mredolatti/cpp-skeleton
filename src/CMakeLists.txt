cmake_minimum_required(VERSION 2.8.4)

#########################
# Build main executable #
#########################

# Specify sources manually
set(SOURCES 
    main.cpp)

# Or use a file glob for the local folder
#file(GLOB ./*)

# Or use a recursive gile glob to include all folders inside src
#file(GLOB_RECURSE ./*)


add_executable(hello ${SOURCES})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
target_link_libraries( hello ${Boost_LIBRARIES} )

#install(TARGETS hello RUNTIME DESTINATION bin)
