//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> ans(2, 0);
        priority_queue<pair<int, int>> pq;
        int maxDeadline = -1;
        for(int i=0;i<n;i++){
            pair<int, int> p = {arr[i].profit, arr[i].dead};
            maxDeadline = max(maxDeadline, arr[i].dead);
            pq.push(p);
        }
        vector<int> maxDead(maxDeadline+1, -1);
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            for(int i=p.second;i>=1;i--){
                if(maxDead[i] == -1){
                    ans[1] += p.first;
                    ans[0] += 1;
                    maxDead[i] = p.second;
                    break;
                }
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends