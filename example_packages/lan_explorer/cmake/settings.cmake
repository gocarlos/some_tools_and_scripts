SET(INSTALL_DIRECTORE_SETTINGS "")

IF(CREATE_SNAP_APP)
  SET(INSTALL_DIRECTORE_SETTINGS "/snap/${LAN_EXPLORER}/current/${LAN_EXPLORER}/")
  MESSAGE("Going to move the settings files to ${INSTALL_DIRECTORE_SETTINGS}")
ELSE()
  SET(INSTALL_DIRECTORE_SETTINGS "${CMAKE_CURRENT_LIST_DIR}/../")
  MESSAGE("Going to move the settings files to ${INSTALL_DIRECTORE_SETTINGS}")
ENDIF(CREATE_SNAP_APP)

FILE(WRITE ${CMAKE_CURRENT_LIST_DIR}/../include/${LAN_EXPLORER}/settings.hpp
"
// Auto-generated headers file, do not edit, will be overwritten by cmake.
#ifndef LAN_EXPLORER__SETTINGS_HPP_
#define LAN_EXPLORER__SETTINGS_HPP_

#include <string>

namespace lan_explorer_settings {

const std::string root_directory = \"${INSTALL_DIRECTORE_SETTINGS}\";

} // namespace lan_explorer_settings

#endif  // LAN_EXPLORER__SETTINGS_HPP_\n
")
