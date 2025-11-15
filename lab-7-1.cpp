#include <iostream>
#include <string>
#include <vector>
#include "lab-7-1.h"

// Функция для красивого вывода вектора
void printWords(const std::vector<std::string>& words, const std::string& title) {
    std::cout << title << ":" << std::endl;
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << "  " << (i + 1) << ". " << words[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    // Пример 2: Список фруктов
    std::cout << "=== List of fruits ===" << std::endl;

    std::vector<std::string> fruits = {"apple", "banana", "orange"};
    std::string filename2 = "fruits.txt";

    std::cout << "Original list of fruits:" << std::endl;
    printWords(fruits, "Fruits");

    // Сохраняем фрукты в файл
    saveToFile(filename2, fruits);
    std::cout << "Fruits are saved to a file: " << filename2 << std::endl << std::endl;

    // Загружаем фрукты из файла
    std::vector<std::string> loadedFruits;
    loadFromFile(filename2, loadedFruits);

    std::cout << "Loaded fruits:" << std::endl;
    printWords(loadedFruits, "Fruits from the file");


    // Проверка, что данные совпадают
    std::cout << std::endl << "Check" << std::endl;
    if (fruits == loadedFruits) {
        std::cout << "The list of fruits matches" << std::endl;
    }

    return 0;
}