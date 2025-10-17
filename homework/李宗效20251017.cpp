#include <iostream>
#include <string>

class Student {
public:
    std::string name;

    Student(const std::string &name, int score) : name(name), score(score) {
        std::cout << "学生 " << name << " 被创建了！" << std::endl;
    }

    ~Student() {
        std::cout << "析构函数" << name << score << std::endl;
    }

    int getScore() { return score; }

private:
    int score = 0;
};

int main() {
    Student s1("张三", 80);
    Student s2("李四", 90);
    Student *s3 = new Student("王五", 75);

    std::cout << "sizeof(s1): " << sizeof(s1) << std::endl;
    std::cout << "sizeof(s2): " << sizeof(s2) << std::endl;
    std::cout << "sizeof(s3): " << sizeof(s3) << std::endl; // 指针大小，通常是4或8字节

    double average = (s1.getScore() + s2.getScore() + s3->getScore()) / 3.0;
    std::cout << "平均成绩: " << average << std::endl;

    delete s3;

    return 0;
}
