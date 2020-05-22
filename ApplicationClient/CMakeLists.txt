
include(../../QxOrm/QxOrm.cmake)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_AUTOMOC ON)
  set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_definitions(-D_QX_ENABLE_QT_NETWORK)

add_executable(ApplicationClient main.cpp)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Qml REQUIRED)
qt5_use_modules(ApplicationClient Core Gui Qml)
target_link_libraries(ApplicationClient ApplicationClientCore ApplicationClientInterface QxOrm)
install(TARGETS ApplicationClient DESTINATION "${EXEC_FOLDER}")
