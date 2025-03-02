#include "SearchBenchmark.h"

// �����������, ����������� ������
SearchBenchmark::SearchBenchmark(const std::vector<int>& inputNumbers, int searchTarget)
    : numbers(inputNumbers), target(searchTarget) {}

// ����� ��� ����������� ���� ����������
void SearchBenchmark::RegisterBenchmarks() {
    benchmark::RegisterBenchmark("BinarySearch", [this](benchmark::State& state) { BM_BinarySearch(state); });
}

// �������� ��� ��������� ������
void SearchBenchmark::BM_BinarySearch(benchmark::State& state) {
    Search search;
    Sort sorter;
    std::vector<int> sortedNumbers = sorter.BubbleSort(numbers).ResArr; // ����������� ��������� ����� �������� �������

    for (auto _ : state) {
        search.BinarySearch(sortedNumbers, target);
    }
}


