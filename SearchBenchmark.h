#pragma once
#include <benchmark/benchmark.h>
#include "Search.h"
#include "Sort.h"
#include <vector>

class SearchBenchmark {
private:
    std::vector<int> numbers; // ���� ��� �������� �����
    int target;               // �����, ������� ����

public:
    SearchBenchmark(const std::vector<int>& inputNumbers, int searchTarget); // �����������

    void BM_BinarySearch(benchmark::State& state);

    void RegisterBenchmarks();
};
