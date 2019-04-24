#ifndef COMMON_H
#define COMMIN_H



#include <iostream>
#include <vector>

using namespace std;


class Sort
{

    public:
    void PrintData(vector<int>&data);
    void QuickSort(vector<int>&data,int start, int end);
    
    //void MergeSort(vector<int>&data);

    void merge(vector<int>&data,int lo, int mid, int hi) // 类里的静态函数是啥意思来着
    {
	int i = lo,j=mid+1;
	for(int k=lo;k<hi;k++)
	{
	    aux[k] = data[k];
	}

	for(int k=lo;k<hi;k++)
	if( i>mid)		data[k] = aux[j++];
	else if(j>hi)		data[k] = aux[i++];
	else if(data[i] > data[j])    data[k] = aux[j++];
	else			data[k] = aux[i++];
    }

    
    private:
    int Partition(vector<int>&data,int start, int end);
    void Swap(int*a, int*b);
    vector<int>aux;



};


#endif



