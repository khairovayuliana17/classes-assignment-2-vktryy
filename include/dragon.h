#include <string>
// declare Dragon class here
class Dragon {
  public:
    // YOUR CODE HERE
    enum class Type { FIRE, ICE, FOREST, GOLDEN };

    enum class AgeCategory { BABY, YOUNG, ADULT, ANCIENT };

    Dragon();
    void registerDragon(const std::string& name, int tail_length, int age, int magic, Type type);
    void registerDragon();
    // МЕТОДЫ ДЛЯ ТВОЕЙ РЕАЛИЗАЦИИ
    void train();
    void ageUp();
    void printInfo() const;
    bool canBreatheFire() const;
    void rename(const std::string& newName);
    void celebrateBirthday();
    bool canFight(const Dragon& other) const;

    // геттеры (не обращай внимания, они нужны мне для написания тестов)
    std::string getName() const;
    int getTailLength() const;
    int getAge() const;
    int getMagicPower() const;
    bool isRegistered() const;
    Type getType() const;
    AgeCategory getAgeCategory() const;

  private:
    // YOUR CODE HERE
    std::string name = "";
    int tail_length = 1;
    int age = 0;
    int magic_power = 0;
    bool is_registered = false;
    Type type = Type::FIRE;
};
