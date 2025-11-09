#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

int main() {
    fs::path p = "my_directory";
    fs::create_directory(p); // 创建目录
    fs::path file = p / "my_file.txt"; // 路径拼接
    // 写入文件
    // ...
    if (fs::exists(file)) {
        std::cout << "File size: " << fs::file_size(file) << std::endl;
        fs::remove(file); // 删除文件
    }
    fs::remove(p);

    std::filesystem::path p1 = "my_directory";
    std::filesystem::create_directory(p1); // 创建目录
    std::filesystem::path file1 = p1 / "my_file.txt"; // 路径拼接
    // 写入文件
    // ...
    if (std::filesystem::exists(file1)) {
        std::cout << "File size: " << std::filesystem::file_size(file1) << std::endl;
        std::filesystem::remove(file1); // 删除文件
    }
    std::filesystem::remove(p1);
    std::cout << "*********************************" << std::endl;


    fs::path currentDir = fs::current_path();
    std::cout << "Current directory: " << currentDir << std::endl;
    fs::path newDir = currentDir / "my_directory";
    fs::create_directory(newDir); // 创建子目录
    std::cout << "Created directory: " << newDir << std::endl;
    fs::path filePath = newDir / "my_file.txt";
    std::ofstream outFile(filePath); // 创建并写入文件
    outFile << "Hello, file system!" << std::endl;
    outFile.close();
    std::cout << "File created: " << filePath << std::endl;
    std::cout << "File size: " << fs::file_size(filePath) << " bytes" << std::endl;
    // 遍历目录
    std::cout << "Files in " << newDir << ":" << std::endl;
    for (const auto& entry : fs::directory_iterator(newDir)) {
        std::cout << entry.path() << std::endl;
    }
    // 删除文件和目录
    fs::remove(filePath);
    fs::remove(newDir);
    std::cout << "File and directory removed." << std::endl;
    std::cout << "*********************************" << std::endl;


    return 0;
}
