//
// Created by Hoang Tran on 4/20/2023.
//
#pragma once
#include <iostream>
#include <vector>


//Shell sort implementation using pseudocode from the slide
/**
 * Shell Sort Algorithm:
 * Sorts the given vector in ascending order using Shell sort algorithm.
 *
 * @param arr The vector to be sorted.
 */
void shellSort(std::vector<int>& arr)
{
    int n = arr.size();
    int gap = n / 2; //starting gap equal to half the vector
    //Sort until gap = 0
    while (gap > 0)
    {
        //Insertion sort to sort the two element between the gap
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            // Shift elements in the sub-array until the correct position for the current element is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp; // Insert the current element in its correct position in the sub-vector
        }
        gap = gap / 2; // divide the gap by half for every iteration
    }
}

//Quick sort implementation using pseudocode from the slide

//Helper method to shift smaller and larger element to the left and right of the pivot element
int partition(std::vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int index = (low - 1);
    // Iterate over the sub-array between low and high
    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot, swap it with the element at the current index of the left sub-array
        if (arr[j] <= pivot) {
            index++;
            std::swap(arr[index], arr[j]);
        }
    }
    std::swap(arr[index + 1], arr[high]); // Swap the pivot element with the element at the final index of the left sub-array
    return (index + 1); // Return the index of the pivot element
}

// Function to implement quick sort

/**
 * Function to implement Quick Sort Algorithm:
 * Sorts the given vector in ascending order using Quick sort algorithm.
 *
 * @param arr The vector to be sorted.
 * @param low The lowest index of the vector.
 * @param high The highest index of the vector.
 */

void quickSort(std::vector<int>& arr, int low, int high)
{
    // Check if the input vector has more than one element
    if (low < high) {
        int pivot = partition(arr, low, high); // Partition the vector around a pivot element

        quickSort(arr, low, pivot - 1); // Recursively sort the sub-array to the left of the pivot element
        quickSort(arr, pivot + 1, high); // Recursively sort the sub-array to the right of the pivot element
    }
}
