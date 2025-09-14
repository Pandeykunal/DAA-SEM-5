#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib> 
using namespace std;

void mS(vector<int> &arr, int left, int right);
void mergeArrays(vector<int> &arr, int low, int mid, int high);
void mergeSort(vector<int> &arr, int size);

void mS(vector<int> &arr, int left, int right) {
    if (left == right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mS(arr, left, mid);
    mS(arr, mid + 1, right);
    mergeArrays(arr, left, mid, right);
}

void mergeArrays(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] < arr[right]) {
            temp.push_back(arr[left++]);
        } else {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left++]);
    }
    while (right <= high) {
        temp.push_back(arr[right++]);
    }
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }}

void mergeSort(vector<int> &arr, int size) {
    mS(arr, 0, size - 1);
}

int main() {
    vector<int> sizes = {1000, 10000, 20000, 30000, 40000, 50000, 100000};
    srand(time(0));

    for (auto n : sizes) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand();
        }

        clock_t start = clock();
        mergeSort(arr, arr.size());
        clock_t end = clock();
        clock_t time = end - start;
        cout << "Time taken by merge sort for size " << n << ": " << time << endl;
    }
    return 0;
}

