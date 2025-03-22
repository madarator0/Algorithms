#include "Sort.h"

// ����������� ������ swap
void Sort::MySwap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// ���������� ���������
SortRes Sort::BubbleSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // ������� ����� �������� �������
    int n = arr.size();
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// ��������� ����������� ������

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                MySwap(arr[j], arr[j + 1]); // ����� ���������
                swapCount++;  // ����������� ������� �������
            }
        }
    }
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

// ������� ����������
int Sort::Partition(std::vector<int>& arr, int low, int high, int& swapCount)
{
    int pivot = arr[high]; // �������� ������� �������
    int i = (low - 1);
    for (int j = low; j < high; ++j)
    {
        if (arr[j] <= pivot)
        {
            i++;
            MySwap(arr[i], arr[j]);
            swapCount++;  // ����������� ������� �������
        }
    }
    MySwap(arr[i + 1], arr[high]);
    swapCount++;  // ����������� ������� �������
    return (i + 1);
}

SortRes Sort::QuickSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // ������� ����� �������� �������
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// ��������� ����������� ������
    QuickSort(arr, 0, arr.size() - 1, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

void Sort::QuickSort(std::vector<int>& arr, int low, int high, int& swapCount)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high, swapCount); // ��������� �������
        QuickSort(arr, low, pi - 1, swapCount); // ���������� ��������� ����� �����
        QuickSort(arr, pi + 1, high, swapCount); // ���������� ��������� ������ �����
    }
}

// ���������� ��������
void Sort::MergeSort(std::vector<int>& arr, int left, int right, int& swapCount)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, swapCount); // ��������� ����� ��������
        MergeSort(arr, mid + 1, right, swapCount); // ��������� ������ ��������
        Merge(arr, left, mid, right, swapCount); // ������� ��� ��������
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
            swapCount++;  // ����������� ������� ������� ��� �������
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
    std::vector<int> arr = input; // ������� ����� �������� �������
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// ��������� ����������� ������
    MergeSort(arr, 0, arr.size() - 1, swapCount);
    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}

// ������������� ����������
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
        swapCount++;  // ����������� ������� �������
        Heapify(arr, n, largest, swapCount);
    }
}

SortRes Sort::HeapSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // ������� ����� �������� �������
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// ��������� ����������� ������
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
        swapCount++;  // ����������� ������� �������
        Heapify(arr, i, 0, swapCount);
    }
}

// ���������� ��������
SortRes Sort::InsertionSort(const std::vector<int>& input)
{
    std::vector<int> arr = input;
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage();// ��������� ����������� ������
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
            swapCount++;  // ����������� ������� �������
        }
        arr[j + 1] = key;
    }
}

// ���������� �������
SortRes Sort::SelectionSort(const std::vector<int>& input)
{
    std::vector<int> arr = input; // ������� ����� �������� �������
    int swapCount = 0;  // �������������� ������� �������
    size_t memoryBefore = MemoryUsage::GetMemoryUsage(); // ��������� ����������� ������

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
            MySwap(arr[i], arr[minIndex]); // ����� ���������
            swapCount++;  // ����������� ������� �������
        }
    }

    size_t memoryAfter = MemoryUsage::GetMemoryUsage();
    return { swapCount, memoryAfter - memoryBefore, arr };
}
