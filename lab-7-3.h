#ifndef UNTITLED_LAB_7_3_H
#define UNTITLED_LAB_7_3_H

#pragma once
#include <string>
#include <vector>
#include <map>
#include <fstream>

// Оценки
enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

// Студент
struct Student
{
    std::string Name;
    int Year;
    std::map<std::string, Score> RecordBook;
};

// Группы студентов
using Groups = std::map<std::string, std::vector<Student>>;

// Сохранить группы в файл
void saveToFile(const std::string& filename, const Groups& groups) {
    std::ofstream file(filename);

    for (const auto& group : groups) {
        file << "Group: " << group.first << "\n";

        for (const auto& student : group.second) {
            file << "Students: " << student.Name << "|" << student.Year << "\n";

            for (const auto& record : student.RecordBook) {
                file << "Record:  " << record.first << "|" << record.second << "\n";
            }
        }
    }
}

// Загрузить группы из файла
void loadFromFile(const std::string& filename, Groups& outGroups) {
    std::ifstream file(filename);
    outGroups.clear();

    std::string currentGroup;
    Student currentStudent;
    bool inStudent = false;

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        if (line.find("Group: ") == 0) {
            // Сохраняем предыдущего студента при смене группы
            if (inStudent) {
                outGroups[currentGroup].push_back(currentStudent);
                inStudent = false;
            }
            currentGroup = line.substr(7);
        }
        else if (line.find("Students: ") == 0) {
            // Сохраняем предыдущего студента
            if (inStudent) {
                outGroups[currentGroup].push_back(currentStudent);
            }

            std::string data = line.substr(10);
            size_t pos = data.find('|');
            currentStudent.Name = data.substr(0, pos);
            currentStudent.Year = std::stoi(data.substr(pos + 1));
            currentStudent.RecordBook.clear();
            inStudent = true;
        }
        else if (line.find("Record:  ") == 0 && inStudent) {
            std::string data = line.substr(9);
            size_t pos = data.find('|');
            std::string subject = data.substr(0, pos);
            int score = std::stoi(data.substr(pos + 1));
            currentStudent.RecordBook[subject] = static_cast<Score>(score);
        }
    }

    // Сохраняем последнего студента
    if (inStudent) {
        outGroups[currentGroup].push_back(currentStudent);
    }
}
#endif //UNTITLED_LAB_7_3_H
