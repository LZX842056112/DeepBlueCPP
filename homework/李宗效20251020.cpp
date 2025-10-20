#include <iostream>
#include <string>

class Employee {
public:
    Employee(const int id, const std::string &name, const int dep) : id(id), name(name), dep(dep) {
        std::cout << "Employee: 工号=" << id << "名字=" << name << "部门=" << dep << std::endl;
    }

    ~Employee() {
        std::cout << "Employee: 工号=" << id << "退出" << std::endl;
    }

    virtual double calculateSalary(double base) {
        return base;
    }

protected:
    int id;
    std::string name;
    int dep;
};

class Manager : public Employee {
public:
    Manager(const double bonus, const Employee &employee) : Employee(employee), bonus(bonus) {
        std::cout << "Manager: 工号=" << id << "名字=" << name << "部门=" << dep << std::endl;
    }

    ~Manager() {
        std::cout << "Manager: 工号=" << id << "退出" << std::endl;
    }

    double calculateSalary(double base) override {
        return base + bonus;
    }

private:
    double bonus;
};

class Salesperson : public Employee {
public:
    Salesperson(const double salesVolume, const double commissionRate, const Employee &employee) : Employee(employee),
        salesVolume(salesVolume),
        commissionRate(commissionRate) {
        std::cout << "Salesperson: 工号=" << id << "名字=" << name << "部门=" << dep << std::endl;
    }

    ~Salesperson() {
        std::cout << "Salesperson: 工号=" << id << "退出" << std::endl;
    }

    double calculateSalary(double base) override {
        return base + salesVolume * commissionRate;
    }

private:
    double salesVolume;
    double commissionRate;
};

int main() {
    Employee employee(1, "Bob", 1);
    double salary = employee.calculateSalary(1000);
    std::cout << salary << std::endl;

    Employee employee2(2, "Lucy", 2);
    Manager manager(400, employee2);
    salary = manager.calculateSalary(1000);
    std::cout << salary << std::endl;

    Employee employee3(3, "Tom", 3);
    Salesperson salesperson(300, 0.5, employee3);
    salary = salesperson.calculateSalary(1000);
    std::cout << salary << std::endl;

    return 0;
}
