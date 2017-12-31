#include <fstream>
#include <iostream>
#include <string>

#include <gtkmm.h>

#include "lan_explorer/settings.hpp"

int main(int argc, char *argv[]) {
  std::cout << "Hello world\n";

  const std::string home_path = lan_explorer_settings::root_directory;

  std::cout << home_path << std::endl;
  auto app =
    Gtk::Application::create(argc, argv,
      "ch.martinho.lan_explorer.");

  Gtk::Window window;
  window.set_default_size(200, 200);

  return app->run(window);


  return 0;
}
