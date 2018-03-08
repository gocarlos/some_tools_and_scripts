

#include <iostream>
#include <memory>
#include <thread>

#include "spdlog/spdlog.h"

class WebServer
{
public:
  static constexpr unsigned short _port = 9980u;
};

int main(int argc, char **argv)
{
  std::vector<spdlog::sink_ptr> sinks;
  sinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_st>());
  sinks.push_back(std::make_shared<spdlog::sinks::daily_file_sink_st>("/tmp/asdf", 23, 59));
  auto logger = std::make_shared<spdlog::logger>("logger", begin(sinks), end(sinks));
  spdlog::register_logger(logger);
  logger->flush_on(spdlog::level::warn);


  // 
  logger->info("I have the following IP address: http://{}/",
               WebServer::_port); 
  logger->info("I have the following IP address: http://{}/",
               std::to_string(WebServer::_port));

  return 0;
}
