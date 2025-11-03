#include <iostream>
#include <fstream>

class Person {
public:
    explicit Person(const int age) : age(age) {
        std::cout << "Person构造" << std::endl;
    }

    ~Person() {
        std::cout << "Person析构" << std::endl;
    }

    int age;
};

class Student : virtual public Person {
public:
    Student(const int age, const int id) : Person(age), student_id(id) {
        std::cout << "Student构造" << std::endl;
    }

    ~Student() {
        std::cout << "Student析构" << std::endl;
    }

    int student_id;
};

class Teacher : virtual public Person {
public:
    Teacher(const int age, const int id) : Person(age), teacher_id(id) {
        std::cout << "Teacher构造" << std::endl;
    }

    ~Teacher() {
        std::cout << "Student析构" << std::endl;
    }

    int teacher_id;
};

class TeacAssit : public Student, public Teacher {
public:
    TeacAssit(const int age, const int s_id, const int t_id) : Person(age), Student(age, s_id), Teacher(age, t_id) {
        std::cout << "TeacAssit构造" << std::endl;
    }

    ~TeacAssit() {
        std::cout << "TeacAssit析构" << std::endl;
    }
};

class Animal {
public:
    Animal(int id) : id(id) {
    }

    void sound() {
    }

    int id;
};

class Cat : public Animal {
public:
    Cat() : Animal(0) {
    }

    void sound() {
        std::cout << "meow  ..." << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog() : Animal(1) {
    }

    void sound() {
        std::cout << "wang wang ..." << std::endl;
    }
};

class Durk : public Animal {
public:
    Durk() : Animal(2) {
    }

    void sound() {
        std::cout << "gua gua ..." << std::endl;
    }
};

void business_function(Animal *ptr) {
    if (ptr->id == 1) {
        ((Dog *) (ptr))->sound();
    } else if (ptr->id == 0) {
        ((Cat *) (ptr))->sound();
    } else if (ptr->id == 2) {
        ((Durk *) (ptr))->sound();
    }
}

class Animal2 {
public:
    virtual void sound() {
        std::cout << "Animal sound ..." << std::endl;
    }
};

class Cat2 : public Animal2 {
public:
    void sound() override {
        std::cout << "meow  ..." << std::endl;
    }
};

class Dog2 : public Animal2 {
public:
    void sound() override {
        std::cout << "wang wang ..." << std::endl;
    }
};

class Durk2 : public Animal2 {
public:
    void sound() override {
        std::cout << "gua gua ..." << std::endl;
    }
};

void business_function2(Animal2 *ptr) {
    ptr->sound();
}

void business_function3(Animal2 &ptr) {
    ptr.sound();
}

class Shape {
public:
    //虚函数
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    TeacAssit ta(18, 1001, 9001);
    std::cout << ta.student_id << std::endl;
    std::cout << ta.teacher_id << std::endl;
    std::cout << ta.Student::age << std::endl;
    std::cout << ta.Teacher::age << std::endl;
    std::cout << ta.age << std::endl;
    std::cout << &ta.age << std::endl;
    std::cout << &ta.Student::age << std::endl;
    std::cout << &ta.Teacher::age << std::endl;
    std::cout << "*********************" << std::endl;

    Dog dog;
    Cat cat;
    Durk durk;
    business_function(&cat);
    business_function(&dog);
    business_function(&durk);
    std::cout << "*********************" << std::endl;

    Animal2 animal;
    Dog2 dog2;
    Cat2 cat2;
    Durk2 durk2;
    business_function2(&animal);
    business_function2(&cat2);
    business_function2(&dog2);
    business_function2(&durk2);
    business_function3(cat2);
    std::cout << "*********************" << std::endl;

    Shape *shape1 = new Circle();
    Shape *shape2 = new Square();
    shape1->draw(); // 调用 Circle::draw()
    shape2->draw(); // 调用 Square::draw()
    delete shape1;
    delete shape2;
    std::cout << "*********************" << std::endl;

    return 0;
}
