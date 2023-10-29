//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        int cnt1=0, cnt2=0;
        int el1=INT_MIN, el2=INT_MIN;
        for(int i=0;i<n;++i){
            if(cnt1==0){
                el1=nums[i];
                cnt1++;
            }
            else if(nums[i]==el1)
                cnt1++;
            else if(cnt2==0){
                el2=nums[i];
                cnt2++;
            }
            else if(nums[i]==el2)
                cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0, cnt2=0;
        for(int i=0;i<n;++i){
            if(nums[i]==el1)    cnt1++;
            else if(nums[i]==el2)   cnt2++;
        }
        //cout<<el1<<" "<<el2<<endl<<cnt1<<" "<<cnt2;
        if(cnt1>n/3)
            ans.push_back(el1);
        if(cnt2>n/3)
            ans.push_back(el2);
        if(ans.size()==0)   ans.push_back(-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends