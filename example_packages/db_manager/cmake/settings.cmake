SET(PATH_TO_SETTINGS
"${CMAKE_CURRENT_LIST_DIR}/../")
MESSAGE("Path to settings is: " ${PATH_TO_SETTINGS})

FILE(WRITE ${CMAKE_CURRENT_LIST_DIR}/../include/db_manager/settings.hpp
"
// Auto-generated headers file, do not edit, will be overwritten by cmake.
#ifndef DB_MANAGER__SETTINGS_HPP_
#define DB_MANAGER__SETTINGS_HPP_

#include <string>

namespace db_manager_settings {

const std::string root_directory = \"${PATH_TO_SETTINGS}/\";

} // namespace db_manager_settings

#endif  // DB_MANAGER__SETTINGS_HPP_\n
"
)
