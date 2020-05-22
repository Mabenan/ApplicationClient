
include(../../QxOrm/QxOrm.cmake)
set(target "ApplicationClientCore")

add_definitions(-DAPPLICATIONCLIENTCORE_LIBRARY)
add_definitions(-D_QX_ENABLE_QT_NETWORK)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(include)
add_subdirectory(rsrc)
add_subdirectory(src)
add_subdirectory(ui)
add_library(${target} SHARED ${SRC} ${RSC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Qml REQUIRED)
find_package(Qt5Quick REQUIRED)
qt5_use_modules(${target} Core Gui Qml Quick)
target_link_libraries(${target} ApplicationClientInterface QxOrm)
target_precompile_headers(${target}
 PUBLIC
  "ApplicationClientCore.Precompiled.h"
 )
target_include_directories(${target}
 PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${INCLUDE_FOLDER}>
 PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)    
set_property(TARGET ${target} APPEND PROPERTY PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
install(TARGETS ${target}
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${EXEC_FOLDER}"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
install(FILES ${HEADER} DESTINATION "${INCLUDE_FOLDER}")
