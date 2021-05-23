#pragma once



namespace itis {


  struct TimSort {

    static const int RUN = 32;
    static void insertionSort(int arr[], int left, int right);
    static void merge(int arr[], int l, int m, int r);
    static void timSort(int arr[], int n);
    static void printArray(int arr[], int n);

  };

}