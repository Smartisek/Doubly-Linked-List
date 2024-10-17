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

template<class T>
void removeDuplicates(DList<T>& nums) {
	DListIterator<T> outer = nums.getIterator();
    while (outer.isValid()) {
        DListIterator<T> inner = outer;
        inner++;
        while (inner.isValid()) {
            if (*inner == *outer) {
                inner = nums.remove(inner);
            }
            else {
                inner++;
            }
        }
        outer++;
    }

}

template<class T>
void mergeTwoLists(DList<T>& list1, DList<T>& list2, DList<T>& merged) {
    DListIterator<T> it1 = list1.getIterator(); //get iterator for list1
    DListIterator<T> it2 = list2.getIterator(); //get iterator for list2
    while (it1.isValid() || it2.isValid()) { //while they are both valid do below
        if (!it1.isValid()) { 
			merged.append(*it2++);
        }
        else if (!it2.isValid()) {
			merged.append(*it1++);
       } 
        else if (*it1 < *it2) {
			merged.append(*it1++);
        }
        else {
			merged.append(*it2++);
        }
    }
}

template<class T>
bool isPalindrome(DList<T>& list) {
    DListIterator<T> forward = list.getIterator();
	DListIterator<T> backward = list.getIterator();
    backward.end();
    while (forward.isValid() && backward.isValid()) {
        if (*forward != *backward) {
            return false;
        }
        else {
            forward++;
            backward--;
        }
        return true;
    }
}

//template<class T> 
//void arrayToListReversed(T& arr, int size,DList<T>& list) {
//    for (int i = size - 1; i >= 0; i--) {
//        list.append(i);
//    }
//
//}

int main()
{
    DList<int> nums;
    for (int i = 1; i <= 10; i++) {
        nums.append(i);
    }
    display(nums, "original list");
    displayReversed(nums, "reversed list");

    DList<int> nums2;
    for (int i = 1; i < 5; i++) {
        for (int c = 1; c < i; c++) {
			nums2.append(i);
        }
    }

	display(nums2, "list with duplicate");
	removeDuplicates(nums2);
	display(nums2, "list with duplicates removed");

    DList<int> merged;
	mergeTwoLists(nums, nums2, merged);
	display(merged, "merged list"); 

    DList<int> palindrome;
    for (int i = 1; i < 5; i++) {
        palindrome.append(i);
    }
	for (int i = 3; i > 0; i--) {
		palindrome.append(i);
	}
    display(palindrome, "palindrome");
    cout << isPalindrome(palindrome) << endl;
	display(nums, "not palindrome");
	cout << isPalindrome(nums) << endl;
    
    /*int storage[10];
    for (int i = 1; i < 10; i++) {
		storage[i] = i;
    }
    DList<int> listFromArray;
    arrayToListReversed(storage,10 ,listFromArray);*/

	return 0;
}

