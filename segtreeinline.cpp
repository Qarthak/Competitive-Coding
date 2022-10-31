#include <cstdio>
#include <iostream>

using namespace std;

int segTree[2001000];
int arr[1000000];

#define BAD_VAL 2147483647

void updateTree(int requiredElement, int curStart, int curEnd, int index){
	if (requiredElement>curEnd || requiredElement < curStart){
		return;
	}
	
	if(curStart==curEnd){ 
		segTree[index] = arr[curStart];
	}
	else{
		int mid = curStart + (curEnd-curStart)/2;
		updateTree(requiredElement,curStart,mid,index*2+1);
		updateTree(requiredElement,mid+1,curEnd,index*2+2);
		segTree[index] = segTree[index*2+1] + segTree[index*2+2];
	}
}

int queryTree(int requiredStart, int requiredEnd, int curStart, int curEnd, int index){
	if (requiredStart>curEnd || requiredEnd < curStart){
		return BAD_VAL;
	}
	else if (requiredStart<=curStart && requiredEnd>=curEnd){
		return segTree[index];
	}
	else{
		int mid = curStart + (curEnd-curStart)/2;
		int leftQuery  = queryTree(requiredStart,requiredEnd,curStart,mid,index*2+1);
		int rightQuery = queryTree(requiredStart,requiredEnd,mid+1,curEnd,index*2+2);
		return leftQuery+rightQuery;
	}
}

int makeTree(int start, int end, int index){
	if (start==end){
		segTree[index] = arr[start];
	}
	else{
		int mid = start + (end-start)/2;
		int leftQuery =  makeTree(start,mid,index*2+1);
		int rightQuery = makeTree(mid+1,end,index*2+2);
		segTree[index] = leftQuery + rightQuery;
	}
	return segTree[index];
}

long long answer(){
	
}

int main(){
	int n;
	cin >> n;
	for (int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	makeTree(0,n-1,0);
	while (1){
		int c,a,b;
		scanf("%d %d %d",&c,&a,&b);
		if (c==1)
			printf("%d\n", queryTree(a,b,0,n-1,0));
		if (c==2){
			arr[a] = b;
			updateTree(a,0,n-1,0);
		}
	}
}
