

export(PACKAGE "ApplicationClient")
include(CMakePackageConfigHelpers)
configure_package_config_file( 
  "Config.cmake.in" 
  "ApplicationClientConfig.cmake"
  INSTALL_DESTINATION ${LIB_FOLDER}
  PATH_VARS
    LIB_FOLDER
  )

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/ApplicationClientConfigVersion.cmake
  VERSION 1.0.0
  COMPATIBILITY SameMajorVersion
  )
  
  export(EXPORT ApplicationClient
  FILE "${CMAKE_CURRENT_BINARY_DIR}/ApplicationClient.cmake"
)
configure_file(${CMAKE_CURRENT_BINARY_DIR}/ApplicationClientConfig.cmake
  "${CMAKE_CURRENT_BINARY_DIR}/ApplicationClient.cmake"
)

### Install Config and ConfigVersion files
install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/ApplicationClientConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ApplicationClientConfigVersion.cmake"
  DESTINATION "${LIB_FOLDER}"
  )