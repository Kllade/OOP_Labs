#pragma once
#include "Point.hpp"
#include "NpcVisitor.hpp"
#include <string>

enum class NpcType {
    KNIGHT,
    PEGASUS,
    DRAGON
};

// Базовый класс NPC
class NPC {
public:
    virtual ~NPC() = default;
    
    // Visitor pattern
    virtual void accept(NpcVisitor& visitor) = 0;
    
    // Геттеры
    virtual std::string getName() const = 0;
    virtual Point<int> getPosition() const = 0;
    virtual NpcType getType() const = 0;
    virtual bool isAlive() const = 0;
    
    // Установка позиции
    virtual void setPosition(const Point<int>& pos) = 0;
    
    // Убить NPC
    virtual void kill() = 0;
    
    // Атака другого NPC (возвращает true если атака успешна)
    virtual bool attack(NPC* other) = 0;
    
    // Проверка, может ли атаковать другого NPC
    virtual bool canAttack(NPC* other) const = 0;
    
    // Получить строковое представление типа
    virtual std::string getTypeName() const = 0;
};

