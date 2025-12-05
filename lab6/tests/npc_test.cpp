#include <gtest/gtest.h>
#include "NPC.hpp"
#include "Knight.hpp"
#include "Pegasus.hpp"
#include "Dragon.hpp"
#include "NpcFactory.hpp"
#include "World.hpp"
#include "Point.hpp"
#include <memory>

TEST(NPCTest, KnightCreation) {
    auto knight = std::make_shared<Knight>("Arthur", Point<int>(100, 100));
    EXPECT_EQ(knight->getName(), "Arthur");
    EXPECT_EQ(knight->getType(), NpcType::KNIGHT);
    EXPECT_TRUE(knight->isAlive());
}

TEST(NPCTest, KnightKillsDragon) {
    auto knight = std::make_shared<Knight>("Arthur", Point<int>(100, 100));
    auto dragon = std::make_shared<Dragon>("Smaug", Point<int>(100, 100));
    
    EXPECT_TRUE(knight->canAttack(dragon.get()));
    knight->attack(dragon.get());
    EXPECT_FALSE(dragon->isAlive());
}

TEST(NPCTest, DragonEatsPegasus) {
    auto dragon = std::make_shared<Dragon>("Smaug", Point<int>(100, 100));
    auto pegasus = std::make_shared<Pegasus>("Peggy", Point<int>(100, 100));
    
    EXPECT_TRUE(dragon->canAttack(pegasus.get()));
    dragon->attack(pegasus.get());
    EXPECT_FALSE(pegasus->isAlive());
}

TEST(NPCTest, PegasusDoesNotAttack) {
    auto pegasus = std::make_shared<Pegasus>("Peggy", Point<int>(100, 100));
    auto knight = std::make_shared<Knight>("Arthur", Point<int>(100, 100));
    
    EXPECT_FALSE(pegasus->canAttack(knight.get()));
    EXPECT_FALSE(pegasus->attack(knight.get()));
    EXPECT_TRUE(knight->isAlive());
}

TEST(NPCTest, KnightDoesNotAttackPegasus) {
    auto knight = std::make_shared<Knight>("Arthur", Point<int>(100, 100));
    auto pegasus = std::make_shared<Pegasus>("Peggy", Point<int>(100, 100));
    
    EXPECT_FALSE(knight->canAttack(pegasus.get()));
    EXPECT_FALSE(knight->attack(pegasus.get()));
    EXPECT_TRUE(pegasus->isAlive());
}

TEST(NPCTest, DragonDoesNotAttackKnight) {
    auto dragon = std::make_shared<Dragon>("Smaug", Point<int>(100, 100));
    auto knight = std::make_shared<Knight>("Arthur", Point<int>(100, 100));
    
    EXPECT_FALSE(dragon->canAttack(knight.get()));
    EXPECT_FALSE(dragon->attack(knight.get()));
    EXPECT_TRUE(knight->isAlive());
}

TEST(FactoryTest, CreateNPCs) {
    auto knight = NpcFactory::create(NpcType::KNIGHT, "Arthur", Point<int>(50, 50));
    auto pegasus = NpcFactory::create(NpcType::PEGASUS, "Peggy", Point<int>(100, 100));
    auto dragon = NpcFactory::create(NpcType::DRAGON, "Smaug", Point<int>(200, 200));
    
    EXPECT_EQ(knight->getType(), NpcType::KNIGHT);
    EXPECT_EQ(pegasus->getType(), NpcType::PEGASUS);
    EXPECT_EQ(dragon->getType(), NpcType::DRAGON);
}

TEST(FactoryTest, CreateFromString) {
    auto knight = NpcFactory::createFromString("Knight", "Arthur", 50, 50);
    auto pegasus = NpcFactory::createFromString("Pegasus", "Peggy", 100, 100);
    auto dragon = NpcFactory::createFromString("Dragon", "Smaug", 200, 200);
    
    EXPECT_EQ(knight->getType(), NpcType::KNIGHT);
    EXPECT_EQ(pegasus->getType(), NpcType::PEGASUS);
    EXPECT_EQ(dragon->getType(), NpcType::DRAGON);
}

TEST(WorldTest, AddAndPrint) {
    World world;
    auto knight = NpcFactory::create(NpcType::KNIGHT, "Arthur", Point<int>(50, 50));
    world.addNPC(knight);
    
    EXPECT_EQ(world.getAliveCount(), 1);
}

TEST(WorldTest, SaveAndLoad) {
    World world1;
    world1.addNPC(NpcFactory::create(NpcType::KNIGHT, "Arthur", Point<int>(50, 50)));
    world1.addNPC(NpcFactory::create(NpcType::PEGASUS, "Peggy", Point<int>(100, 100)));
    
    world1.saveToFile("test_save.txt");
    
    World world2;
    world2.loadFromFile("test_save.txt");
    
    EXPECT_EQ(world2.getAliveCount(), 2);
}

TEST(WorldTest, BattleWithRange) {
    World world;
    world.addNPC(NpcFactory::create(NpcType::KNIGHT, "Arthur", Point<int>(100, 100)));
    world.addNPC(NpcFactory::create(NpcType::DRAGON, "Smaug", Point<int>(100, 100)));
    
    ConsoleLogger logger;
    world.subscribe(&logger);
    
    world.startBattle(10.0);
    world.removeDeadNPCs();
    
    // Дракон должен быть убит рыцарем
    EXPECT_EQ(world.getAliveCount(), 1);
}

TEST(PointTest, Distance) {
    Point<int> p1(0, 0);
    Point<int> p2(3, 4);
    
    double dist = p1.distance(p2);
    EXPECT_DOUBLE_EQ(dist, 5.0);
}

