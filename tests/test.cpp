#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dragon.h"

TEST_CASE("Type checks for Dragon fields") {
    SECTION("Check field types") {
        static_assert(
            std::is_same_v<decltype(Dragon{}.getName()), std::string>,
            "name field should be std::string");

        static_assert(
            std::is_same_v<decltype(Dragon{}.getTailLength()), int>,
            "tail_length field should be int");

        static_assert(std::is_same_v<decltype(Dragon{}.getAge()), int>, "age field should be int");

        static_assert(
            std::is_same_v<decltype(Dragon{}.getMagicPower()), int>,
            "magic_power field should be int");

        static_assert(
            std::is_same_v<decltype(Dragon{}.isRegistered()), bool>,
            "is_registered field should be bool");

        static_assert(
            std::is_same_v<decltype(Dragon{}.getType()), Dragon::Type>,
            "type field should be Dragon::Type");
    }
}

TEST_CASE("Class initialization checks") {
    SECTION("Default constructor values") {
        Dragon d;
        REQUIRE(d.getName() == "");
        REQUIRE(d.getTailLength() == 1);
        REQUIRE(d.getAge() == 0);
        REQUIRE(d.getMagicPower() == 0);
        REQUIRE_FALSE(d.isRegistered());
        REQUIRE(d.getType() == Dragon::Type::FIRE);
    }
}
TEST_CASE("New dragon is not registered by default") {
    Dragon d;
    REQUIRE_FALSE(d.isRegistered());
}

TEST_CASE("Dragon can breathe fire only when conditions met") {
    Dragon d;

    SECTION("Fire dragon with sufficient power") {
        d.registerDragon("Firestorm", 200, 15, 60, Dragon::Type::FIRE);
        REQUIRE(d.canBreatheFire());
    }

    SECTION("Fire dragon with insufficient power") {
        d.registerDragon("Smolder", 180, 10, 40, Dragon::Type::FIRE);
        REQUIRE_FALSE(d.canBreatheFire());
    }

    SECTION("Non-fire dragon") {
        d.registerDragon("Frostbite", 150, 20, 80, Dragon::Type::ICE);
        REQUIRE_FALSE(d.canBreatheFire());
    }
}

TEST_CASE("Dragon training increases magic power") {
    Dragon d;
    d.registerDragon("Spark", 90, 5, 40, Dragon::Type::GOLDEN);

    SECTION("Normal training") {
        d.train();
        REQUIRE(d.getMagicPower() == 50);
    }

    SECTION("Training doesn't exceed maximum") {
        d.registerDragon("Mighty", 200, 30, 95, Dragon::Type::FIRE);
        d.train();
        REQUIRE(d.getMagicPower() == 100);
        d.train();
        REQUIRE(d.getMagicPower() == 100);
    }
}

TEST_CASE("Dragon aging changes age category") {
    Dragon d;

    SECTION("Baby dragon (0-5 years)") {
        d.registerDragon("Tiny", 50, 3, 10, Dragon::Type::FOREST);
        REQUIRE(d.getAgeCategory() == Dragon::AgeCategory::BABY);
    }

    SECTION("Young dragon (6-20 years)") {
        d.registerDragon("Teen", 80, 15, 30, Dragon::Type::ICE);
        REQUIRE(d.getAgeCategory() == Dragon::AgeCategory::YOUNG);
    }

    SECTION("Age progression") {
        d.registerDragon("Grower", 100, 4, 30, Dragon::Type::FOREST);
        REQUIRE(d.getAgeCategory() == Dragon::AgeCategory::BABY);

        d.ageUp();
        REQUIRE(d.getAgeCategory() == Dragon::AgeCategory::BABY);

        d.ageUp();
        REQUIRE(d.getAgeCategory() == Dragon::AgeCategory::YOUNG);
    }
}

TEST_CASE("Dragon registration sets correct properties") {
    Dragon d;
    d.registerDragon("Flame", 150, 10, 75, Dragon::Type::FIRE);

    REQUIRE(d.getName() == "Flame");
    REQUIRE(d.getTailLength() == 150);
    REQUIRE(d.getAge() == 10);
    REQUIRE(d.getMagicPower() == 75);
    REQUIRE(d.getType() == Dragon::Type::FIRE);
    REQUIRE(d.isRegistered());
}

TEST_CASE("The methods work correctly") {
    Dragon d1, d2;
    d1.registerDragon("Draco", 200, 10, 70, Dragon::Type::FIRE);
    d2.registerDragon("Frost", 150, 15, 60, Dragon::Type::ICE);

    SECTION("Renaming") {
        d1.rename("Dragonius");
        REQUIRE(d1.getName() == "Dragonius");
    }

    SECTION("Birthday celebration") {
        int old_age = d1.getAge();
        int old_power = d1.getMagicPower();

        d1.celebrateBirthday();

        REQUIRE(d1.getAge() == old_age + 1);
        REQUIRE(d1.getMagicPower() == old_power + 5);
    }

    SECTION("Fight comparison") {
        REQUIRE(d1.canFight(d2));
        REQUIRE_FALSE(d2.canFight(d1));
    }
}
