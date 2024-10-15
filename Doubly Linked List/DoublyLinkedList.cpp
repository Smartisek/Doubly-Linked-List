// DoublyLinkedList.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "DList.h"
using namespace std;


template <class T>
void display(DList<T>& nums, string msg = "") {
    DListIterator<T> it = nums.getIterator();
    cout << msg << ": ";
    while (it.isValid()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

template<class T>
void displayReversed(DList<T>& nums, string msg = "") {
    DListIterator<T> it = nums.getIterator();
    it.end();
    cout << msg << ": ";
    while (it.isValid()) {
        cout << *it << " ";
        it--;
    }
    cout << endl;
}

int main()
{
    DList<int> nums;
    for (int i = 1; i <= 10; i++) {
        nums.append(i);
    }
    display(nums, "original list");
    displayReversed(nums, "reversed list");
}

