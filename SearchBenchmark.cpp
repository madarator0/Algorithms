#include "SearchBenchmark.h"

// Конструктор, принимающий данные
SearchBenchmark::SearchBenchmark(const std::vector<int>& inputNumbers, int searchTarget)
    : numbers(inputNumbers), target(searchTarget) {}

// Метод для регистрации всех бенчмарков
void SearchBenchmark::RegisterBenchmarks() {
    benchmark::RegisterBenchmark("BinarySearch", [this](benchmark::State& state) { BM_BinarySearch(state); });
}

// Бенчмарк для бинарного поиска
void SearchBenchmark::BM_BinarySearch(benchmark::State& state) {
    Search search;
    Sort sorter;
    std::vector<int> sortedNumbers = sorter.BubbleSort(numbers).ResArr; // Обязательно сортируем перед бинарным поиском

    for (auto _ : state) {
        search.BinarySearch(sortedNumbers, target);
    }
}


