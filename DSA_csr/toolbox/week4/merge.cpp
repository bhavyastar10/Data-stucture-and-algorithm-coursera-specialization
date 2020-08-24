#include<iostream>

using namespace std;

void join(int a[],int low,int mid,int high)
{
	int x[mid-low+1],y[high-mid];
	for(int i=0;i<mid-low+1;i++)
		x[i]=a[low+i];
	for(int j=0;j<high-mid;j++)
		y[j]=a[mid+j+1];
	int i=0,j=0,k=low;
	while(i<mid-low+1 && j<high-mid){
		if(x[i]>y[j]) {  a[k]=y[j];   k++;  j++; }
		else {  a[k]=x[i];   k++;  i++;  }
        }
	while(i<mid-low+1)
		{   a[k]=x[i];  k++; i++;  }
	while(j<high-mid)
		{   a[k]=y[j];  k++;  j++;  }
	
}
	

void merge(int a[],int low,int high){

	if(low<high){
	int mid = low+(high-low)/2;
	merge(a,low,mid);
	merge(a,mid+1,high);
	join(a,low,mid,high);
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
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	printf("\n");
	merge(a,0,n-1);
	cout<<"your sorted array is:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	printf("\n");
	return 0;
}

	
