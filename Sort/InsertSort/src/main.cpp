#include "common.h"



int main() {
    int arr[] = {10,4,2,3,1,4,15,6,13,43,23,12,56,17};
    int len = sizeof(arr)/sizeof(arr[0]);
    vector<int>a(arr,arr+len);
    Sort q;
    q.InsertSort(a); 
    q.PrintData(a);
    return 0;

}
