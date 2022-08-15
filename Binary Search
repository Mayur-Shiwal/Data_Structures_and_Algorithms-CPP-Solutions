#include <iostream>

using namespace std;

int binarySearch(int arr[],int n,int key){

    int start=0;
    int end=n-1;
    int mid=start+(end-start)/2;                    //int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}

int main()
{
    int arr[7]={2,4,7,9,13,15,19};
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    int key;
    cout<<"Enter the value to find in array: "<<endl;
    cin>>key;
    int index=binarySearch(arr,7,key);

    if(index==-1){
        cout<<"Element not found in given array"<<endl;
    }
    else{
        cout<<"Element found at index: "<<index<<endl;
    }

    return 0;
}
