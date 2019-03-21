#include "common.h"


void Sort:: PrintData(vector<int>&data)
{
    for (int i=0;i<data.size();i++)
    {
	cout<<data[i]<<endl;
    }

}


void Sort::QuickSort(vector<int>&data,int start, int end)
{
    if(start==end)return;
    int index = Partition(data,start,end);
    if(index>start)
	QuickSort(data,start,index-1);
    if(index<end)
	QuickSort(data,index+1,end);
}


int Sort::Partition(vector<int>&data,int start, int end)
{

    int small = start-1;
    for(int i =start;i<end;i++)
    {
	if(data[i]<data[end])
	{
	    small++;
	    if(small!=i)
	    {
		Swap(&data[i],&data[small]);
	    }
	}
    }
    small++;

    Swap(&data[small],&data[end]);

    return small;
}



void Sort::Swap(int *a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
void quickSort(vector<int>&data,int start, int end)
{
    if(start == end)return;

    int index = 

}

*/


