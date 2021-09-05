#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int > arr;
	int temp; 
	while (cin >>temp)
	
	
	{
	
		 arr. push_back		(temp);
	}
	int n=arr.size();
	sort(arr.begin(),arr.end());
	for(auto i : arr){
		cout << i << " " ;
	}
	cout  << "\nnumber of elements is "<<n ;
	int tot=0;
	for (size_t i=0; i<(n+1)/2; i++){
		tot+=arr[i];
	}
	cout << " Total of the leaves is "<<tot << "\n" ;
}