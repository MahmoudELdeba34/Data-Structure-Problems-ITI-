#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Employee Class
class Employee {
public:
    int emp_id;
    string name;
    int age;
    double salary;

    Employee(int id, string n, int a, double s) : emp_id(id), name(n), age(a), salary(s) {}

    void display() const {
        cout << "ID: " << emp_id << ", Name: " << name << ", Age: " << age << ", Salary: " << salary << endl;
    }
};

// EmployeeManager Class
class EmployeeManager {
private:
    vector<Employee> employees;

public:
    EmployeeManager(vector<Employee> emp) : employees(emp) {}

    // Selection Sort
    void selectionSort() {
        int n = employees.size();
        for (int i = 0; i < n - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < n; ++j) {
                if (employees[j].emp_id < employees[minIndex].emp_id) {
                    minIndex = j;
                }
            }
            swap(employees[i], employees[minIndex]);
        }
    }

    // Bubble Sort
    void bubbleSort() {
        int n = employees.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (employees[j].emp_id > employees[j + 1].emp_id) {
                    swap(employees[j], employees[j + 1]);
                }
            }
        }
    }

    // Insertion Sort
    void insertionSort() {
        int n = employees.size();
        for (int i = 1; i < n; ++i) {
            Employee key = employees[i];
            int j = i - 1;
            while (j >= 0 && employees[j].emp_id > key.emp_id) {
                employees[j + 1] = employees[j];
                --j;
            }
            employees[j + 1] = key;
        }
    }

    // Sequential Search
    void sequentialSearch(int id) const {
        for (const auto& emp : employees) {
            if (emp.emp_id == id) {
                cout << "Employee found:\n";
                emp.display();
                return;
            }
        }
        cout << "Employee not found!\n";
    }

    // Binary Search (Assume sorted by ID)
    void binarySearch(int id) const {
        int left = 0, right = employees.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (employees[mid].emp_id == id) {
                cout << "Employee found:\n";
                employees[mid].display();
                return;
            }
            if (employees[mid].emp_id < id) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << "Employee not found!\n";
    }

    // Display Employees
    void displayEmployees() const {
        for (const auto& emp : employees) {
            emp.display();
        }
    }
};

// Main Function
int main() {
    vector<Employee> employees;
    int num;

    cout << "Enter the number of employees: ";
    cin >> num;

    for (int i = 0; i < num; ++i) {
        int id, age;
        double salary;
        string name;

        cout << "Enter Employee " << i + 1 << " ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Employee " << i + 1 << " Name: ";
        getline(cin, name);
        cout << "Enter Employee " << i + 1 << " Age: ";
        cin >> age;
        cout << "Enter Employee " << i + 1 << " Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, age, salary);
    }

    EmployeeManager manager(employees);

    int choice;
    cout << "\nChoose Operation:\n";
    cout << "1. Sort Employees\n";
    cout << "2. Search Employee\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nChoose Sorting Algorithm:\n";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nSorting using Selection Sort...\n";
                manager.selectionSort();
                break;
            case 2:
                cout << "\nSorting using Bubble Sort...\n";
                manager.bubbleSort();
                break;
            case 3:
                cout << "\nSorting using Insertion Sort...\n";
                manager.insertionSort();
                break;
            default:
                cout << "Invalid choice! Exiting...\n";
                return 0;
        }

        cout << "\nSorted Employees List:\n";
        manager.displayEmployees();
    } else if (choice == 2) {
        int searchChoice, id;
        cout << "\nChoose Search Method:\n";
        cout << "1. Sequential Search\n";
        cout << "2. Binary Search\n";
        cout << "Enter your choice: ";
        cin >> searchChoice;

        cout << "Enter Employee ID to search: ";
        cin >> id;

        if (searchChoice == 1) {
            manager.sequentialSearch(id);
        } else if (searchChoice == 2) {
            manager.binarySearch(id);
        } else {
            cout << "Invalid choice! Exiting...\n";
        }
    } else {
        cout << "Invalid operation! Exiting...\n";
    }

    return 0;
}
