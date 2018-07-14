#include "config/light_generators.hh"

namespace config
{

light generate_litake_basic_light(uint8_t starting_channel)
{
    light l;
    l.starting_channel = starting_channel;

    config::channel brightness;
    brightness.name = "brightness";
    brightness.base_offset = 0;
    brightness.min_value = 0;
    brightness.max_value = 127;
    brightness.role = channel_role::BRIGHTNESS;
    l.channels.emplace_back(std::move(brightness));

    config::channel flash;
    flash.name = "flash";
    flash.base_offset = 0;
    flash.min_value = 128;
    flash.max_value = 255;
    flash.role = channel_role::FLASH;
    l.channels.emplace_back(std::move(flash));

    config::channel red;
    red.name = "red";
    red.base_offset = 0;
    red.min_value = 0;
    red.max_value = 255;
    red.role = channel_role::RED;
    l.channels.emplace_back(std::move(red));

    config::channel green;
    green.name = "green";
    green.base_offset = 0;
    green.min_value = 0;
    green.max_value = 255;
    green.role = channel_role::GREEN;
    l.channels.emplace_back(std::move(green));

    config::channel blue;
    blue.name = "blue";
    blue.base_offset = 0;
    blue.min_value = 0;
    blue.max_value = 255;
    blue.role = channel_role::BLUE;
    l.channels.emplace_back(std::move(blue));

    return l;
}

}
