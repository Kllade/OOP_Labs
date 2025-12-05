#include <iostream>
#include <memory>
#include <limits>
#include "World.hpp"
#include "NpcFactory.hpp"
#include "FileLogger.hpp"
#include "ConsoleLogger.hpp"
#include "Point.hpp"

void printMenu() {
    std::cout << "\n=== Dungeon Editor ===\n";
    std::cout << "1. Add NPC\n";
    std::cout << "2. Print all NPCs\n";
    std::cout << "3. Save to file\n";
    std::cout << "4. Load from file\n";
    std::cout << "5. Start battle\n";
    std::cout << "6. Exit\n";
    std::cout << "Choice: ";
}

void addNPC(World& world) {
    std::cout << "\nNPC types:\n";
    std::cout << "1. Knight\n";
    std::cout << "2. Pegasus\n";
    std::cout << "3. Dragon\n";
    std::cout << "Type: ";
    
    int type;
    std::cin >> type;
    
    if (type < 1 || type > 3) {
        std::cout << "Invalid type!\n";
        return;
    }
    
    std::cout << "Name: ";
    std::string name;
    std::cin >> name;
    
    std::cout << "X coordinate (0-500): ";
    int x;
    std::cin >> x;
    if (x < 0 || x > 500) {
        std::cout << "Invalid X coordinate!\n";
        return;
    }
    
    std::cout << "Y coordinate (0-500): ";
    int y;
    std::cin >> y;
    if (y < 0 || y > 500) {
        std::cout << "Invalid Y coordinate!\n";
        return;
    }
    
    NpcType npcType = static_cast<NpcType>(type - 1);
    auto npc = NpcFactory::create(npcType, name, Point<int>(x, y));
    world.addNPC(npc);
    
    std::cout << "NPC added successfully!\n";
}

void startBattle(World& world) {
    std::cout << "\nBattle range: ";
    double range;
    std::cin >> range;
    
    if (range < 0) {
        std::cout << "Invalid range!\n";
        return;
    }
    
    std::cout << "\nStarting battle with range " << range << "...\n";
    world.startBattle(range);
    world.removeDeadNPCs();
    std::cout << "Battle finished. Alive NPCs: " << world.getAliveCount() << "\n";
}

int main() {
    World world;
    
    // Подписываем наблюдателей
    FileLogger fileLogger("log.txt");
    ConsoleLogger consoleLogger;
    world.subscribe(&fileLogger);
    world.subscribe(&consoleLogger);
    
    int choice;
    do {
        printMenu();
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                addNPC(world);
                break;
            case 2:
                world.printAll();
                break;
            case 3: {
                std::cout << "Filename: ";
                std::string filename;
                std::cin >> filename;
                world.saveToFile(filename);
                std::cout << "Saved!\n";
                break;
            }
            case 4: {
                std::cout << "Filename: ";
                std::string filename;
                std::cin >> filename;
                world.loadFromFile(filename);
                std::cout << "Loaded!\n";
                break;
            }
            case 5:
                startBattle(world);
                break;
            case 6:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 6);
    
    return 0;
}

