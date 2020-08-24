#include <iostream>
#include <vector>
using namespace std;
using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int join(vector<int> &a,size_t low,size_t mid,size_t high)
{
	int x[mid-low+1],y[high-mid],c=0;
	for(int i=0;i<mid-low+1;i++)
		x[i]=a[low+i];
	for(int j=0;j<high-mid;j++){
		y[j]=a[mid+j+1];
		int i=mid-low;
		while(x[i]>y[j] && i>=0) {   c++;  i--;  }
	}
	
	int i=0,j=0,k=low;
	while(i<mid-low+1 && j<high-mid){
		if(x[i]>y[j])    {  a[k]=y[j];   k++;  j++; }
		else { 
				a[k]=x[i];   k++;  i++;  }
        }
	while(i<mid-low+1)
		{   a[k]=x[i];  k++; i++;  }
	while(j<high-mid)
		{   a[k]=y[j];  k++;  j++;  }
	return c;	
}
	

int merge(vector<int> &a,size_t low,size_t high){
	int count=0;
	if(low<high){
	int mid = low+(high-low)/2;
	count+=merge(a,low,mid);
	count+=merge(a,mid+1,high);
	count+=join(a,low,mid,high);
	}
	return count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << merge(a, 0, a.size()-1) << '\n';	
}
