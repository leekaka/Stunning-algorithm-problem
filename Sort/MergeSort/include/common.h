#ifndef COMMON_H
#define COMMIN_H



#include <iostream>
#include <vector>

using namespace std;


class Sort
{ 
    public: 
    
    void PrintData(vector<int>&data); 
    
    void MergeSort(vector<int>&data) {
	    Msort(data,0,data.size()-1);
    }

    void Msort(vector<int>&data,int lo, int hi) {
	    if(lo >= hi)return;
	    int mid =lo +  (hi-lo)/2;
	    Msort(data,lo,mid);
	    Msort(data,mid+1,hi);
	    merge(data,lo,mid,hi);

    }

    void merge(vector<int>&data,int lo, int mid, int hi) { 
		int i = lo, j=mid+1;
	    for(int k=lo;k<=hi;k++) {
	        help[k] = data[k];
	    }

	    for(int k=lo;k<=hi;k++) {
	        if( i > mid )		        data[k] = help[j++];
	        else if( j > hi)		    data[k] = help[i++];
	        else if(help[i] > help[j])  data[k] = help[j++];
	        else			            data[k] = help[i++];
	    }
    }

    private:
	
	int help[1000]; // 这里其实可以只需要输入的data长度即可

};


#endif



