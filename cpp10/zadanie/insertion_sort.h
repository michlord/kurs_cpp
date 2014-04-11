#ifndef INSERTION_SORT_H_
#define INSERTION_SORT_H_
#include <algorithm> //swap
namespace obliczenia{
template <typename T, typename Cmp = std::less_equal<T> >
void insertSort(T *arr, int size, Cmp compare = Cmp()){
    for(int i=1; i<size; ++i){
        int t=i;
        while(t>0){
            //if(arr[t] < arr[t-1]){
            if(compare(arr[t],arr[t-1])==true){
                std::swap(arr[t],arr[t-1]);
                --t;
            }else{
                break;
            }
        }
    }
}
}
#endif
