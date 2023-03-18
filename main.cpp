// Использован упрощенный вариант пузырьковой сортировки
// Использован Enum и инициализация указателя на массив посредством new double[n]
#include <iostream>

using std::cout;
using std::endl;

enum SortOrder { ASC, DESC, };

bool isDirection(double current, double next, SortOrder order) {
    return (order == ASC) ? current > next : current < next;
}

// Bubble sorting O(n^2)
void arrSort(double* arr, int size, SortOrder order) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < (size - (i + 1)); ++j) {
            if (isDirection(arr[j], arr[j + 1], order)) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    double* arr = nullptr;
    int arr1Size = 0;

    cout << "Enter the number of array elements:";
    std::cin >> arr1Size;
    arr = new double[arr1Size];

    cout << "Sequentially enter values:" << endl;
    for (int i = 0; i < arr1Size; ++i) {
        cout << "Enter " << (i + 1) << " item:";
        std::cin >> arr[i];
    }

    arrSort(arr, arr1Size, DESC);

    for (int i = 0; i < arr1Size; ++i) cout << arr[i] << endl;
}