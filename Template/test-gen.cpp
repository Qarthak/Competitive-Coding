#include<bits/stdc++.h>
using namespace std;
 
//Number of testcases
#define NUM_TESTS 100

//These many numbers will be generated per testcase
#define NUMBERS_PER_TEST 2

// Define the range of the test data generated
#define MAX_RAND 100


int main()
{
    freopen("Test_Cases.in", "w", stdout);
	cout << NUM_TESTS << endl ;
	for(int i=0;i<NUM_TESTS;i++)
    {
		srand(time(NULL)+i);
		for (int j=1; j<=NUMBERS_PER_TEST; j++)
			printf("%d ",rand() % (MAX_RAND) );
		cout << endl ;
	}
}