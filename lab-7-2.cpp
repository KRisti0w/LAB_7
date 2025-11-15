#include <iostream>
#include <vector>
#include "lab-7-2.h"

int main() {
    // Создаем несколько книг
    std::vector<Book> myBooks = {
            {"Lev Tolstoy", "War and Peace", 1869},
            {"Fyodor Dostoevsky", "Crime and punishment", 1866}
    };

    // Сохраняем в файл
    saveToFile("books.txt", myBooks);
    std::cout << "Books are saved to a file" << std::endl;

    // Загружаем из файла
    std::vector<Book> loadedBooks;
    loadFromFile("books.txt", loadedBooks);
    std::cout << "Books are saved to a file" << std::endl;

    // Показываем что получилось
    std::cout << "\nDownloaded books:" << std::endl;
    for (const auto& book : loadedBooks) {
        std::cout << "Author: " << book.Author << std::endl;
        std::cout << "Title: " << book.Title << std::endl;
        std::cout << "Year: " << book.Year << std::endl;
        std::cout << "---" << std::endl;
    }

    return 0;
}