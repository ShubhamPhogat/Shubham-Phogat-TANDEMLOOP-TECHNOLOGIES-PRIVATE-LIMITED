#include <bits/stdc++.h>
using namespace std;


int main() {
	// your code goes here
	string s;
	cin>>s;
	
	try
	{
	    int n=stoi(s);
	
	vector<int>series;
	int i=0,number=1;
	
	while(i<n)
	{
	    series.push_back(number);
	    for(auto it:series)cout<<it<<" ";
	    cout<<endl;
	    number+=2;
	    i++;
	}
	
	}
	catch(const exception& e)
	{
	    cout<<"Error :"<<e.what()<<endl;
	}
	catch(const invalid_argument& e)
	{
	    cout<<"Error :"<<e.what()<<endl;
	}

}
