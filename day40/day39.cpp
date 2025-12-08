#include <iostream>

class iPhone : public Phone { /* ... */ };
class Huawei : public Phone { /* ... */ };

class TechFactory {
public:
    virtual Phone* createPhone() = 0;
    virtual Earphone* createEarphone() = 0;
    virtual ~TechFactory() {}
};

class AppleFactory : public TechFactory {
public:
    Phone* createPhone() override { return new iPhone(); }
    Earphone* createEarphone() override { return new AirPods(); }
};

class HuaweiFactory : public TechFactory {
public:
    Phone* createPhone() override { return new Huawei(); }
    Earphone* createEarphone() override { return new FreeBuds(); }
};

void client_show_ecosystem(TechFactory* factory, const std::string& brand) {
    Phone* phone = factory->createPhone();
    Earphone* earphone = factory->createEarphone();

    std::cout << "--- " << brand << " Ecosystem Products ---" << std::endl;
    phone->show();
    earphone->show();
    std::cout << "---------------------------------" << std::endl;

    delete phone;
    delete earphone;
}

int main() {
    TechFactory* apple_store = new AppleFactory();
    client_show_ecosystem(apple_store, "Apple");
    delete apple_store;

    TechFactory* huawei_store = new HuaweiFactory();
    client_show_ecosystem(huawei_store, "Huawei");
    delete huawei_store;

    return 0;
}