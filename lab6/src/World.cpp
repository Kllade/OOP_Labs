#include "../include/World.hpp"
#include "../include/BattleVisitor.hpp"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>

void World::notifyKill(const std::string& killer, const std::string& victim) {
    for (auto* observer : observers_) {
        observer->onKill(killer, victim);
    }
}

void World::addNPC(std::shared_ptr<NPC> npc) {
    npcs_.push_back(npc);
}

void World::removeDeadNPCs() {
    npcs_.erase(
        std::remove_if(npcs_.begin(), npcs_.end(),
            [](const std::shared_ptr<NPC>& npc) {
                return !npc->isAlive();
            }),
        npcs_.end()
    );
}

void World::subscribe(Observer* observer) {
    observers_.push_back(observer);
}

void World::unsubscribe(Observer* observer) {
    observers_.erase(
        std::remove(observers_.begin(), observers_.end(), observer),
        observers_.end()
    );
}

void World::printAll() const {
    std::cout << "\n=== NPC List ===\n";
    if (npcs_.empty()) {
        std::cout << "No NPCs\n";
        return;
    }
    
    for (size_t i = 0; i < npcs_.size(); ++i) {
        const auto& npc = npcs_[i];
        std::cout << (i + 1) << ". " << npc->getTypeName() 
                  << " \"" << npc->getName() << "\""
                  << " at " << npc->getPosition()
                  << " [" << (npc->isAlive() ? "Alive" : "Dead") << "]\n";
    }
}

void World::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for writing: " << filename << std::endl;
        return;
    }
    
    for (const auto& npc : npcs_) {
        if (npc->isAlive()) {
            file << NpcFactory::typeToString(npc->getType()) << " "
                 << npc->getName() << " "
                 << npc->getPosition().x << " "
                 << npc->getPosition().y << "\n";
        }
    }
}

void World::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file for reading: " << filename << std::endl;
        return;
    }
    
    npcs_.clear();
    
    std::string typeStr, name;
    int x, y;
    
    while (file >> typeStr >> name >> x >> y) {
        if (x >= 0 && x <= 500 && y >= 0 && y <= 500) {
            auto npc = NpcFactory::createFromString(typeStr, name, x, y);
            npcs_.push_back(npc);
        }
    }
}

void World::startBattle(double battle_range) {
    BattleVisitor visitor(&npcs_, battle_range, &observers_);
    
    // Проходим по всем живым NPC
    for (auto& npc : npcs_) {
        if (npc->isAlive()) {
            visitor.setCurrentNpc(npc.get());
            npc->accept(visitor);
        }
    }
}

size_t World::getAliveCount() const {
    return std::count_if(npcs_.begin(), npcs_.end(),
        [](const std::shared_ptr<NPC>& npc) {
            return npc->isAlive();
        });
}

