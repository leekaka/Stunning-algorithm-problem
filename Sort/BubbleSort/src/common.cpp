#include "common.h"


void Sort:: PrintData(vector<int>&data) {
    for (int i=0;i<data.size();i++) {
	    cout<<data[i]<<endl;
    }

}



void Sort::BubbleSort(vector<int>&data) {
    for(int i=0;i< data.size()-1;i++) {
	    bool flag = true;
	    for(int j = 0; j < data.size()-1-i; j++) {
	        if(data[j] > data[j+1]) {
		        swap(data[j],data[j+1]);
		        flag = false;
	        }
	    }
	    if(flag==true)break;  // 当出现一次没有互换的情况，则说明已经OK 
    }
}

