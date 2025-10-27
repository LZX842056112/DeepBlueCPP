#include <iostream>
#include <map>

class Phonebook {
public:
    // 可根据 ID 查询电话号码
    std::string findByID(const int id) {
        const auto it = phones.find(id);
        if (it == phones.end()) {
            std::cerr << "查询不到联系人的ID!" << std::endl;
            return "";
        }
        return it->second;
    }

    // 能够新增加
    bool add(int id, const std::string &number) {
        const auto it = phones.find(id);
        if (it != phones.end()) {
            std::cerr << "联系人的ID已存在，请勿重复添加!" << std::endl;
            return false;
        }
        phones[id] = number;
        std::cerr << "增加成功!" << std::endl;
        return true;
    }

    // 能够修改
    bool updateByID(const int id, const std::string &number) {
        const auto it = phones.find(id);
        if (it == phones.end()) {
            std::cerr << "联系人的ID不存在,无法修改!" << std::endl;
            return false;
        }
        it->second = number;
        std::cerr << "修改成功!" << std::endl;
        return true;
    }

    //能够删除
    bool deleteByID(const int id) {
        const auto it = phones.find(id);
        if (it == phones.end()) {
            std::cerr << "联系人的ID不存在,无法删除!" << std::endl;
            return false;
        }
        phones.erase(it);
        std::cerr << "删除成功!" << std::endl;
        return true;
    }

private:
    std::map<int, std::string> phones;
};

int main() {
    Phonebook p;
    p.add(3, "13000000003");
    std::cout << p.findByID(3) << std::endl;

    p.updateByID(3, "13000003333");
    std::cout << p.findByID(3) << std::endl;

    p.add(3, "13000000003");
    p.deleteByID(3);

    p.findByID(3);
    p.updateByID(3, "13000003333");

    return 0;
}
