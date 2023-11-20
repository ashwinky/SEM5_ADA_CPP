#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// Recursive Quick Sort
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Recursive Insertion Sort
void insertionSort(int arr[], int n) {
  if (n <= 1) return;

  insertionSort(arr, n - 1);

  int key = arr[n - 1];
  int j = n - 2;

  while (j >= 0 && arr[j] > key) {
    arr[j + 1] = arr[j];
    j = j - 1;
  }
  arr[j + 1] = key;
}

// Recursive Selection Sort
int minIndex(int arr[], int i, int j) {
  if (i == j) return i;

  int k = minIndex(arr, i + 1, j);

  return (arr[i] < arr[k]) ? i : k;
}

void selectionSort(int arr[], int n, int index = 0) {
  if (index == n) return;

  int k = minIndex(arr, index, n - 1);

  if (k != index) swap(&arr[k], &arr[index]);

  selectionSort(arr, n, index + 1);
}

int main() {
  int sizes[] = {10, 100, 1000, 10000};
  int numSizes = sizeof(sizes) / sizeof(sizes[0]);

  for (int s = 0; s < numSizes; s++) {
    int n = sizes[s];

    int* arr1 = new int[n];
    int* arr2 = new int[n];
    int* arr3 = new int[n];

    // Initialize arrays with same random values
    for (int i = 0; i < n; i++) {
      int x = rand() % n;
      arr1[i] = x;
      arr2[i] = x;
      arr3[i] = x;
    }

    cout << "For n = " << n << ":" << endl;

    auto start = high_resolution_clock::now();
    quickSort(arr1, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "  Time taken by Quick Sort: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    insertionSort(arr2, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "  Time taken by Insertion Sort: " << duration.count() << " ms" << endl;

    start = high_resolution_clock::now();
    selectionSort(arr3, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "  Time taken by Selection Sort: " << duration.count() << " ms" << endl;

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
  }

  return 0;
}
