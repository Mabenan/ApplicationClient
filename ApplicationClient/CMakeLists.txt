
include(../../QxOrm/QxOrm.cmake)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_QX_ENABLE_QT_NETWORK)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
add_executable(${CMAKE_PROJECT_NAME} main.cpp main.rc)
else()
add_executable(${CMAKE_PROJECT_NAME} WIN32 main.cpp main.rc)
endif()
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Qml REQUIRED)
qt5_use_modules(${CMAKE_PROJECT_NAME} Core Gui Qml)
target_link_libraries(${CMAKE_PROJECT_NAME} ApplicationClientCore ApplicationClientInterface QxOrm)
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION "${EXEC_FOLDER}")
