#ifndef RANDOM_SHUFFLE_H_
#define RANDOM_SHUFFLE_H_

#include <algorithm> //swap

#include <cstdlib> //rand

namespace obliczenia{

template <typename T>
void randomShuffle(T arr, int size){

    for(int i=0; i<size; ++i){
        int r = rand() % size;
        std::swap(arr[i],arr[r]);
    }
}

}
#endif
