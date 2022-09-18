#include <iostream>
#include <queue>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;
        while(index>1){
            int parent = index/2;
            if(arr[index]>arr[parent]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deletion(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        //take root node to its correct position
        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if(leftIndex<size && arr[leftIndex]>arr[i]){
                swap(arr[leftIndex],arr[i]);
                i = leftIndex;
            }
            else if(rightIndex<size && arr[rightIndex]>arr[i]){
                swap(arr[rightIndex],arr[i]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[],int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[largest]<arr[left]){
        largest = left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest = right;
    }
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    int t = n;
    while(t>1){
        //step 1: swap
        swap(arr[1], arr[t]);
        t--;

        heapify(arr,t,1);
    }
}

int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deletion();
    h.print();

    //heap creation
    int arr[6] = {-1,54,53,55,52,50};
    int n =5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array after heapify: "<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    //heap sort
    heapSort(arr,n);
    cout<<"Printing heap sort"<<endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Using Priority Queue here"<<endl;
    //max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    //max element
    cout<<"Element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"After pop: "<<endl;
    cout<<"Element at top: "<<pq.top()<<endl;
    cout<<"Size is: "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"heap is empty: "<<endl;
    }
    else{
        cout<<"Heap is not empty: "<<endl;
    }

    //min heap
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);

    //max element
    cout<<"Element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"After pop: "<<endl;
    cout<<"Element at top: "<<minheap.top()<<endl;
    cout<<"Size is: "<<minheap.size()<<endl;
    if(minheap.empty()){
        cout<<"heap is empty: "<<endl;
    }
    else{
        cout<<"Heap is not empty: "<<endl;
    }


    return 0;
}
