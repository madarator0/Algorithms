#pragma once
#include <vector>

struct SearchRes
{
    bool found; 
    int Id;  
};

class Search
{
public:
    SearchRes BinarySearch(const std::vector<int>& arr, int target);  
};


