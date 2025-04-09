#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here

	    int n;
	    cin>>n;
	    vector<int>nums;
	    for(int i=0;i<n;i++)
	    {
	        int a;
	        cin>>a;
	        nums.push_back(a);
	    }
	    map<int,int>mp;
	    for(int i=1;i<=9;i++)
	    {
	        mp[i]=0;
	        for(int j=0;j<nums.size();j++)
	        {
	            if(nums[j] % i ==0)mp[i]++;
	        }
	    }
	    for(auto it:mp)
	    {
	        cout<<it.first<<" : "<<it.second<<endl;
	    }
	    
	
}
