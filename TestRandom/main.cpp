#include <iostream>
#include <random>
#include "tester.h"
using namespace  std;

template <class T>
void sort(T* array, int n){
    // implemente aqui
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if(array[j] > array[j+1])
            {
                T temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void generateRandom(double* array, int n){
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(5.0,2.0);
    for (int i = 0; i < n; ++i) {
        array[i] = distribution(generator);
    }
}

int main() {
    double* array = new double[100];
    generateRandom(array, 100);
    sort(array, 100);
    ASSERT(isSorted<double>(array, 100), "The sort is not working");
    return 0;
}
