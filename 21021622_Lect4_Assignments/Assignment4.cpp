#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    string studentClass;
    Student* next;
};

class StudentManager {
private:
    Student* head;
public:
    StudentManager() : head(nullptr) {}

    void insert(int id, const string& name, const string& studentClass) {
        Student* newStudent = new Student{id, name, studentClass, head};
        head = newStudent;
    }

    void deleteStudent(int id) {
        Student *temp = head, *prev = nullptr;
        while (temp != nullptr && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) return;
        if (prev == nullptr)
            head = temp->next;
        else
            prev->next = temp->next;
        delete temp;
    }

    void infor(int id) {
        Student* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << temp->name << "," << temp->studentClass << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "NA,NA" << endl;
    }
};

int main() {
    StudentManager manager;
    string command;
    while (getline(cin, command)) {
        if (command.find("Insert(") == 0) {
            int id;
            string name, studentClass;
            size_t firstComma = command.find(",", 7);
            size_t lastComma = command.rfind(",");
            id = stoi(command.substr(7, firstComma - 7));
            name = command.substr(firstComma + 1, lastComma - firstComma - 1);
            studentClass = command.substr(lastComma + 1, command.length() - lastComma - 2);
            manager.insert(id, name, studentClass);
        } else if (command.find("Delete(") == 0) {
            int id = stoi(command.substr(7, command.length() - 8));
            manager.deleteStudent(id);
        } else if (command.find("Infor(") == 0) {
            int id = stoi(command.substr(6, command.length() - 7));
            manager.infor(id);
        }
    }
    return 0;
}
