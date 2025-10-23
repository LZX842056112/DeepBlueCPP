#include <iostream>
#include <string>

class Animal {
public:
    Animal(const std::string &name, const std::string &type) : name(name), type(type) {
    }

    ~Animal() {
        std::cout << "Animal destroyed" << std::endl;
    }

    virtual void MakeSound() const = 0;

    virtual void ShowInfo() const {
        std::cout << "Animal name: " << name << ", type: " << type << std::endl;
    }

protected:
    std::string name;
    std::string type;
};

class Cat : public Animal {
public:
    Cat(const std::string &name, const std::string &type) : Animal(name, type) {
    }

    ~Cat() {
        std::cout << "Cat " << name << " destroyed" << std::endl;
    }

    void MakeSound() const override {
        std::cout << "Meow Meow Meow..." << std::endl;
    }

    void ShowInfo() const override {
        std::cout << "Cat name: " << name << ", type: " << type << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(const std::string &name, const std::string &type) : Animal(name, type) {
    }

    ~Dog() {
        std::cout << "Dog " << name << " destroyed" << std::endl;
    }

    void MakeSound() const override {
        std::cout << "Woof Woof Woof..." << std::endl;
    }

    void ShowInfo() const override {
        std::cout << "Dog name: " << name << ", type: " << type << std::endl;
    }
};

class Bird : public Animal {
public:
    Bird(const std::string &name, const std::string &type) : Animal(name, type) {
    }

    ~Bird() {
        std::cout << "Bird " << name << " destroyed" << std::endl;
    }

    void MakeSound() const override {
        std::cout << "Tweet Tweet Tweet..." << std::endl;
    }

    void ShowInfo() const override {
        std::cout << "Bird name: " << name << ", type: " << type << std::endl;
    }
};

int main() {
    Animal *zoo[3];
    Dog dog("d1", "dog");
    Cat cat("c1", "cat");
    Bird bird("b1", "bird");
    zoo[0] = &dog;
    zoo[1] = &cat;
    zoo[2] = &bird;

    for (const auto &animal: zoo) {
        animal->MakeSound();
        animal->ShowInfo();
        std::cout << "---------------------" << std::endl;
    }
    return 0;
}
