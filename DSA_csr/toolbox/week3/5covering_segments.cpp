#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points,a;

  for (size_t i = 0; i < segments.size()-1; i++) {
    for( size_t j=i+1; j < segments.size(); j++) {
        int temp;
	if(segments[i].start>segments[j].start)  { temp=segments[i].start;   segments[i].start=segments[j].start;   segments[j].start=temp;
						   temp=segments[i].end;   segments[i].end=segments[j].end;   segments[j].end=temp;	  }
    	
     }
  }
  a.push_back(segments[0].start);
  a.push_back(segments[0].end);
  size_t j=0;
  for (size_t i = 1; i < segments.size(); ++i) {
      

	if(segments[i].start<=a[j+1]) {
		a[j]=segments[i].start;
		if(segments[i].end<a[j+1])  a[j+1]=segments[i].end;   }
	else {
		j+=2;
		a.push_back(segments[i].start);
  		a.push_back(segments[i].end);   }
  }
  for(size_t j=0;j<a.size();j+=2){
	points.push_back(a[j+1]);
  }	
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  printf("\n");
}
