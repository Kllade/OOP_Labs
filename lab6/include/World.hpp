#pragma once
#include "NPC.hpp"
#include "Observer.hpp"
#include "BattleVisitor.hpp"
#include "NpcFactory.hpp"
#include <vector>
#include <memory>
#include <string>

// Мир (Subject для Observer pattern)
class World {
private:
    std::vector<std::shared_ptr<NPC>> npcs_;
    std::vector<Observer*> observers_;
    
    void notifyKill(const std::string& killer, const std::string& victim);

public:
    // Добавить NPC
    void addNPC(std::shared_ptr<NPC> npc);
    
    // Удалить мертвых NPC
    void removeDeadNPCs();
    
    // Подписать Observer
    void subscribe(Observer* observer);
    
    // Отписать Observer
    void unsubscribe(Observer* observer);
    
    // Печать всех NPC
    void printAll() const;
    
    // Сохранение в файл
    void saveToFile(const std::string& filename) const;
    
    // Загрузка из файла
    void loadFromFile(const std::string& filename);
    
    // Запуск боевого режима
    void startBattle(double battle_range);
    
    // Получить количество живых NPC
    size_t getAliveCount() const;
    
    // Получить все NPC
    const std::vector<std::shared_ptr<NPC>>& getNPCs() const { return npcs_; }
};

