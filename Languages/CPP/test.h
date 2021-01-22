#ifndef test_H
#define test_H

#include <iostream>
using namespace std;
template <class T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
              swap(a[j], a[j - 1]);
}
template <class X>
void reverse(X a[], int n) {
    for (int i = n; i > 0; i--)
        for (int j = 0; i > j; j++)
            if (a[j] < a[j + 1])
              swap(a[j], a[j + 1]);
}

#endif
