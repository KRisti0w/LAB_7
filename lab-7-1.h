#ifndef UNTITLED_LAB_7_1_H
#define UNTITLED_LAB_7_1_H

#pragma once
#include <string>
#include <vector>
#include <fstream>

// Функция для сохранения слов в файл
void saveToFile(const std::string& filename, const std::vector<std::string>& data) {
    std::ofstream file(filename);  // Открываем файл для записи
    if (file.is_open()) {          // Если файл открылся успешно
        for (const auto& word : data) {  // Перебираем все слова в списке
            file << word << "\n";  // Записываем каждое слово на новой строке
        }
    }
}

// Функция для загрузки слов из файла
void loadFromFile(const std::string& filename, std::vector<std::string>& outData) {
    std::ifstream file(filename);  // Открываем файл для чтения
    outData.clear();               // Очищаем старый список

    if (file.is_open()) {          // Если файл открылся успешно
        std::string line;          // Временная переменная для хранения строки
        while (std::getline(file, line)) {  // Читаем файл построчно
            if (!line.empty()) {   // Если строка не пустая
                outData.push_back(line);  // Добавляем слово в список
            }
        }
    }
}
#endif //UNTITLED_LAB_7_1_H
