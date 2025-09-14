#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, choice;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "\nChoose sorting method:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        // Bubble Sort
        for (int i = 0; i < n - 1; i++) {
            bool swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
        cout << "\nSorted using Bubble Sort: ";
    } 
    else if (choice == 2) {
        // Selection Sort
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
        cout << "\nSorted using Selection Sort: ";
    } 
    else {
        cout << "\nInvalid choice!";
        return 0;
    }
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
