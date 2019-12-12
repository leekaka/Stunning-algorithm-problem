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
    

        
    private:
        int Partition(vector<int>&data,int start, int end);
        void Swap(int*a, int*b);

};


#endif



