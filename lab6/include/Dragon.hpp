#pragma once
#include "NPC.hpp"
#include "NpcVisitor.hpp"
#include "Point.hpp"
#include <string>

class Dragon : public NPC {
private:
    std::string name_;
    Point<int> position_;
    bool alive_;

public:
    Dragon(const std::string& name, const Point<int>& position)
        : name_(name), position_(position), alive_(true) {}
    
    void accept(NpcVisitor& visitor) override {
        visitor.visit(*this);
    }
    
    std::string getName() const override { return name_; }
    Point<int> getPosition() const override { return position_; }
    NpcType getType() const override { return NpcType::DRAGON; }
    bool isAlive() const override { return alive_; }
    
    void setPosition(const Point<int>& pos) override { position_ = pos; }
    void kill() override { alive_ = false; }
    
    bool attack(NPC* other) override {
        if (!other || !other->isAlive() || !isAlive()) {
            return false;
        }
        // Дракон ест только пегасов
        if (other->getType() == NpcType::PEGASUS) {
            other->kill();
            return true;
        }
        return false;
    }
    
    bool canAttack(NPC* other) const override {
        if (!other || !other->isAlive() || !isAlive()) {
            return false;
        }
        // Дракон может атаковать только пегасов
        return other->getType() == NpcType::PEGASUS;
    }
    
    std::string getTypeName() const override { return "Dragon"; }
};

