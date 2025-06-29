
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
