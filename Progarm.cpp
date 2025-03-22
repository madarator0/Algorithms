#include <benchmark/benchmark.h>
#include "SortBenchmark.h"
#include "SearchBenchmark.h"
#include <vector>
#include <random>
#include <iostream>

int main(int argc, char** argv)
{
    // Размер входных данных
    const int dataSize = 10000;

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 10000); // Числа от 1 до 10000

    // Заполняем вектор случайными числами
    std::vector<int> testData(dataSize);
    for (int& num : testData) {
        num = distrib(gen);
    }

    // Генерируем случайное число для поиска
    int targetValue = distrib(gen);

    // Выводим первые 10 чисел для проверки (можно убрать)
    std::cout << "Sample input data: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << testData[i] << " ";
    }
    std::cout << "\nTarget value: " << targetValue << std::endl;

    // Создаем объект для тестирования сортировки
    SortBenchmark sortBench(testData);

    // Регистрируем бенчмарки для сортировки
    sortBench.RegisterBenchmarkByType(SortBenchmarkType::HeapSort);
    sortBench.RegisterBenchmarkByType(SortBenchmarkType::QuickSort);
    sortBench.RegisterBenchmarkByType(SortBenchmarkType::BubbleSort);
    sortBench.RegisterBenchmarkByType(SortBenchmarkType::InsertionSort);
    sortBench.RegisterBenchmarkByType(SortBenchmarkType::MergeSort);
	sortBench.RegisterBenchmarkByType(SortBenchmarkType::SelectionSort);

    // Запуск бенчмарков
    benchmark::Initialize(&argc, argv);
    benchmark::RunSpecifiedBenchmarks();

    return 0;
}
