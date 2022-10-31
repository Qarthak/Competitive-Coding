#include <iostream>
#include <vector>
#include <map>
#include <set>


struct Line
{
	double a,b,c;
	bool operator<(Line const& other) const
	{
		return (this->a<other.a) + (this->a==other.a)*(this->b<other.b) + (this->a==other.a && this->b==other.b)*(this->c<other.c);
	}
};

struct Point2D { 
	double x, y; 
	Point2D(){
		this->x=0;
		this->y=0;
	}
	Point2D(double p_x, double p_y){
		this->x=p_x;
		this->y=p_y;
	}
};

using namespace std;

int main(){
	int NUM=4;
	vector<Point2D> A(NUM*NUM);
	for(int i=0 ; i<NUM ; i++){
		for(int j=0; j<NUM ; j++){
			A[i*NUM+j]=Point2D((double)i, (double)j);
		}
	}
	
	    map<Line, set<int>> setOfLines;
	for(int i=0 ; i<A.size() ; i++){
		for(int j=i + 1 ; j<A.size() ; j++){
			double delX=A[j].x-A[i].x;
			double delY=A[j].y-A[i].y;
			Line line{
				delX?(delY/delX):(-1),
				delX?(-1):(delX/delY),
				0
			};
			line.c= -line.a*A[i].x -line.b*A[i].y;
			if(line.a || line.b){
				setOfLines[line].insert(i);
				setOfLines[line].insert(j);
			}
		}
	}
    long long ans=0;
	for(auto& i : setOfLines){
		if(i.second.size()<3)
			continue;
		int pointsOnLine=i.second.size();
		ans+=((pointsOnLine)*(pointsOnLine-1)*(pointsOnLine-2))/6;
		if(ans>100000000){
            return -1;
        }
	}
    cout << ans << endl ;


	// int ans=0;
	// map<Line, set<int>> result;
	// for(int i=0 ; i<A.size() ; i++){
	// 	for(int j=i + 1 ; j<A.size() ; j++){
	// 		double delX=A[j].x-A[i].x;
	// 		double delY=A[j].y-A[i].y;
	// 		Line line{
	// 			delX?(delY/delX):(-1),
	// 			delX?(-1):(delX/delY),
	// 			0
	// 		};
	// 		line.c= -line.a*A[i].x -line.b*A[i].y;
	// 		if(line.a || line.b){
	// 			result[line].insert(i);
	// 			result[line].insert(j);
	// 		}
	// 	}
	// }

	// cout << ans << endl ;
	return 0;
}

		// for(auto j=i.second.begin() ; j != i.second.end() ; j++){
		// 	cout << " (" << A[*j].x << ", " << A[*j].y << ")";
		// }
