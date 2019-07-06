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
    

    void MergeSort(vector<int>&data)
    {
	Msort(data,0,data.size()-1);
    }

    void Msort(vector<int>&data,int lo, int hi)
    {
	if(lo >= hi)return;
	int mid =lo +  (hi-lo)/2;
	Msort(data,lo,mid);
	Msort(data,mid+1,hi);
	merge(data,lo,mid,hi);

    }

    void merge(vector<int>&data,int lo, int mid, int hi) // 类里的静态函数有意义的
    {
	int i = lo, j=mid+1;
	for(int k=lo;k<=hi;k++)
	{
	    aux.push_back(data[k]);
	}

	for(int k=lo;k<=hi;k++)
	{
	    if( i > mid )		    data[k] = aux[j++];
	    else if( j > hi)		    data[k] = aux[i++];
	    else if(aux[i] > aux[j])	    data[k] = aux[j++];
	    else			    data[k] = aux[i++];
	}
    }

    
    private:
    int Partition(vector<int>&data,int start, int end);
    void Swap(int*a, int*b);
    vector<int>aux;

};


#endif



