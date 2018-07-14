#include "config/universe_generators.hh"
#include "config/light_generators.hh"

namespace config
{

universe generate_living_room_universe()
{
    uint16_t address = 1;

    universe living_room;
    living_room.lights.emplace_back(generate_litake_basic_light("Right Side", address));
    living_room.lights.emplace_back(generate_litake_basic_light("Left Side", address));

    return living_room;
}
}