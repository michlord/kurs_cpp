#include <iostream>

#include "random_shuffle.h"
#include "insertion_sort.h"
#include "quick_sort.h"

#include <algorithm>
#include <typeinfo>
#include <ctime> //srand(time)
#include <string>
using namespace obliczenia;


template <typename T>
void printArray(T arr, int size){
    for(int i=0; i<size;++i){
        std::cout << arr[i] << " ";
    }
}

template <>
void printArray<const double **>(const double * *arr,int size){
    for(int i=0; i<size;++i){
        std::cout << *arr[i] << " ";
    }
}

template <typename Iterator,typename Cmp>
bool isSorted(Iterator first, Iterator last,Cmp compare){
    if(first == last)
        return true;
    for(Iterator i=first;i!=(last-1);++i){
        if(compare(*i,*(i+1))==false && compare(*(i+1),*i)==true) // < and ==
            return false;
    }
    return true;
}
template<typename T, typename Cmp = std::less_equal<T> >
void test(T *a,const int SIZE,Cmp compare = Cmp()){
    randomShuffle(a,SIZE);
    std::cout << "in:\n";
    printArray(a,SIZE);
    std::cout << "\nout (insert sort):\n";
    insertSort(a,SIZE,compare);
    if(isSorted(a,a+SIZE,compare)){
        std::cout << "SORTED OK\n";
    }else{
        std::cout << "NOT SORTED!\n";
    }
    printArray(a,SIZE);
    randomShuffle(a,SIZE);
    std::cout << "\nin:\n";
    printArray(a,SIZE);
    std::cout << "\nout (quick sort):\n";
    quickSort(a,SIZE,compare);
    if(isSorted(a,a+SIZE,compare)){
        std::cout << "SORTED OK\n";
    }else{
        std::cout << "NOT SORTED!\n";
    }
    printArray(a,SIZE);
    std::cout << "\n";
}

bool cmpb(const double * &a, const double * &b){
    return *a < *b;
}
bool cmpc(const char * &a, const char * &b){
    return std::string(a) < std::string(b);
}


int main()
{
    srand(time(nullptr));
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    test(a,15);

    const double *b[15];
    for(int i=0;i<15;++i)
        b[i] = new double (i+i/3.0);
    test(b,15);

    const char *c[15];
    for(int i=0;i<15;++i){
        char * str = new char [5];
        str[0] = 'a'; str[1] = 'b'; str[2] = 'c'; str[3] = 'd'; str[4] = '\0';
        randomShuffle(str,4);
        c[i] = str;
    }
    test(c,15,cmpc);

    std::string s[15];
    for(int i=0;i<15;++i){
        char * str = new char [5];
        str[0] = 'a'; str[1] = 'b'; str[2] = 'c'; str[3] = 'd'; str[4] = '\0';
        randomShuffle(str,4);
        s[i] = str;
    }
    test(s,15);
    return 0;
}
