#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void InsertionSort(std::vector<int> &array, const int left, const int right) {
    for (int i = left + 1; i <= right; ++i) {
        const int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void Heapify(std::vector<int> &array, const int n, const int i, const int offset) {
    int largest = i;
    const int left = 2 * i + 1;
    const int right = 2 * i + 2;
    if (left < n && array[offset + left] > array[offset + largest]) {
        largest = left;
    }
    if (right < n && array[offset + right] > array[offset + largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(array[offset + i], array[offset + largest]);
        Heapify(array, n, largest, offset);
    }
}

void HeapSort(std::vector<int> &array, const int left, const int right) {
    const int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; --i) {
        Heapify(array, n, i, left);
    }
    for (int i = n - 1; i > 0; --i) {
        std::swap(array[left], array[left + i]);
        Heapify(array, i, 0, left);
    }
}

int Partition(std::vector<int> &array, const int left, const int right) {
    const int pivot = array[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (array[j] <= pivot) {
            ++i;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[right]);
    return i + 1;
}

void QuickSort(std::vector<int> &array, int left, const int right, const int depth_limit) {
    while (left < right) {
        if (right - left + 1 <= 16) {
            InsertionSort(array, left, right);
            break;
        }
        if (depth_limit == 0) {
            HeapSort(array, left, right);
            break;
        }
        const int pivot = Partition(array, left, right);
        QuickSort(array, left, pivot - 1, depth_limit - 1);
        left = pivot + 1;
    }
}

void IntroSort(std::vector<int> &array, const int left, const int right) {
    const int depth_limit = static_cast<int>(2 * std::log2(right - left + 1));
    QuickSort(array, left, right, depth_limit);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 0;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    IntroSort(array, 0, n - 1);
    for (const int &val: array) {
        std::cout << val << ' ';
    }
    return 0;
}
