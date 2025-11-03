#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

class Complex {
public:
    Complex(int real, int imag) : real(real), imag(imag) {
    }

    friend Complex operator+(const Complex &c1, const Complex &c2);

    friend std::ostream &operator<<(std::ostream &os, const Complex &c);

private:
    int real;
    int imag;
};

Complex operator+(const Complex &c1, const Complex &c2) {
    return {c1.real + c2.real, c1.imag + c2.imag};
}

std::ostream &operator<<(std::ostream &os, const Complex &c) {
    os << "{real: " << c.real << ", imag: " << c.imag << "}";
    return os;
}

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {
    }

    friend void printWidth(Box &b); // friend 声明友元函数
};

void printWidth(Box &b) {
    std::cout << "Width of box: " << b.width << std::endl; // 访问私有成员
}

class Cuboid2 {
private:
    double length, width, height;

public:
    Cuboid2(double l, double w, double h) : length(l), width(w), height(h) {
    }

    // 友元函数声明
    friend double calculateVolume(const Cuboid2 &c);

    friend void updateDimensions(Cuboid2 &c, double l, double w, double h);
};

// 友元函数定义
double calculateVolume(const Cuboid2 &c) {
    return c.length * c.width * c.height; // 访问私有成员
}

void updateDimensions(Cuboid2 &c, double l, double w, double h) {
    c.length = l;
    c.width = w;
    c.height = h; // 修改私有成员
}

class ClassA {
private:
    int privateMember;

public:
    ClassA() : privateMember(42) {
    }

    friend class ClassB; // ClassB 将是 ClassA 的友元类
};

class ClassB {
public:
    void displayPrivateMember(const ClassA &a) {
        std::cout << "Private member of ClassA: " << a.privateMember << std::endl;
    }
};

class Parent {
private:
    int parentPrivate;

protected:
    int parentProtected;

public:
    Parent() : parentPrivate(10), parentProtected(20) {
    }

    friend void friendFunction(Parent &p);
};

void friendFunction(Parent &p) {
    std::cout << "Parent Private: " << p.parentPrivate << std::endl;
    std::cout << "Parent Protected: " << p.parentProtected << std::endl;
}

class Child : public Parent {
private:
    int childPrivate;

public:
    Child() : Parent(), childPrivate(30) {
    }

    // Note: friendFunction() inherits permission to access Parent's members
    friend void childFriendFunction(Child &c);
};

void childFriendFunction(Child &c) {
    // 可以访问父类的私有和受保护部分
    friendFunction(c);

    // 仅可以访问子类的受保护成员,无法访问子类私有成员
    // std::cout << "Child Private: " << c.parentPrivate << std::endl;
    std::cout << "Child Private: " << c.childPrivate << std::endl;
    std::cout << "Parent Protected Access via Child: " << c.parentProtected << std::endl;
}

class Cuboid {
private:
    double length, width, height;

public:
    Cuboid(double l, double w, double h) : length(l), width(w), height(h) {
    }

    // 友元函数重载 `+` 运算符
    friend Cuboid operator+(const Cuboid &a, const Cuboid &b);

    // 友元函数重载 `<<` 运算符
    friend std::ostream &operator<<(std::ostream &os, const Cuboid &c);
};

// 重载 `+` 运算符
Cuboid operator+(const Cuboid &a, const Cuboid &b) {
    double newLength = a.length + b.length;
    double newWidth = std::max(a.width, b.width);
    double newHeight = std::max(a.height, b.height);
    return Cuboid(newLength, newWidth, newHeight);
}

// 重载 `<<` 运算符
std::ostream &operator<<(std::ostream &os, const Cuboid &c) {
    os << "Cuboid(" << c.length << ", " << c.width << ", " << c.height << ")";
    return os;
}

struct Person {
    std::string name;
    int age;
    std::string city;
};

// 解析CSV格式的字符串
std::vector<Person> parseCSV(const std::string &csvData) {
    std::vector<Person> people;
    std::istringstream ss(csvData);
    std::string line;

    // 跳过标题行
    std::getline(ss, line);

    while (std::getline(ss, line)) {
        std::istringstream lineStream(line);
        std::string field;
        std::vector<std::string> fields;

        // 分割每行的字段
        while (std::getline(lineStream, field, ',')) {
            fields.push_back(field);
        }

        if (fields.size() >= 3) {
            Person p;
            p.name = fields[0];
            p.age = std::stoi(fields[1]);
            p.city = fields[2];
            people.push_back(p);
        }
    }

    return people;
}

// 将人员数据转换为HTML表格
std::string toHTMLTable(const std::vector<Person> &people) {
    std::ostringstream html;
    html << "<table border='1'>\n";
    html << "<tr><th>姓名</th><th>年龄</th><th>城市</th></tr>\n";

    for (const auto &p: people) {
        html << "<tr><td>" << p.name
                << "</td><td>" << p.age
                << "</td><td>" << p.city
                << "</td></tr>\n";
    }

    html << "</table>";
    return html.str();
}

int main() {
    Complex c1(1, 2);
    Complex c2(3, 4);
    Complex result = c1 + c2;
    std::cout << result << std::endl;
    std::cout << "*********************************" << std::endl;

    Box box(10.0);
    printWidth(box);
    std::cout << "*********************************" << std::endl;

    Cuboid2 c3(2.0, 3.0, 4.0);
    std::cout << "Initial Volume of c1: " << calculateVolume(c3) << std::endl;
    updateDimensions(c3, 5.0, 5.0, 5.0);
    std::cout << "Updated Volume of c1: " << calculateVolume(c3) << std::endl;
    std::cout << "*********************************" << std::endl;

    ClassA a;
    ClassB b;
    b.displayPrivateMember(a);
    std::cout << "*********************************" << std::endl;

    Child c;
    childFriendFunction(c);
    std::cout << "*********************************" << std::endl;

    Cuboid c4(3.0, 2.0, 1.0);
    Cuboid c5(4.0, 1.0, 5.0);
    Cuboid result2 = c4 + c5;

    std::cout << "Cuboid 1: " << c4 << "\n";
    std::cout << "Cuboid 2: " << c5 << "\n";
    std::cout << "Result: " << result2 << "\n";
    std::cout << "*********************************" << std::endl;

    int age;
    std::cout << "请输入您的年龄："; // 提示用户输入
    std::cin >> age; // 从标准输入读取整数
    std::cout << "您的年龄是：" << age << std::endl; // 输出到标准输出
    if (age < 0) {
        std::cerr << "错误：年龄不能为负数！" << std::endl; // 输出错误信息
    } else {
        std::clog << "日志：用户输入了有效年龄 " << age << std::endl; // 记录日志
    }
    std::cout << "*********************************" << std::endl;

    char ch;
    std::cout << "请输入一个字符：";
    std::cin.get(ch); // 读取一个字符（包括空格）
    std::cout << "您输入的字符是：" << ch << std::endl;
    char buffer[80];
    std::cout << "请输入一行文本：";
    std::cin.ignore(); // 清除缓冲区中的换行符
    std::cin.getline(buffer, 80); // 读取一行文本
    std::cout << "您输入的文本是：" << buffer << std::endl;
    // 使用 string 和 getline() 读取一行
    std::string line;
    std::cout << "请输入另一行文本 (string): ";
    std::getline(std::cin, line); // string版本的getline不需要ignore()
    std::cout << "您输入的文本是: " << line << std::endl;
    std::cout << "*********************************" << std::endl;

    char ch1 = 'A';
    std::cout.put(ch1); // 输出字符 'A'
    std::cout << std::endl;
    const char *str = "Hello, world!";
    std::cout.write(str, 5); // 输出字符串的前 5 个字符 "Hello"
    std::cout << std::endl;
    std::cout << "*********************************" << std::endl;

    // 格式化输出学生成绩表格
    std::cout << std::left << std::setw(15) << "姓名"
            << std::setw(8) << "语文"
            << std::setw(8) << "数学"
            << std::setw(8) << "英语"
            << std::setw(10) << "平均分" << std::endl;

    std::cout << std::string(49, '-') << std::endl;
    std::cout << std::left << std::setw(15) << "张三"
            << std::setw(8) << 85
            << std::setw(8) << 92
            << std::setw(8) << 78
            << std::fixed << std::setprecision(2) << std::setw(10) << (85 + 92 + 78) / 3.0 << std::endl;

    std::cout << std::left << std::setw(15) << "李四"
            << std::setw(8) << 76
            << std::setw(8) << 88
            << std::setw(8) << 90
            << std::fixed << std::setprecision(2) << std::setw(10) << (76 + 88 + 90) / 3.0 << std::endl;
    std::cout << "*********************************" << std::endl;

    // 使用原始字符串字面量表示文件路径
    std::ifstream inputFile(R"(example.txt)"); // 打开文件
    if (inputFile.is_open()) {
        // 检查文件是否成功打开
        std::string line;
        while (std::getline(inputFile, line)) {
            // 逐行读取
            std::cout << line << std::endl; // 输出每一行
        }
        inputFile.close(); // 关闭文件
    } else {
        std::cerr << "无法打开文件！" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    std::ofstream outputFile("output.txt"); // 以写入模式打开文件
    //等效于 std::ofstream outputFile("output.txt", std::ios::out);
    if (outputFile.is_open()) {
        outputFile << "Hello, file!" << std::endl;
        outputFile << "This is a new line." << std::endl;
        outputFile.close();
    } else {
        std::cerr << "无法创建文件！" << std::endl;
    }
    // 以二进制模式写入文件
    std::ofstream binaryFile("data.bin", std::ios::binary);
    if (binaryFile.is_open()) {
        int data[] = {97, 2, 3, 4, 5};
        // 使用 reinterpret_cast 将整数数组转换为字符指针
        binaryFile.write(reinterpret_cast<char *>(data), sizeof(data));
        binaryFile.close();
    } else {
        std::cerr << "无法创建二进制文件！" << std::endl;
    }
    std::cout << "*********************************" << std::endl;

    // 创建一个简单的数据库文件
    std::ofstream dbFile("database.txt");
    dbFile << "001 张三 25 北京\n";
    dbFile << "002 李四 30 上海\n";
    dbFile << "003 王五 28 广州\n";
    dbFile.close();
    // 修改李四的年龄为31
    std::fstream file("database.txt", std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "无法打开数据库文件！" << std::endl;
        return 1;
    }
    std::string line2;
    while (std::getline(file, line2)) {
        if (line2.find("002 李四") != std::string::npos) {
            // 找到李四的记录，计算当前位置
            std::streampos pos = file.tellg();
            // 回到行首
            file.seekp(pos - line2.length() - 3);
            // 写入修改后的记录
            file << "002 李四 31 上海\n";
            break;
        }
    }
    file.close();
    // 显示修改后的文件内容
    std::ifstream displayFile("database.txt");
    std::cout << "修改后的数据库内容：" << std::endl;
    while (std::getline(displayFile, line2)) {
        std::cout << line2 << std::endl;
    }
    displayFile.close();
    std::cout << "*********************************" << std::endl;

    // 模拟CSV格式的数据
    std::string csvData = "姓名,年龄,城市\n"
            "张三,25,北京\n"
            "李四,30,上海\n"
            "王五,28,广州\n";
    // 解析CSV数据
    std::vector<Person> people = parseCSV(csvData);
    // 转换为HTML表格
    std::string htmlTable = toHTMLTable(people);
    // 输出结果
    std::cout << "生成的HTML表格：" << std::endl;
    std::cout << htmlTable << std::endl;

    return 0;
}
