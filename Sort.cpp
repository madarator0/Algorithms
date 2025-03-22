#include "Sort.h"

// Собственная версия swap
void Sort::MySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Сортировка пузырьком
SortRes Sort::BubbleSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // Создаем копию входного вектора
    int n = arr.size();
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// Начальное потребление памяти

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                MySwap(arr[j], arr[j + 1]); // Обмен элементов
                swapCount++;  // Увеличиваем счетчик обменов
            }
        }
    }
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

// Быстрая сортировка
int Sort::Partition(std::vector<int>& arr, int low, int high, int& swapCount)
{
    int pivot = arr[high]; // Выбираем опорный элемент
    int i = (low - 1);
    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            MySwap(arr[i], arr[j]);
            swapCount++;  // Увеличиваем счетчик обменов
        }
    }
    MySwap(arr[i + 1], arr[high]);
    swapCount++;  // Увеличиваем счетчик обменов
    return (i + 1);
}

SortRes Sort::QuickSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // Создаем копию входного вектора
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// Начальное потребление памяти
    QuickSort(arr, 0, arr.size() - 1, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

void Sort::QuickSort(std::vector<int>& arr, int low, int high, int& swapCount)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, swapCount); // Разбиение массива
        QuickSort(arr, low, pi - 1, swapCount); // Рекурсивно сортируем левую часть
        QuickSort(arr, pi + 1, high, swapCount); // Рекурсивно сортируем правую часть
    }
}

// Сортировка слиянием
void Sort::MergeSort(std::vector<int>& arr, int left, int right, int& swapCount)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, swapCount); // Сортируем левую половину
        MergeSort(arr, mid + 1, right, swapCount); // Сортируем правую половину
        Merge(arr, left, mid, right, swapCount); // Сливаем две половины
    }
}

void Sort::Merge(std::vector<int>& arr, int left, int mid, int right, int& swapCount)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
            swapCount++;  // Увеличиваем счетчик обменов при слиянии
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

SortRes Sort::MergeSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // Создаем копию входного вектора
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// Начальное потребление памяти
    MergeSort(arr, 0, arr.size() - 1, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

// Пирамидальная сортировка
void Sort::Heapify(std::vector<int>& arr, int n, int i, int& swapCount)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        MySwap(arr[i], arr[largest]);
        swapCount++;  // Увеличиваем счетчик обменов
        Heapify(arr, n, largest, swapCount);
    }
}

SortRes Sort::HeapSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // Создаем копию входного вектора
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// Начальное потребление памяти
    HeapSort(arr, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

void Sort::HeapSort(std::vector<int>& arr, int& swapCount)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        Heapify(arr, n, i, swapCount);

    for (int i = n - 1; i >= 0; --i)
    {
        MySwap(arr[0], arr[i]);
        swapCount++;  // Увеличиваем счетчик обменов
        Heapify(arr, i, 0, swapCount);
    }
}

// Сортировка вставкой
SortRes Sort::InsertionSort(const std::vector<int>& input)
{
    std::vector<int> arr = input;
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// Начальное потребление памяти
    InsertionSort(arr, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

void Sort::InsertionSort(std::vector<int>& arr, int& swapCount)
{
    int n = arr.size();
    for (int i = 1; i < n; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
            swapCount++;  // Увеличиваем счетчик обменов
        }
        arr[j + 1] = key;
    }
}

// Сортировка выбором
SortRes Sort::SelectionSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // Создаем копию входного вектора
    int swapCount = 0;  // Инициализируем счетчик обменов
    size_t memoryBefore = MemoryUsage::GetMemoryUsage(); // Начальное потребление памяти

    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            MySwap(arr[i], arr[minIndex]); // Обмен элементов
            swapCount++;  // Увеличиваем счетчик обменов
        }
    }

    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}
