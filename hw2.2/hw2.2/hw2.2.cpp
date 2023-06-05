#include <iostream>
#include "Employee.h"
#include <list>

using namespace TSA;
int main()
{
    setlocale(LC_ALL, "rus");

    //2.1
    list <TSA::Employee> l1{};
    l1.push_back(Employee("Agata", "Belousova", 19, "agata", "irucm", "cashier"));
    l1.push_back(Employee("Victor", "Ovsyannikov", 26, "victor", "ujvr", "top-manager"));
    l1.push_back(Employee("Alisa", "Pavlova", 22, "alisa", "iuthmc", "manager"));

    //2.2
    cout << "Первый список: " << endl;
    for (auto l : l1)
        cout << l << " " << endl;

    //2.3
    list<Employee>::iterator it;
    it = l1.begin();
    while (it != l1.end())
    {
        *it = Employee((*it).getName(), (*it).getLastName(), (*it).getAge() + 2, (*it).getLogin(), (*it).getPass(), (*it).getJob());
        it++;
    }

    //2.4   
    it = l1.begin();
    cout << "\nИзмененный первый список: " << endl;
    while (it != l1.end())
    {
        cout << *it << endl;
        ++it;
    }

    //2.5
    list <Employee> l2{};
    l2.push_back(Employee("Victoria", "Gracheva", 19, "vika", "rvt", "cashier"));
    l2.push_back(Employee("Fyodor", "Naumov", 26, "fedya", "tytvge", "top-manager"));

    //2.6
    int n = 2;
    l1.resize(l1.size() - n);
    it = l1.begin();
    l1.insert(l1.end(), l2.begin(), l2.end());

    //2.7
    cout << "\nПервый список (удалены n = " << n << " элементов, вставлены элементы второго): " << endl;
    for (auto l : l1)
        cout << l << endl;

    cout << "Второй список: " << endl;
    for (auto l : l2)
        cout << l << endl;
}