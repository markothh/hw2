#include <iostream>
#include "Employee.h"
#include <list>
#include <deque>
#include <algorithm>

using namespace TSA;
int main()
{
    setlocale(LC_ALL, "rus");

    //3.1
    list<Employee> listContainer{};
    listContainer.push_back(Employee("Agata", "Belousova", 19, "agata", "irucm", "cashier"));
    listContainer.push_back(Employee("Victor", "Ovsyannikov", 26, "victor", "ujvr", "top-manager"));
    listContainer.push_back(Employee("Alisa", "Pavlova", 22, "alisa", "iuthmc", "manager"));

    //3.2
    listContainer.sort([](Employee a, Employee b) {return a > b; });

    //3.3
    cout << "Первый список, отсортированный по убыванию: " << endl;
    for (Employee employee : listContainer)
        cout << employee << " " << endl;

    cout << "Данные сотрудника, которому меньше 20 лет: " << endl;
    //3.4
    list<Employee>::iterator it = find_if(listContainer.begin(), listContainer.end(), [](Employee a) {return a.getAge() < 20; });
    cout << *it << endl;

    //3.5
    deque<Employee> dequeContainer{};
    for (Employee employee : listContainer)
    {
        if (employee.getAge() < 25)
            dequeContainer.push_back(employee);
    }

    //3.6
    cout << "Двусторонняя очередь с данными сотрудников, которым меньше 20 лет: " << endl;
    for (Employee employee : dequeContainer)
        cout << employee << " " << endl;

    //3.7
    listContainer.sort([](Employee a, Employee b) {return a < b; });
    sort(dequeContainer.begin(), dequeContainer.end(), [](Employee a, Employee b) { return a < b; });

    //3.8
    cout << "Сортировка обоих контейнеров по возрастанию" << endl;
    cout << "Первый контейнер: " << endl;
    for (Employee employee : listContainer)
        cout << employee << " " << endl;
    cout << "\nВторой контейнер: " << endl;
    for (Employee employee : dequeContainer)
        cout << employee << " " << endl;

    //3.9
    deque<Employee> mergedContainer(dequeContainer.size() + listContainer.size());
    merge(dequeContainer.begin(), dequeContainer.end(), listContainer.begin(), listContainer.end(), mergedContainer.begin());

    //3.10
    cout << "Третий контейнер, полученный слиянием первых двух: ";
    for (Employee employee : mergedContainer)
        cout << employee << " " << endl;

    //3.11
    cout << "Количество сотрудников младше 25 лет в третьем контейнере: " << count_if(mergedContainer.begin(), mergedContainer.end(), [](Employee a) {return a.getAge() < 25; }) << endl;

    //3.12
    cout << "Есть ли в третьем контейнере сотрудник старше 30: ";
    cout << (count_if(mergedContainer.begin(), mergedContainer.end(), [](Employee a) {return a.getAge() > 30; }) ? "да" : "нет") << endl;
}