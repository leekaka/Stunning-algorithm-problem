#include "common.h"


void Sort:: PrintData(vector<int>&data) {
    for (int i=0;i<data.size();i++) {
	    cout<<data[i]<<endl;
    }

}



void Sort::InsertSort(vector<int>&data) {
    for(int i=1;i<data.size();i++) { //未排序的 
	    int tmp = data[i];
	    int j=i;
	    while(j>0 && tmp < data[j-1]) {
	        data[j] = data[j-1];
	        j--;
	    }

	    if(j!=i) {
	        data[j] = tmp;
		}
    }
}

