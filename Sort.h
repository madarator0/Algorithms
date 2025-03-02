#pragma once
#include <vector>
#include "memory_usage.h"

struct SortRes
{
	int SwapCount;
	size_t Memory;
	std::vector<int> ResArr;
};

class Sort
{
public:
	// ���������� ��������� (BubbleSort)
	SortRes BubbleSort(const std::vector<int>& input);

	// ������� ���������� (QuickSort)
	void QuickSort(std::vector<int>& arr, int low, int high, int& swapCount);
	SortRes QuickSort(const std::vector<int>& input);

	// ���������� �������� (MergeSort)
	void MergeSort(std::vector<int>& arr, int left, int right, int& swapCount);
	SortRes MergeSort(const std::vector<int>& input);

	// ������������� ���������� (HeapSort)
	void Heapify(std::vector<int>& arr, int n, int i, int& swapCount);
	void HeapSort(std::vector<int>& arr, int& swapCount);
	SortRes HeapSort(const std::vector<int>& input);

	// ���������� �������� (InsertionSort)
	void InsertionSort(std::vector<int>& arr, int& swapCount);
	SortRes InsertionSort(const std::vector<int>& input);
private:
	void Merge(std::vector<int>& arr, int left, int mid, int right, int& swapCount);
	int Partition(std::vector<int>& arr, int low, int high, int& swapCount);
	void MySwap(int& a, int& b);
};
