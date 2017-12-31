#include <fstream>
#include <iostream>
#include <string>

#include <gtkmm.h>

#include "simple_gtk_snap_app/settings.hpp"

int main(int argc, char *argv[]) {
  std::cout << "Hello world\n";

  const std::string home_path = simple_gtk_snap_app::root_directory;

  std::cout << home_path << std::endl;
  auto app =
    Gtk::Application::create(argc, argv,
      "ch.martinho.simple-gtk-snap-app");

  Gtk::Window window;
  window.set_default_size(200, 200);

  return app->run(window);


  return 0;
}
