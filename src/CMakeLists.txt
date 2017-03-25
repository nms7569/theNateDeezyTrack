cmake_minimum_required(VERSION 3.0)

project(theNateDeezyTrack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")


# option for when we want to run in MPI, for now default is off
option(RUN_IN_MPI_MODE "Turn on the MPI compile mode" OFF)

# additional include libraries
include(FindBoost)
if (RUN_IN_MPI_MODE)
include(FindMPI)
find_package(MPI Required)
include_directories(${MPI_CXX_INCLUDE_PATH})
# adding preprocessor settings
add_definitions(-DUSE_MPI)
find_package(Boost 1.44 COMPONENTS mpi serialization filesystem system REQUIRED)
else (RUN_IN_MPI_MODE)
find_package(Boost 1.44 COMPONENTS filesystem system ) #minimum version is 1.44 required means it will fail if boost isn't present
endif (RUN_IN_MPI_MODE)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

set(COMMON_FILES main.cpp)

set(EULER_FILES pe_problem14.h pe_problem14.cpp pe_problem22.h pe_problem22.cpp pe_problem6.h pe_problem6.cpp)

add_executable(theNateDeezyTrack ${COMMON_FILES} ${EULER_FILES})

if (RUN_IN_MPI_MODE)
target_link_libraries(theNateDeezyTrack ${Boost_LIBRARIES} ${MPI_CXX_LIBRARIES})
else (RUN_IN_MPI_MODE)
target_link_libraries(theNateDeezyTrack ${Boost_LIBRARIES})
endif (RUN_IN_MPI_MODE)
