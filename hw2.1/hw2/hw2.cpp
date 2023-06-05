#include <iostream>
#include <list>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");

    //1.1
    list <long> l1{};
    for (int i{}; i < 6; i++)
        l1.push_back(i);

    //1.2
    cout << "Первый список: " << endl;
    for (auto l : l1)
        cout << l << " ";

    //1.3
    list<long>::iterator it;
    it = l1.begin();
    int i{};
    while (it != l1.end())
    {
        i++;
        if (i % 2 == 0)
        {
            *it = -(*it);
        }
        it++;
    }

    //1.4   
    it = l1.begin();
    cout << "\nИзмененный первый список: " << endl;
    while (it != l1.end())
    {
        cout << *it << " ";
        ++it;
    }

    //1.5
    list <long> l2{};
    for (int i{ 6 }; i < 10; i++)
        l2.push_back(i);

    //1.6
    int n = 2;
    l1.resize(l1.size() - n);
    it = l1.begin();
    l1.insert(l1.end(), l2.begin(), l2.end());

    //1.7
    cout << "\nПервый список (удалены n = " << n << " элементов, вставлены элементы второго): " << endl;
    for (auto l : l1)
        cout << l << " ";

    cout << "\nВторой список: " << endl;
    for (auto l : l2)
        cout << l << " ";
}


