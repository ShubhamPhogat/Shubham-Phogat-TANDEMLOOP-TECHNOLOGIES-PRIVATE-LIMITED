#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here

	   
	 int n ;
	 cin>>n;
	 if(n<0)
	 {
	     cout<<"enter positive integer"<<endl;
	 }
	 if(n==0)
	 {
	     cout<<0<<endl;
	 }
	 
	 vector<int>series;
	 int number=1;
	 int i=1;
	 while(i<=n)
	 {
	     if(i==1)
	     {
	         series.push_back(number);
	         number+=2;
	     }
	    else  if(i%2)
	     {
	         series.push_back(number);
	         number+=2;
	         series.push_back(number);
	         number+=2;
	     }
	     for(auto it:series)cout<<it<<" ";
	     cout<<endl;
	     i++;
	 }
	 
	 
	
}
