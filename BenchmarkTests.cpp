#include "BenchmarkTests.h"

// Бенчмарк для сортировки
void BenchmarkTests::BM_BubbleSort(benchmark::State& state) {
    Sort sorter;
    std::vector<int> numbers = { 5, 3, 8, 4, 2 };

    for (auto _ : state) {
        sorter.BubbleSort(numbers);
    }
}

// Бенчмарк для бинарного поиска
void BenchmarkTests::BM_BinarySearch(benchmark::State& state) {
    Search search;
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int target = 4;
    SearchRes result;

    for (auto _ : state) {
        result = search.BinarySearch(numbers, target);
    }
}

// Метод для регистрации всех бенчмарков
void BenchmarkTests::RegisterBenchmarks() {
    benchmark::RegisterBenchmark("BubbleSort", BM_BubbleSort);
    benchmark::RegisterBenchmark("BinarySearch", BM_BinarySearch);
}
