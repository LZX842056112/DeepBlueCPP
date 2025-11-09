#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <filesystem>
#include <fstream>
#include <cctype>
#include <map>

int main() {
    std::filesystem::path file_path = "input.txt";
    if (!std::filesystem::exists(file_path)) {
        std::cerr << "文件不存在: " << file_path << std::endl;
        return 1;
    }
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "无法打开文件: " << file_path << std::endl;
        return 1;
    }
    std::string line;
    std::map<std::string, int> m;

    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        std::string field;
        while (std::getline(lineStream, field, ' ')) {
            std::string word;
            for (char c: field) {
                if (std::isalpha(c)) {
                    word += std::tolower(c);
                }
            }
            auto it = m.find(word);
            if (it != m.end()) {
                m[word]++;
            } else {
                m[word] = 1;
            }
        }
    }
    std::vector<std::pair<std::string, int> > vec(m.begin(), m.end());
    std::sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    for (const auto &[word, count]: vec) {
        if (!word.empty()) {
            std::cout << word << ": " << count << std::endl;
        }
    }
    file.close();

    return 0;
}
