//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int n, int k) 
    { 
        map<int, int> prefixsummap;
        int sum=0;
        int maxlen=0;
        for(int i=0;i<n;++i){
        //calculate the prefix sum till index i
        sum+=A[i];
        
        //if sum=k, update maxlen
        if(sum==k)
            maxlen=max(maxlen,i+1);
        
        //calculate the sum of the remaining part i.e. x-k
        int rem=sum-k;

        //calculate the length and update maxlen
        if(prefixsummap.find(rem)!=prefixsummap.end()){
            int len=i-prefixsummap[rem];
            maxlen=max(maxlen,len);
        }

        //finally, update the map checking the conditions
        if(prefixsummap.find(sum)==prefixsummap.end())
            prefixsummap[sum]=i;
    }
    return maxlen;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends