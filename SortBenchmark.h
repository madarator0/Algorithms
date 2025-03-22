#pragma once
#include <benchmark/benchmark.h>
#include "Sort.h"
#include <vector>

enum class SortBenchmarkType {
    BubbleSort,
    QuickSort,
    MergeSort,
    HeapSort,
    InsertionSort,
    SelectionSort
};


class SortBenchmark {
private:
    std::vector<int> numbers; // Поле для хранения чисел

public:
    SortBenchmark(const std::vector<int>& inputNumbers); // Конструктор

    void BM_BubbleSort(benchmark::State& state);
    void BM_QuickSort(benchmark::State& state);
    void BM_MergeSort(benchmark::State& state);
    void BM_HeapSort(benchmark::State& state);
    void BM_InsertionSort(benchmark::State& state);
	void BM_SelectionSort(benchmark::State& state);

    void RegisterBenchmarkByType(SortBenchmarkType benchmarkType);
};
