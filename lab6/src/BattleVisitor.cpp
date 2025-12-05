#include "../include/BattleVisitor.hpp"
#include "../include/Knight.hpp"
#include "../include/Pegasus.hpp"
#include "../include/Dragon.hpp"
#include <algorithm>
#include <cmath>

BattleVisitor::BattleVisitor(std::vector<std::shared_ptr<NPC>>* npcs,
                             double battle_range,
                             std::vector<Observer*>* observers)
    : npcs_(npcs), battle_range_(battle_range), observers_(observers), current_npc_(nullptr) {}

void BattleVisitor::visit(Knight& knight) {
    current_npc_ = &knight;
    
    if (!knight.isAlive()) return;
    
    for (auto& other : *npcs_) {
        if (!other || !other->isAlive() || other.get() == &knight) {
            continue;
        }
        
        double dist = knight.getPosition().distance(other->getPosition());
        if (dist <= battle_range_ && knight.canAttack(other.get())) {
            if (knight.attack(other.get())) {
                // Уведомляем наблюдателей
                for (auto* obs : *observers_) {
                    obs->onKill(knight.getName(), other->getName());
                }
            }
        }
    }
}

void BattleVisitor::visit(Pegasus& pegasus) {
    current_npc_ = &pegasus;
    // Пегас никого не атакует, но может быть атакован
}

void BattleVisitor::visit(Dragon& dragon) {
    current_npc_ = &dragon;
    
    if (!dragon.isAlive()) return;
    
    for (auto& other : *npcs_) {
        if (!other || !other->isAlive() || other.get() == &dragon) {
            continue;
        }
        
        double dist = dragon.getPosition().distance(other->getPosition());
        if (dist <= battle_range_ && dragon.canAttack(other.get())) {
            if (dragon.attack(other.get())) {
                // Уведомляем наблюдателей
                for (auto* obs : *observers_) {
                    obs->onKill(dragon.getName(), other->getName());
                }
            }
        }
    }
}

