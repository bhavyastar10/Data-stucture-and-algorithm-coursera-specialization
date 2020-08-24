#include<iostream>

using namespace std;

void selection(int a[],int n)
{
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min])  min=j;
		if(min!=i) {   int temp=a[i];
				a[i]=a[min];
				a[min]=temp; }
  	}
}

int main(){
	int n;
	cout<<"enter the size of array: ";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cout<<"enter the "<<i+1<<" index value: ";
		cin>>a[i];
		}
	selection(a,n);
	cout<<"your sorted array is:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	printf("\n");
	return 0;
}
