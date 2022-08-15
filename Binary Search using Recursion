#include <iostream>

using namespace std;

bool binarySearch(int *arr, int s, int e, int k){
    if(s>e)
        return false;
    int mid=s+(e-s)/2;
    if(arr[mid] == k)
        return true;
    if(arr[mid]<k)
        return binarySearch(arr,mid+1,e,k);
    else
        return binarySearch(arr,s,mid-1,k);
}

int main()
{
    int arr[5]={2,4,6,8,10};
    bool ans=binarySearch(arr,0,4,8);
    if(ans)
        cout<<"Element found: "<<endl;
    else
        cout<<"Element not found: "<<endl;
    return 0;
}
