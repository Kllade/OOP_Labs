#pragma once

// Forward declarations
class Knight;
class Pegasus;
class Dragon;

// Visitor интерфейс для паттерна Visitor
class NpcVisitor {
public:
    virtual ~NpcVisitor() = default;
    virtual void visit(Knight& knight) = 0;
    virtual void visit(Pegasus& pegasus) = 0;
    virtual void visit(Dragon& dragon) = 0;
};

