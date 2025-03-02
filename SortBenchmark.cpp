#include "SortBenchmark.h"
#include "memory_usage.h"


// Конструктор, принимающий данные
SortBenchmark::SortBenchmark(const std::vector<int>& inputNumbers) : numbers(inputNumbers) {}

// Бенчмарк для пузырьковой сортировки
void SortBenchmark::BM_BubbleSort(benchmark::State& state) {
    Sort sorter;
    SortRes result;
    for (auto _ : state) {
        result = sorter.BubbleSort(numbers);
    }
    state.counters["SwapCount"] = result.SwapCount;
    state.counters["MemoryUsage"] = result.Memory / 1024.0; // В КБ
}

void SortBenchmark::BM_QuickSort(benchmark::State& state) {
    Sort sorter;
    SortRes result;
    for (auto _ : state) {
        result = sorter.QuickSort(numbers);
    }
    state.counters["SwapCount"] = result.SwapCount;
    state.counters["MemoryUsage"] = result.Memory / 1024.0; // В КБ
}

void SortBenchmark::BM_MergeSort(benchmark::State& state) {
    Sort sorter;
    SortRes result;
    for (auto _ : state) {
        result = sorter.MergeSort(numbers);
    }
    state.counters["SwapCount"] = result.SwapCount;
    state.counters["MemoryUsage"] = result.Memory / 1024.0; // В КБ
}

void SortBenchmark::BM_HeapSort(benchmark::State& state) {
    Sort sorter;
    SortRes result;
    for (auto _ : state) {
        result = sorter.HeapSort(numbers);
    }
    state.counters["SwapCount"] = result.SwapCount;
    state.counters["MemoryUsage"] = result.Memory / 1024.0; // В КБ
}

void SortBenchmark::BM_InsertionSort(benchmark::State& state) {
    Sort sorter;
    SortRes result;
    for (auto _ : state) {
        result = sorter.InsertionSort(numbers);
    }
    state.counters["SwapCount"] = result.SwapCount;
    state.counters["MemoryUsage"] = result.Memory / 1024.0; // В КБ
}


// Метод для регистрации всех бенчмарков
void SortBenchmark::RegisterBenchmarkByType(SortBenchmarkType benchmarkType) {
    switch (benchmarkType) {
    case SortBenchmarkType::BubbleSort:
        benchmark::RegisterBenchmark("BubbleSort", [this](benchmark::State& state) { BM_BubbleSort(state); });
        break;
    case SortBenchmarkType::QuickSort:
        benchmark::RegisterBenchmark("QuickSort", [this](benchmark::State& state) { BM_QuickSort(state); });
        break;
    case SortBenchmarkType::MergeSort:
        benchmark::RegisterBenchmark("MergeSort", [this](benchmark::State& state) { BM_MergeSort(state); });
        break;
    case SortBenchmarkType::HeapSort:
        benchmark::RegisterBenchmark("HeapSort", [this](benchmark::State& state) { BM_HeapSort(state); });
        break;
    case SortBenchmarkType::InsertionSort:
        benchmark::RegisterBenchmark("InsertionSort", [this](benchmark::State& state) { BM_InsertionSort(state); });
        break;
    default:
        break;
    }
}