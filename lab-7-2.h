#ifndef UNTITLED_LAB_7_2_H
#define UNTITLED_LAB_7_2_H

#pragma once
#include <string>
#include <vector>
#include <fstream>

struct Book {
    std::string Author;
    std::string Title;
    int Year;
};

// Сохраняем книги в файл
void saveToFile(const std::string& filename, const std::vector<Book>& data) {
    std::ofstream file(filename);
    for (const auto& book : data) {
        file << book.Author << "|" << book.Title << "|" << book.Year << "\n";
    }
}

// Загружаем книги из файла
void loadFromFile(const std::string& filename, std::vector<Book>& outData) {
    std::ifstream file(filename);
    outData.clear();

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty()) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);

            Book book;
            book.Author = line.substr(0, pos1);
            book.Title = line.substr(pos1 + 1, pos2 - pos1 - 1);
            book.Year = std::stoi(line.substr(pos2 + 1));

            outData.push_back(book);
        }
    }
}
#endif //UNTITLED_LAB_7_2_H
