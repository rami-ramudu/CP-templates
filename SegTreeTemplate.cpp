#include<bits/stdc++.h>
using namespace std;

void build(int ind,int low,int high,int arr[],int seg[])
{
	if(low==high)
	{
		seg[ind]=arr[low];
		return;
	}
	int mid=(low+high)/2;
	build(2*ind+1,low,mid,arr,seg);
	build(2*ind+2,mid+1,high,arr,seg);
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int low,int high,int l,int r,int seg[])
{
	//no overlap
	//low high l r or l r low high
	if(high<l or r<low) return INT_MAX;

	//Complete overlap
	if( l<=low and high<=r) return seg[ind];
	//partial overlap
    int mid=(low+high)/2;
	int left=query(2*ind+1,low,mid,l,r,seg);
	int right=query(2*ind+2,mid+1,high,l,r,seg);
	return min(left,right);
}
void solve()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  int seg[4*n];
  build(0,0,n-1,arr,seg);
  int q;
  cin>>q;
  while(q--)
  {
  	 int l,r;
  	 cin>>l>>r;
  	 cout<<query(0,0,n-1,l,r,seg)<<"\n";
  }
}



int main()
{
	/* code */
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solve();
	
	return 0;
}
