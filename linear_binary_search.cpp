#include <iostream>
using namespace std;

// Linear Search
int linear_search(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search 
int binary_search(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Print array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Selection Sort
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Original array: ";
    print_array(arr, n);

    int target;
    cout << "Enter target: ";
    cin >> target;
    cout << "\n===== Menu =====\n";
    cout << "1. Linear search\n";
    cout << "2. Binary search\n";
    int option;
    cout << "Enter option: ";
    cin >> option;

    switch (option)
    {
    case 1:
        cout << "Element found at index: " << linear_search(arr, n, target) << endl;
        break;
    case 2:
        selection_sort(arr, n);
        cout << "Sorted array: ";
        print_array(arr, n);
        cout << "Element found at index (in sorted array): " << binary_search(arr, n, target) << endl;
        break;

    default:
        cout << "Invalid option" << endl;
        break;
    }
    delete[] arr;
    return 0;
}
