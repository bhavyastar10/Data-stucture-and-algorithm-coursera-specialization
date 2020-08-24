#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
using std::vector;
using std::swap;
using std::pair;

pair<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l,k=j;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      k++;
      if(j==k) swap(a[i], a[j]);
      else {  swap(a[i],a[k]);    swap(a[j],a[k]);   }
	}
    else if(a[i]==x)  {   
	k++;    swap(a[i],a[k]);     }
    }

  swap(a[l],a[j]);
  pair<int,int> q=make_pair(j,k);
  return q;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m,n ;
  pair<int,int> p= partition2(a, l, r);
  randomized_quick_sort(a, l, p.first - 1);
  randomized_quick_sort(a, p.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  printf("\n");
}
