### Top Level CMake Script for ND-Grad ###
cmake_minimum_required(VERSION 3.23.0)
project(NDGrad VERSION 1.0.0)


### Options ###
option(courses_build_all            "Builds nd-coursework applications, corresponding unit tests, and corresponding code samples." OFF)
option(courses_build_tests          "Builds nd-coursework applications and corresponding unit tests." OFF)
option(courses_build_samples        "Builds nd-coursework applications and corresponding code samples." OFF)
option(courses_exclude_scripts      "Builds nd-coursework applications while ignoring the scripts directory." OFF)

option(grad_build_all               "Builds all applications, unit tests, and code samples." OFF)
option(grad_build_tests             "Builds all applications and unit tests." OFF)
option(grad_build_samples           "Builds all applications and code samples." OFF)
option(grad_enable_coverage         "Builds all applications, unit tests, and enables coverage options." OFF)
option(grad_format_codebase         "Builds appropriate applications while also formatting the code." OFF)

option(research_build_all           "Builds nd-research applications, corresponding unit tests, and corresponding code samples." OFF)
option(research_build_tests         "Builds nd-research applications and corresponding unit tests." OFF)
option(research_build_samples       "Builds nd-research applications and corresponding code samples." OFF)
option(research_exclude_npgBuilder  "Builds nd-research applications without including NPG-Builder and its dependencies." OFF)
option(research_exclude_scripts     "Builds nd-research applications while ignoring the scripts directory." OFF)

if (grad_format_codebase)
    find_program(formatter clang-format HINTS /opt/homebrew/bin/)

    if (NOT formatter_NOTFOUND)
        message(STATUS "Formatting ND-Grad")

        ## Run clang-format on all code except the files passed as arguments with the '-i' flag ##
        execute_process(COMMAND bash cmake/scripts/format-codebase.sh 
                                        -f ${formatter}
                                        -i nd-research/src/applications/misc/squareMatrix.cpp
                                        -i nd-research/src/applications/misc/utils.cpp
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                        OUTPUT_QUIET)
    endif()
endif()

if (grad_enable_coverage)
    set(grad_build_tests ON)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage)
endif()

if (grad_build_all)
    set(courses_build_all ON)
    set(grad_build_tests ON)
    set(grad_build_samples ON)
    set(research_build_all ON)
endif()

if (grad_build_tests)
    set(courses_build_tests ON)
    set(research_build_tests ON)
endif()

if (grad_build_samples)
    set(courses_build_samples ON)
    set(research_build_samples ON)
endif()

if (courses_build_all)
    set(courses_build_tests ON)
    set(courses_build_samples ON)

    if (NOT grad_build_all AND NOT grad_build_tests AND NOT grad_build_samples
        AND NOT research_build_all AND NOT research_build_tests AND NOT research_build_samples)
        set(grad_exclude_research ON)
    endif()
endif()

if (research_build_all)
    set(research_build_tests ON)
    set(research_build_samples ON)

    if (NOT grad_build_all AND NOT grad_build_tests AND NOT grad_build_samples
        AND NOT courses_build_all AND NOT courses_build_tests AND NOT courses_build_samples)
        set(grad_exclude_courses ON)
    endif()
endif()


### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (NOT WIN32)
    add_compile_options(-Wall -Wextra -pedantic -Werror)

    if (CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-Wno-psabi)
    endif()
else()
    add_compile_options(/MD /WX)
endif()


### Functions ###
include(cmake/grad-utility-functions.cmake)


### Files / Directories ###
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all executables.")

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    CACHE PATH "Single directory for all static libraries.")


### External Modules ###
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

include(FetchContent)
find_package(DryChem)

if (NOT DryChem_FOUND)
    ## If DryChem isn't installed or can't be found, download it from github ##
    message(STATUS "Fetching DryChem...")
    FetchContent_Declare(drychem        # v1.0.0
                         GIT_REPOSITORY "https://github.com/crdrisko/drychem.git"
                         GIT_TAG        "714dded492aca9a59c7d3f167839abe57daec12e")

    FetchContent_MakeAvailable(drychem)

    set(DryChem_FOUND TRUE)
    set(COMMON_UTILS_INCLUDE_DIR "${drychem_SOURCE_DIR}/common-utilities/include")
    set(CPP_UNITS_INCLUDE_DIR    "${drychem_SOURCE_DIR}/cpp-units/include")
endif()

include_directories(${COMMON_UTILS_INCLUDE_DIR})
include_directories(${CPP_UNITS_INCLUDE_DIR})

find_package(DryPhys)

if (NOT DryPhys_FOUND)
    ## If DryPhys isn't installed or can't be found, download it from github ##
    message(STATUS "Fetching DryPhys...")
    FetchContent_Declare(dryphys
                         GIT_REPOSITORY "https://github.com/crdrisko/dryphys.git"
                         GIT_TAG dev)

    if (research_exclude_npgBuilder)
        set(phys_exclude_engine ON)
    else()
        set(phys_exclude_engine OFF)
    endif()

    FetchContent_MakeAvailable(dryphys)
    set(DryPhys_FOUND TRUE)
    set(DRYPHYS_INCLUDE_DIR  "${dryphys_SOURCE_DIR}/include")
    set(ENGINE2D_LIBRARIES    engine2d_gui)
else()
    ## ImGui
    message(STATUS "Fetching ImGUI...")
    FetchContent_Declare(imgui          # v1.90.5
                         GIT_REPOSITORY "https://github.com/ocornut/imgui.git"
                         GIT_TAG        "231cbee0fc4f59dbe5b8b853a11b08dc84e57c65")

    FetchContent_MakeAvailable(imgui)
    include_directories(${imgui_SOURCE_DIR})

    ## SFML
    message(STATUS "Fetching SFML...")
    FetchContent_Declare(sfml           # v2.6.1
                         GIT_REPOSITORY "https://github.com/SFML/SFML.git"
                         GIT_TAG        "69ea0cd863aed1d4092b970b676924a716ff718b")

    set(SFML_BUILD_AUDIO ON)
    set(SFML_BUILD_NETWORK OFF)

    FetchContent_MakeAvailable(sfml)

    ## ImGui-SFML
    message(STATUS "Fetching ImGui-SFML...")
    FetchContent_Declare(imgui_sfml     # v2.6
                         GIT_REPOSITORY "https://github.com/SFML/imgui-sfml.git"
                         GIT_TAG        "de565ac8f2b795dedc0307b60830cb006afd2ecd")

    set(IMGUI_DIR ${imgui_SOURCE_DIR})
    set(IMGUI_SFML_FIND_SFML OFF)
    set(IMGUI_SFML_IMGUI_DEMO ON)

    FetchContent_MakeAvailable(imgui_sfml)
    include_directories(${imgui_sfml_SOURCE_DIR})

    set(IMGUI_SOURCE ${imgui_SOURCE_DIR}/imgui.cpp
                     ${imgui_SOURCE_DIR}/imgui_demo.cpp
                     ${imgui_SOURCE_DIR}/imgui_draw.cpp
                     ${imgui_SOURCE_DIR}/imgui_tables.cpp
                     ${imgui_SOURCE_DIR}/imgui_widgets.cpp
                     ${imgui_sfml_SOURCE_DIR}/imgui-SFML.cpp)
endif()

include_directories(${DRYPHYS_INCLUDE_DIR})


### ND-Grad Subprojects ###
if (NOT grad_exclude_courses)
    # add_subdirectory(nd-coursework)
endif()

if (NOT grad_exclude_research)
    include_directories(nd-research/include)
    add_subdirectory(nd-research)
endif()
