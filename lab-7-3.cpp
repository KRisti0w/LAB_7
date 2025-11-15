#include <iostream>
#include <vector>
#include <map>
#include "lab-7-3.h"

int main() {
    // Создаем студентов
    Student student1;
    student1.Name = "Kristina Savenkova";
    student1.Year = 2025;
    student1.RecordBook = {{" Math", Excellent}, {" Physics", Good}};

    Student student2;
    student2.Name = "Vanya Ivanov";
    student2.Year = 2020;
    student2.RecordBook = {{" Math", Good}, {" Physics", Satisfactorily}};

    // Создаем группу
    std::vector<Student> group1;
    group1.push_back(student1);
    group1.push_back(student2);

    Groups university;
    university["IU8-14"] = group1;

    // Сохраняем в файл
    saveToFile("students.txt", university);
    std::cout << "Saved to a file" << std::endl;

    // Загружаем из файла
    Groups loadedUniversity;
    loadFromFile("students.txt", loadedUniversity);
    std::cout << "Saved to a file" << std::endl;

    // Показываем результат
    std::cout << "\nGroups and students:" << std::endl;
    for (const auto& group : loadedUniversity) {
        std::cout << "Group: " << group.first << std::endl;

        for (const auto& student : group.second) {
            std::cout << "  Student: " << student.Name << " (" << student.Year << ")" << std::endl;
            std::cout << "  Score: ";

            for (const auto& record : student.RecordBook) {
                std::cout << record.first << "=" << record.second << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}