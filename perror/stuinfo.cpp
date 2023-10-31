#include <iostream>
#include <string>
#include <map>

struct Student {
    int midTermScore;
    int finalScore;
    
    Student() : midTermScore(0), finalScore(0) {}
    Student(int mid, int final) : midTermScore(mid), finalScore(final) {}
};

int main() {
    int numStudents;
    std::cout << "학생 수를 입력하세요: ";
    std::cin >> numStudents;

    std::map<std::string, Student> students;

    for (int i = 0; i < numStudents; i++) {
        std::string name;
        int midTermScore, finalScore;

        std::cout << "학생 이름: ";
        std::cin >> name;
        std::cout << "중간 점수: ";
        std::cin >> midTermScore;
        std::cout << "기말 점수: ";
        std::cin >> finalScore;

        students[name] = Student(midTermScore, finalScore);
    }

    std::string searchName;
    std::cout << "찾을 학생 이름을 입력하세요: ";
    std::cin >> searchName;

    auto it = students.find(searchName);
    if (it != students.end()) {
        std::cout << "학생 이름: " << it->first << std::endl;
        std::cout << "중간 점수: " << it->second.midTermScore << std::endl;
        std::cout << "기말 점수: " << it->second.finalScore << std::endl;
    } else {
        std::cout << "학생을 찾을 수 없음." << std::endl;
    }

    return 0;
}
