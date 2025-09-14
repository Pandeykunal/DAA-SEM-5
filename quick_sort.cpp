#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <utility>
using namespace std;

int partition(vector<int> &arr, int low, int high);
void qs(vector<int> &arr, int low, int high);

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot && j > low) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void qs(vector<int> &arr, int low, int high) {
    if (low >= high) {
        return;
    }
    int pivotIndex = partition(arr, low, high);
    qs(arr, low, pivotIndex - 1);
    qs(arr, pivotIndex + 1, high);
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
        qs(arr, 0, arr.size() - 1);
        clock_t end = clock();
        clock_t time = end - start;
        cout << "Time taken by quick sort: " << time << endl;
    }
    return 0;
}
