#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <fstream>

#include "athlete.h"
#include "sorting_algs.h"
#include "utils.h"

/**
 * @mainpage
 * 
 * Link to repository: https://github.com/mrzrow/pm-labs
 * 
 * Results
 * @image latex graph.png
 */

int main() {

    generateAthletesCSV("athletes.csv", 101000);
    std::cout << "File generated\n";
    
    std::vector<int> sizes = {100, 300, 800, 2000, 4000, 7000, 12000,
                              20000, 35000, 55000, 80000, 101000};
    
    using SortFunc = void(*)(Athlete*, long);

    SortFunc sortFunc[] = {
        insertSort<Athlete>,
        heapSort<Athlete>,
        quickSortR<Athlete>,
        standartSort<Athlete>
    };
    const int numSortFunc = 4;

    std::ofstream output("times.csv");
    output << "Size,InsertSort,HeapSort,QuickSort,StandartSort\n";

    for (int size: sizes) {
        std::cout << "Process size = " << size << "...\n";

        Athlete* original = new Athlete[size];
        fillAthleteArray(original, size);
        
        long durations[numSortFunc];
        for (int i = 0; i < numSortFunc; ++i) {
            Athlete* copy = new Athlete[size];
            std::copy(original, original + size, copy);

            auto start = std::chrono::steady_clock::now();
            sortFunc[i](copy, size);
            auto end = std::chrono::steady_clock::now();

            durations[i] = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
            delete[] copy;
        }

        output << size;
        for (int i = 0; i < numSortFunc; ++i) output << "," << durations[i];
        output << "\n";

        delete[] original;
    }

    output.close();
    
    return 0;
}