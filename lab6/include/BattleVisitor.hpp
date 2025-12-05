#pragma once
#include "NpcVisitor.hpp"
#include "NPC.hpp"
#include "Observer.hpp"
#include <vector>
#include <memory>

// Forward declarations
class Knight;
class Pegasus;
class Dragon;

// Visitor для проведения боевых действий
class BattleVisitor : public NpcVisitor {
private:
    std::vector<std::shared_ptr<NPC>>* npcs_;
    double battle_range_;
    std::vector<Observer*>* observers_;
    NPC* current_npc_;

public:
    BattleVisitor(std::vector<std::shared_ptr<NPC>>* npcs, 
                  double battle_range,
                  std::vector<Observer*>* observers);
    
    void visit(Knight& knight) override;
    void visit(Pegasus& pegasus) override;
    void visit(Dragon& dragon) override;
    
    void setCurrentNpc(NPC* npc) { current_npc_ = npc; }
};

