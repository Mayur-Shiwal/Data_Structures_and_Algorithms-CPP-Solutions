#include <iostream>

using namespace std;

int getSum(int arr[],int n){

    if(n == 0){
        return 0;
    }
    if(n == 1){
        return arr[0];
    }
    int sum=arr[0]+getSum(arr+1,n-1);
    return sum;


}

int main()
{
    int arr[5]={2,4,6,8,10};
    int ans=getSum(arr,5);
    cout<<ans<<endl;
    return 0;
}
