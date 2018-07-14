// For controlling lights
#include "config/universe_generators.hh"
#include "light_control/dmx.hh"
#include "light_control/light_universe_controller.hh"
#include "serial_control/ftd2xx_serial_interface.hh"

// For hosting webserver
#include "http_server/http_server.hh"
#include "http_server/messages.hh"
#include "json/json.hh"
#include "json/parser.hh"
#include "resources/file_resource.hh"
#include "server_hooks/universe_resource.hh"

#include <random>
#include <iostream>
#include <limits>
#include <map>
#include <memory>

constexpr auto ROOT_PATH = "/home/matt/Documents/dmx_control/server_hooks/test_server";

int main()
{
    const config::universe universe_config = config::generate_living_room_universe();

    //
    // Configure the universe controller and serial interface
    //
    lights::light_universe_controller::controller_params params;
    params.control = lights::light_universe_controller::control_type::EXECUTIVE_AUTO;

    serial::ftd2xx_serial_interface interface(dmx::BAUDRATE);
    lights::light_universe_controller universe{interface, params, universe_config};

    //
    // Build the universe using the resource builder
    //
    universe_resource_builder builder{universe};

    auto resource = std::make_shared<universe_resource>(builder.finalize());

    //
    // Now spin a web server up, see if the client can access it
    //
    http_server server(8080);
    server.add_resource(resource);
    server.add_resource(std::make_shared<resources::file_resource>(std::string(ROOT_PATH), "/index.html"));
    server.add_resource(std::make_shared<resources::file_resource>(std::string(ROOT_PATH), "/styles.css"));
    server.add_resource(std::make_shared<resources::file_resource>(std::string(ROOT_PATH), "/scripts.js"));

    server.start_server();
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::duration<double>(1.0));
        std::cout << resource->get_json_resource().get_value_as_string() << "\n";
    }
}
