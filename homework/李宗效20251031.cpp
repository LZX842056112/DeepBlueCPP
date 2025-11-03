#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <map>

class Student {
public:
    Student() {
    }

    Student(const std::string &name, const int chinese, const int math, const int english) : name(name),
        chinese(chinese), math(math), english(english) {
        avg = (chinese + math + english) / 3.0;
        grade = gradation(avg);
    }

    ~Student() {
    }

    char gradation(const int avg) {
        if (avg >= 90) {
            return 'A';
        } else if (avg >= 80) {
            return 'B';
        } else if (avg >= 70) {
            return 'C';
        } else if (avg >= 60) {
            return 'D';
        } else {
            return 'E';
        }
    }

    std::string name;
    int chinese;
    int math;
    int english;
    char grade;
    double avg;
};

void dataStructure(std::vector<Student> sts, const std::string &fileName, bool flag = false) {
    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        outputFile << "姓名 语文 数学 英语 等级 平均分\n";
        outputFile << "------------------------\n";
        std::for_each(sts.begin(), sts.end(), [&outputFile, flag](const Student &s) {
            outputFile << s.name << "\t" << s.chinese << "\t" << s.math << "\t" << s.english;
            if (flag) {
                outputFile << "\t" << s.grade << "\t" << std::fixed << std::setprecision(2) << s.avg;
            }
            outputFile << "\n";
        });
        outputFile.close();
    } else {
        std::cerr << "无法创建文件！" << std::endl;
    }
}

// 解析CSV格式的字符串
std::vector<Student> parseCSV(const std::string &csvData) {
    std::vector<Student> stu;
    std::istringstream csvFile(csvData);
    std::string line;
    std::getline(csvFile, line);
    std::getline(csvFile, line);
    while (std::getline(csvFile, line)) {
        std::istringstream lineStream(line);
        std::string field;
        std::vector<std::string> fields;
        while (std::getline(lineStream, field, '\t')) {
            fields.push_back(field);
        }
        if (fields.size() >= 4) {
            Student st(fields[0], std::stoi(fields[1]), std::stoi(fields[2]), std::stoi(fields[3]));
            stu.push_back(st);
        }
    }
    return stu;
}

class Subject {
public:
    Subject() {
    }

    Subject(const std::string &name, const int sum, const int max, const int min,
            const double avg) : name(name), sum(sum), max(max), min(min), avg(avg) {
    }

    ~Subject() {
    }

    std::string name;
    int sum;
    int max;
    int min;
    double avg;
};

std::string toHTMLTable(const std::vector<Subject> &subs) {
    std::ostringstream html;
    html << "<table border='1'>\n";
    html << "<tr><th></th><th>max</th><th>min</th><th>avg</th></tr>\n";

    std::for_each(subs.begin(), subs.end(), [&html](const Subject &s) {
        html << "<tr><td>" << s.name
                << "/td><td>" << s.max
                << "</td><td>" << s.min
                << "</td><td>" << s.avg
                << "</td></tr>\n";
    });
    html << "</table>";
    return html.str();
};

int main() {
    try {
        // 构造数据
        Student st1("张三", 90, 95, 60);
        Student st2("李四", 70, 80, 86);
        Student st3("王五", 100, 75, 65);
        Student st4("赵六", 85, 30, 90);
        Student st5("田七", 50, 100, 80);
        std::vector<Student> sts = {st1, st2, st3, st4, st5};
        dataStructure(sts, "student_scores.txt");

        //读取数据
        std::ifstream inputFile("student_scores.txt");
        if (inputFile.is_open()) {
            std::stringstream buffer;
            std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            inputFile.close();
            //解析数据
            std::vector<Student> sts2 = parseCSV(content);
            //写入数据
            dataStructure(sts2, "student_grades.txt", true);

            // 统计数据
            Subject sub_chinese("chinese", 0, 0, 100, 0);
            Subject sub_math("math", 0, 0, 100, 0);
            Subject sub_english("english", 0, 0, 100, 0);
            std::for_each(sts2.begin(), sts2.end(), [&sub_chinese, &sub_math, &sub_english](const Student &s) {
                sub_chinese.sum += s.chinese;
                sub_chinese.max = std::max(sub_chinese.max, s.chinese);
                sub_chinese.min = std::min(sub_chinese.min, s.chinese);
                sub_math.sum += s.math;
                sub_math.max = std::max(sub_math.max, s.math);
                sub_math.min = std::min(sub_math.min, s.math);
                sub_english.sum += s.english;
                sub_english.max = std::max(sub_english.max, s.english);
                sub_english.min = std::min(sub_english.min, s.english);
            });
            std::vector<Subject> subjects = {sub_chinese, sub_math, sub_english};
            std::for_each(subjects.begin(), subjects.end(), [](Subject &s) {
                s.avg = s.sum / 3.0;
            });

            //转换为HTML表格
            std::string htmlTable = toHTMLTable(subjects);
            std::cout << "生成的HTML表格：" << std::endl;
            std::cout << htmlTable << std::endl;

            //按等级分类统计
            std::map<char, std::vector<Student> > m;
            std::for_each(sts2.begin(), sts2.end(), [&m](const Student &s) {
                m[s.grade].push_back(s);
            });
            for (const auto &pair: m) {
                double percentage = (static_cast<double>(pair.second.size()) / sts2.size()) * 100;
                std::cout << pair.first << "等级学生人数: " << pair.second.size() << ", 百分比: " << std::fixed <<
                        std::setprecision(2) << percentage << "%" << std::endl;
            }
        } else {
            std::cerr << "无法打开文件!" << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
