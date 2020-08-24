#include <iostream>
#include <vector>
using namespace std;
using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> den;
  for(auto i=0;i<weights.size();i++)
	{  den.push_back((double)(values[i])/weights[i]);    }
   for (size_t i = 0; i < den.size()-1; i++) {
    for( size_t j=i+1; j < den.size(); j++) {
        double temp;
	int k,x;
	if(den[i]<den[j])  { temp=den[i];   den[i]=den[j];   den[j]=temp;
			     k=weights[i];    weights[i]=weights[j];   weights[j]=k;
			     x=values[i];     values[i]=values[j];     values[j]=x;	 }
     }
  }
  size_t i=0;
  while(i<den.size() && capacity!=0){
	if(capacity>weights[i])  {  value+=(double)values[i];  capacity-=weights[i];  }
	else   {  value+=values[i]*(double)(capacity)/weights[i];   capacity=0;  }
	i++;
	}
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
