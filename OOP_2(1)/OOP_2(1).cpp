// OOP_2(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

﻿#include <iostream>
#include <set>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int array[100];
    srand(time(0));

    for (int i = 0; i < 100; i++) {
        array[i] = rand() % 99 + 1;
    }

    cout << "Элементы массива: " << endl;
    for (int i = 0; i < 100; i++) {
        cout << array[i] << endl;
    }

    set<int> BalancedTree;

    for (int i = 0; i < 100; i++) {
        BalancedTree.insert(array[i]);
    }

    cout << "Элементы дерева: ";
    for (auto& element : BalancedTree) {
        cout << element << " ";
    }
    cout << endl;

    int value;
    cout << "Введите значение для поиска: ";
    cin >> value;

    auto it = BalancedTree.find(value);

    if (it != BalancedTree.end()) {
        int index = 0;
        for (auto element : BalancedTree) {
            if (element == value) {
                cout << "Число " << value << " найдено в индексе: " << index << endl;
                break;
            }
            index++;
        }
    }
    else {
        cout << "Число " << value << " не найдено." << endl;
    }

    return 0;
}

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
