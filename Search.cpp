#include "Search.h"

SearchRes Search::BinarySearch(const std::vector<int>& arr, int target)
{
    SearchRes result;
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            result.found = true;
            result.Id = mid;  // Используем Id для хранения индекса
            return result;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    result.found = false;
    result.Id = -1;  // Если элемент не найден, устанавливаем Id в -1
    return result;
}
