/*
 * Example showing the basic usage of the sqlite3 to insert and retrieve an binary file.
 */

#include <fstream>
#include <iostream>
#include <string>

#include "sqlite3.h"

#include "db_manager/settings.hpp"

// Insert file into the sqlite3 db with c library.
int insert_file_to_db(const std::string &db_path_name, const std::string &file_path_name) {
  std::ifstream file(file_path_name, std::ios::in | std::ios::binary);
  if (!file) {
    std::cerr << "An error occurred opening the file\n";
    return -1;
  }
  file.seekg(0, std::ifstream::end);
  std::streampos size = file.tellg();
  file.seekg(0);

  char *buffer = new char[size];
  file.read(buffer, size);

  sqlite3 *db = NULL;
  int rc = sqlite3_open_v2(db_path_name.c_str(), &db, SQLITE_OPEN_READWRITE, NULL);
  if (rc != SQLITE_OK) {
    std::cerr << "db open failed: " << sqlite3_errmsg(db) << std::endl;
  } else {
    sqlite3_stmt *stmt = NULL;
    rc = sqlite3_prepare_v2(db,
                            "INSERT INTO images(img)"
                            " VALUES(?)",
                            -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
      std::cerr << "prepare failed: " << sqlite3_errmsg(db) << std::endl;
    } else {
      // SQLITE_STATIC because the statement is finalized
      // before the buffer is freed:
      rc = sqlite3_bind_blob(stmt, 1, buffer, size, SQLITE_STATIC);
      if (rc != SQLITE_OK) {
        std::cerr << "bind failed: " << sqlite3_errmsg(db) << std::endl;
      } else {
        rc = sqlite3_step(stmt);
        if (rc != SQLITE_DONE) {
          std::cerr << "execution failed: " << sqlite3_errmsg(db) << std::endl;
        }
      }
    }
    sqlite3_finalize(stmt);
  }
  sqlite3_close(db);

  delete[] buffer;

  return 0;
}

// Retrieve file from the sqlite3 db with c library.
int retrieve_file_from_db(const std::string &db_path_name, const std::string &file_path_name) {
  // TODO
  return 0;
}

int main(int argc, char *argv[]) {

  const std::string home_path = db_manager_settings::root_directory;
  const std::string file_path_name = home_path + "carlos.jpg";
  const std::string db_path_name = home_path + "data_base.db";

  if (insert_file_to_db(db_path_name, file_path_name)) {
    return -1;
  }

  if (retrieve_file_from_db(db_path_name, file_path_name)) {
    return -1;
  }

  return 0;
}
