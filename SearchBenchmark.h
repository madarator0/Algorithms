#pragma once
#include <benchmark/benchmark.h>
#include "Search.h"
#include "Sort.h"
#include <vector>

class SearchBenchmark {
private:
    std::vector<int> numbers; // Поле для хранения чисел
    int target;               // Число, которое ищем

public:
    SearchBenchmark(const std::vector<int>& inputNumbers, int searchTarget); // Конструктор

    void BM_BinarySearch(benchmark::State& state);

    void RegisterBenchmarks();
};
