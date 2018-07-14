#pragma once

#include "config/channel.hh"

#include <vector>

namespace config
{

///
///
///
struct light
{
    uint8_t starting_address;

    std::vector<channel> channels;
};

//
// ############################################################################
//

inline std::ostream& operator<<(std::ostream& os, const light& l)
{
    os << "Light at " << static_cast<uint8_t>(l.starting_address) << "\n";
    for (const channel& c : l.channels)
    {
        os << "\n   " << c;
    }
    return os;
}

}