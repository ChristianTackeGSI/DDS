# Copyright 2014 GSI, Inc. All rights reserved.
#
#
project(dds-daemonize)

set(USER_DEFAULTS_CFG_VERSION "0.1")

configure_file(src/version.h.in ${PROJECT_BINARY_DIR}/version.h @ONLY )

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
  MiscCommon
  Boost::boost
	Boost::program_options
  Boost::system
  Boost::filesystem
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
)

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION bin
)

if(BUILD_TESTS)
  message(STATUS "Build ${PROJECT_NAME} unit tests - YES")
  add_subdirectory(tests) 
else()
  message(STATUS "Build ${PROJECT_NAME} unit tests - NO")
endif()

