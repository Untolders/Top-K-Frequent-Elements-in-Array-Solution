***************************************************************************************  Question  *********************************************************************************************************************


Given a non-empty array nums[] of integers of length N, find the top k elements which have the highest frequency in the array. If two numbers have same frequencies, then the larger number should be given more preference.

Example 1:

Input:
N = 6
nums = {1,1,1,2,2,3}
k = 2
Output: {1, 2}
Example 2:

Input:
N = 8
nums = {1,1,2,2,3,3,3,4}
k = 2
Output: {3, 2}
Explanation: Elements 1 and 2 have the
same frequency ie. 2. Therefore, in this
case, the answer includes the element 2
as 2 > 1.
User Task:
You don't have to read or print anything. You will have to complete the function topK() that takes an array nums[] and integer k as input and returns a list of top k most frequent elements. If any two elements have same frequencies, then give more preference to the larger elemet.

Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)

Constraints:
1 <= N <= 105
1<= nums[i] <=105
1 <= k <= N


****************************************************************************************  Solution  ********************************************************************************************************************
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
       int N = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < N; i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int> >pq;
        for(auto x : mp){
            pq.push({x.second , x.first});
        }
        vector <int> ans;
        for(int i = 0 ; i < k ; i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends


