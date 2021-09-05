#include<stdio.h>
int powe(int x,int y)
{
	if(y==0) return 1;
	return x*powe(x,y-1);
}

int main(int argc, char const *argv[])
{
	int n=29;
	scanf("%d",&n);
	int a[n];
	for (size_t i = 0; i < n; i++)
	{
		a[i]=i;
		scanf("%d", a+i);
	}
	// for (size_t i = 0; i < n; i++)
	// {
	// 	printf("%d ",a[i]);
	// }
	
	int temp=n;
	int level=1;
	while(temp/=2)
	{
		level++;
	}
	
	for (size_t i = 0; i < level; i++)
	{
		for (size_t j = 0; j < powe(2,level-1-i)-1; j++)
		{
			printf("  ");
		}
		
		for (size_t j = 0; j < powe(2,i)&&powe(2,i)+j-1<n; j++)
		{
			printf("%-2d  ",a[powe(2,i)+j-1]);
			for (size_t j = 0; j < powe(2,level-1-i)-1; j++)
			{
				printf("    ");
			}
		}
		printf("\n\n");
		
	}
	
	return 0;
}
