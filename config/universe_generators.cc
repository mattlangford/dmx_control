#include "config/universe_generators.hh"
#include "config/light_generators.hh"

namespace config
{

universe generate_living_room_universe()
{
    uint16_t address = 0;

    universe living_room;
    living_room.lights.emplace_back(generate_litake_basic_light(address));
    living_room.lights.emplace_back(generate_litake_basic_light(address));

    return living_room;
}
}
