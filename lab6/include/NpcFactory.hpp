#pragma once
#include "NPC.hpp"
#include "Knight.hpp"
#include "Pegasus.hpp"
#include "Dragon.hpp"
#include "Point.hpp"
#include <string>
#include <memory>
#include <stdexcept>

// Factory для создания NPC
class NpcFactory {
public:
    static std::shared_ptr<NPC> create(NpcType type, 
                                       const std::string& name, 
                                       const Point<int>& position) {
        switch (type) {
            case NpcType::KNIGHT:
                return std::make_shared<Knight>(name, position);
            case NpcType::PEGASUS:
                return std::make_shared<Pegasus>(name, position);
            case NpcType::DRAGON:
                return std::make_shared<Dragon>(name, position);
            default:
                throw std::invalid_argument("Unknown NPC type");
        }
    }
    
    static std::shared_ptr<NPC> createFromString(const std::string& typeStr,
                                                 const std::string& name,
                                                 int x, int y) {
        NpcType type = stringToType(typeStr);
        return create(type, name, Point<int>(x, y));
    }
    
    static NpcType stringToType(const std::string& typeStr) {
        if (typeStr == "Knight" || typeStr == "knight") {
            return NpcType::KNIGHT;
        } else if (typeStr == "Pegasus" || typeStr == "pegasus") {
            return NpcType::PEGASUS;
        } else if (typeStr == "Dragon" || typeStr == "dragon") {
            return NpcType::DRAGON;
        }
        throw std::invalid_argument("Unknown NPC type string: " + typeStr);
    }
    
    static std::string typeToString(NpcType type) {
        switch (type) {
            case NpcType::KNIGHT:
                return "Knight";
            case NpcType::PEGASUS:
                return "Pegasus";
            case NpcType::DRAGON:
                return "Dragon";
            default:
                return "Unknown";
        }
    }
};

