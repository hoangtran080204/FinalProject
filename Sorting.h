//
// Created by Hoang Tran on 4/20/2023.
//
#pragma once
#include <iostream>
#include <vector>


//Shell sort implementation using pseudocode from the slide
void shellSort(std::vector<int>& arr)
{
    int n = arr.size();
    int gap = n / 2;

    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
        gap = gap / 2;
    }
}

//Quick sort implementation using pseudocode from the slide
int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int index = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            index++;
            std::swap(arr[index], arr[j]);
        }
    }
    std::swap(arr[index + 1], arr[high]);
    return (index + 1); // low index
}

// Function to implement quick sort
void quickSort(std::vector<int>& arr, int low, int high)
{
    if (low < high) {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
