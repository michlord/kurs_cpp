#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_
#include <algorithm> //swap
namespace obliczenia{

template <typename T, typename Cmp = std::less_equal<T> >
static int partition(T *tb,int left,int right, Cmp compare = Cmp())
{
	int store=left;
	for(int i=left;i<right;++i)
	{
	    //this moves all elements smaller
	    //than tb[right] to the beggining
	    //of the array
		//if(tb[i]<tb[right])
		if(compare(tb[i],tb[right])==true)
		{
			std::swap(tb[i],tb[store]);
			++store;
		}
	}
	//right is the midpoint
	std::swap(tb[right],tb[store]);
	return store;
}
template <typename T, typename Cmp = std::less_equal<T> >
static void quickSortHelper(T *tb,int left,int right, Cmp compare = Cmp())
{
	if(left<right)
	{
		int pivot=partition(tb,left,right,compare);
		quickSortHelper(tb,left,pivot-1,compare);
		quickSortHelper(tb,pivot+1,right,compare);
	}
}
template <typename T, typename Cmp = std::less_equal<T> >
void quickSort(T *tb,int size, Cmp compare = Cmp()){
    quickSortHelper(tb,0,size-1,compare);
}

}
#endif
