
#include "dragon.h"
#include <iostream>

// геттеры
std::string Dragon::getName() const { return name; }
int Dragon::getTailLength() const { return tail_length; }
int Dragon::getAge() const { return age; }
int Dragon::getMagicPower() const { return magic_power; }
bool Dragon::isRegistered() const { return is_registered; }
Dragon::Type Dragon::getType() const { return type; }

Dragon::AgeCategory Dragon::getAgeCategory() const {
    if (age <= 5) return AgeCategory::BABY;
    if (age <= 20) return AgeCategory::YOUNG;
    if (age <= 100) return AgeCategory::ADULT;
    return AgeCategory::ANCIENT;
}

// конструкторы
void Dragon::registerDragon(const std::string& name, int tail, int age, int magic, Type type) {
    this->name = name;
    tail_length = tail;
    this->age = age;
    magic_power = magic;
    this->type = type;
    is_registered = true;
}

Dragon::Dragon() :
    name(""), tail_length(1), age(0), magic_power(0), is_registered(false), type(Type::FIRE) {}

// YOUR CODE HERE (7 METHODS)

void Dragon::train() {
    magic_power += 10;
    if (magic_power > 100) {
        magic_power = 100;
    }
}

void Dragon::ageUp() { age++; }

void Dragon::printInfo() const {
    std::cout << "Dragon " << name << ":\n";

    std::cout << "Type: ";
    switch (type) {
        case Type::FIRE:
            std::cout << "FIRE\n";
            break;
        case Type::ICE:
            std::cout << "ICE\n";
            break;
        case Type::FOREST:
            std::cout << "FOREST\n";
            break;
        case Type::GOLDEN:
            std::cout << "GOLDEN\n";
            break;
    }

    std::cout << "Age_category: ";
    switch (getAgeCategory()) {
        case AgeCategory::BABY:
            std::cout << "BABY\n";
            break;
        case AgeCategory::YOUNG:
            std::cout << "YOUNG\n";
            break;
        case AgeCategory::ADULT:
            std::cout << "ADULT\n";
            break;
        case AgeCategory::ANCIENT:
            std::cout << "ANCIENT\n";
            break;
    }

    std::cout << "Tail: " << tail_length << " meter(s)\n";
    std::cout << "Magic power: " << magic_power << "/100\n";
    std::cout << "Status: " << (is_registered ? "registered" : "not registered") << "\n";

    std::cout << "Special ability: ";
    if (type == Type::FIRE && canBreatheFire()) {
        std::cout << "can breathe fire";
    } else {
        std::cout << "cannot breathe fire";
    }
    std::cout << "\n";
}

bool Dragon::canBreatheFire() const { return type == Type::FIRE && magic_power >= 50; }

void Dragon::rename(const std::string& newName) { name = newName; }

void Dragon::celebrateBirthday() {
    ageUp();
    magic_power += 5;
    if (magic_power > 100) {
        magic_power = 100;
    }
}

bool Dragon::canFight(const Dragon& other) const {
    return magic_power > other.magic_power && tail_length > other.tail_length;
}
