#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long sum=0;
	long long fibodd=1;
	long long fibeven=2;
	while(fibeven<=4000000)
	{
		sum+=!(fibeven%2)*fibeven+!(fibodd%2)*fibodd;
		fibodd+=fibeven;
		fibeven+=fibodd;
	}
	cout<<sum;
	return 0;
}