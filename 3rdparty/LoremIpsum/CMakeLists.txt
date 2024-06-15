cmake_minimum_required(VERSION 3.1)

#====================================
# User Configuration
#====================================

project(LoremIpsum VERSION 0.1.0)

# Compilaton Setup
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb")
set(CMAKE_CXX_STANDARD 20)

# Generate compile_commands.json for clang intellisense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(LIB_PUBLIC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/LoremIpsum)
    
set(LIB_PUBLIC_INCLUDES
    ${LIB_PUBLIC_INCLUDE_DIR}/LoremIpsum.hpp
)

set(LIB_PRIVATE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(LIB_PRIVATE_SOURCES 
    ${LIB_PRIVATE_SOURCE_DIR}/LoremIpsum.cpp
)

set(LINKED_LIBS 

)

set(INSTALL_NAME ${PROJECT_NAME})

#====================================
# Print Library Information
#====================================

# Print Project info
message("")
message("PROJECT INFO:")
message("|  name:            " ${PROJECT_NAME})
message("|  dir:             " ${CMAKE_CURRENT_SOURCE_DIR})
message("|  include dir:     " ${LIB_PUBLIC_INCLUDE_DIR})
message("|  source dir:      " ${LIB_PRIVATE_SOURCE_DIR})
message("|  linked:          " ${LINKED_LIBS})
message("___")

# Set all the needed names for installation 
set(CMAKE_INSTALL_PREFIX       ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(INSTALL_CONFIGTARGETS_DIR  ${CMAKE_INSTALL_PREFIX})
set(INSTALL_NAME_TARGETS       ${INSTALL_NAME}Targets)
set(INSTALL_CONFIG             ${INSTALL_NAME}Config.cmake)
set(INSTALL_CONFIG_VERSION     ${INSTALL_NAME}ConfigVersion.cmake)

# Print Installation info
message("")
message("PACKAGE INSTALL INFO:")     
message("|  dir:             " ${CMAKE_INSTALL_PREFIX})
message("|  config dir:      " ${INSTALL_CONFIGTARGETS_DIR})
message("|  name:            " ${INSTALL_NAME})
message("|  targets:         " ${INSTALL_NAME_TARGETS})
message("|  config:          " ${INSTALL_CONFIG})
message("|  config version:  " ${INSTALL_CONFIG_VERSION})
message("___")


#====================================
# Make Library
#====================================

# Set library target
add_library(${PROJECT_NAME} STATIC)

# Add sources
target_sources(${PROJECT_NAME} PRIVATE ${LIB_PRIVATE_SOURCES})

# Add public headers
target_sources(${PROJECT_NAME} PUBLIC
  FILE_SET HEADERS

  # Here we determine the prefix from source root to include files,
  BASE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR} # keep relationship to includes
  # ${LIB_PUBLIC_INCLUDE_DIR}

  FILES ${LIB_PUBLIC_INCLUDES}
)

# Add private libs
target_link_libraries(${PROJECT_NAME} PRIVATE ${LINKED_LIBS})


#====================================
# Install Library
#====================================

target_sources(${INSTALL_NAME} PUBLIC
  FILE_SET HEADERS
  FILES ${LIB_PUBLIC_INCLUDES}
)

set_target_properties(${INSTALL_NAME} PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS ${INSTALL_NAME}
    EXPORT ${INSTALL_NAME_TARGETS}
    FILE_SET HEADERS
    LIBRARY       DESTINATION  lib
    ARCHIVE       DESTINATION  lib
    RUNTIME       DESTINATION  bin
    PUBLIC_HEADER DESTINATION include
)

install(EXPORT ${INSTALL_NAME_TARGETS}
    FILE ${INSTALL_NAME_TARGETS}.cmake
    NAMESPACE ${INSTALL_NAME}::
    DESTINATION ${INSTALL_CONFIGTARGETS_DIR}
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    ${INSTALL_CONFIG_VERSION}
    VERSION ${INSTALL_VERSION}
    COMPATIBILITY AnyNewerVersion
)
    
install(FILES ${INSTALL_CONFIG}
    ${CMAKE_CURRENT_BINARY_DIR}/${INSTALL_CONFIG_VERSION}
    DESTINATION ${INSTALL_CONFIGTARGETS_DIR}
)
