/*
1.2-Check Permutation : Given two strings,write a method to decide 
if one is a permutation of the other
*/
// Quicksort (sort() in std maybe got O(n^2) in worst case)
// Merge sort is more efficient and works faster than quick sort in
// case of larger array size or datasets
// Quick sort is more efficient and works faster than merge sort in
// case of smaller array size or datasets.

#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int const left, int const right, int const mid)
{
    auto const idxLeftConst = mid - left + 1;
    auto const idxRightConst = right - mid;

    auto *leftArr = new int[idxLeftConst];
    auto *rightArr = new int[idxRightConst];

    for (auto i = 0; i < idxLeftConst; i++)
        leftArr[i] = arr[left + i];
    for (auto i =0;i < idxRightConst;i++)
        rightArr[i] = arr[mid + 1 +i];
    auto idxLeft = 0,idxRight = 0;

    int idxMerged = left;

    while(idxLeft <  idxLeftConst && idxRight < idxRightConst) {
        if(leftArr[idxLeft] <= rightArr[idxRight]){
            arr[idxMerged] = leftArr[idxLeft];
            idxLeft++;
        } else {
            arr[idxMerged] = rightArr[idxRight];
            idxRight++;
        }
        idxMerged++;
    }

    while (idxLeft < idxLeftConst){
        arr[idxMerged] = leftArr[idxLeft];
        idxLeft++;
        idxMerged++;
    }

    while (idxRight < idxRightConst) {
        arr[idxMerged] = rightArr[idxRight];
        idxRight++;
        idxMerged++;
    }
}


void MergeSort(int arr[],int const left,int const right){
    if(left >= right) return ;
    auto mid = (right - left) /2 + left;
    MergeSort(arr,left,mid);
    MergeSort(arr,mid + 1, right);
    Merge(arr,left,right,mid);    
}

void printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);
 
    cout << "Given array is \n";
    printArray(arr, arr_size);
 
    MergeSort(arr, 0, arr_size - 1);
 
    cout << "\nSorted array is \n";
    printArray(arr, arr_size);
    return 0;
}