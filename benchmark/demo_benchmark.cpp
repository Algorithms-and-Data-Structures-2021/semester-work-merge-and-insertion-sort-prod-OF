#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream
#include "merge_sort.hpp"
#include "timsort.hpp"
#include <vector>
#include <ctime>

using namespace std;
using namespace itis;


const string absolutePathToInputFile = "C:/Users/PC/CLionProjects/semester-work-merge-and-insertion-sort-prod-OF/dataset/data";
const string Algs[] = {"timsort", "merge"};
const string Amount[] = {"500", "1000",  "10000",  "100000", "500000"};



int main() {
  for (int i = 0;i < 10; i++ ) {
    ofstream result(absolutePathToInputFile + "/result(" + to_string(i+1) + ").txt");
    bool flag = true;
    for (const string& alg : Algs) {
      result << "\t" << alg << endl;
      flag = !(flag);
      for (const auto& amount : Amount) {

        auto path = (absolutePathToInputFile + "/data(" + amount + ").txt");

        result << amount << "\t";
        ifstream file(path);
        string s;
        int intValues[stoi(amount)];
        int counter = 0;
        for (file >> s; !file.eof(); file >> s) {
          intValues[counter] = stoi(s);
        }
        int n = sizeof(intValues) / sizeof(intValues);
        const auto time_point_before = chrono::steady_clock::now();
        if (!(flag)) {
          TimSort::timSort(intValues, n);
        } else {
          MergeSort::mergeSort(intValues, 0, n - 1);
        }
        const auto time_point_after = chrono::steady_clock::now();
        const auto time_diff = time_point_after - time_point_before;
        const long long time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();

        result << "Time elapsed (ns): " << time_elapsed_ns << endl;
      }
    }
  }
  return 0;
}