CMAKE_MINIMUM_REQUIRED(VERSION 3.5 FATAL_ERROR)

SET(LAN_EXPLORER "lan-explorer")

IF(NOT PROJECT_NAME)
  PROJECT (${LAN_EXPLORER})
ENDIF(NOT PROJECT_NAME)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11")

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Debug)
ENDIF()

FIND_PACKAGE(Threads)
find_package(PkgConfig)

INCLUDE("${CMAKE_CURRENT_LIST_DIR}/cmake/settings.cmake")

# pkg_check_modules(GTKMM gtkmm-2.4)
pkg_check_modules(PKG REQUIRED gtkmm-3.0)

INCLUDE_DIRECTORIES(
  ${CMAKE_CURRENT_LIST_DIR}/include
  ${GTKMM_INCLUDE_DIRS}
)
include_directories(${PKG_INCLUDE_DIRS})


LINK_DIRECTORIES(
  ${GTKMM_LIBRARY_DIRS}

)

ADD_EXECUTABLE(${LAN_EXPLORER} src/main.cpp)
TARGET_LINK_LIBRARIES(${LAN_EXPLORER}
    ${GTKMM_LIBRARIES}
    ${PKG_LIBRARIES}
)

# TARGET_LINK_LIBRARIES(save_to_sqlite_db
  # Threads::Threads
  # sqlite3
  # dl
# )


                                                                # it contains documentation
# Now the variables GTKMM_INCLUDE_DIRS, GTKMM_LIBRARY_DIRS and GTKMM_LIBRARIES
# contain what you expect


################################
# Define Unit Tests
################################

IF(BUILD_TESTS)
  INCLUDE("${CMAKE_CURRENT_LIST_DIR}/test/CMakeLists.txt")
ENDIF(BUILD_TESTS)

################################
# Install Traffic Monitor Executable
################################

INSTALL(
  TARGETS ${LAN_EXPLORER}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
)

# INSTALL(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/settings DESTINATION ${LAN_EXPLORER})
# INSTALL(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/webserver DESTINATION ${LAN_EXPLORER})
