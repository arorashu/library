#include <iostream>
#include <vector>
using namespace std;

class segtree //for range sum query
{
private:
	vector<long> v;
	vector<pair<long, long> > p;

public:
	segtree(long a[], long n)
	{
		v.reserve(2*n);
		p.reserve(2*n);
		maketree(a,1,0,n-1);
	}

	void maketree(long a[],long node, long i, long j)
	{
		if(i==j) // leaf nodes , 
		{
			v[node]=a[i];
			p[node]=make_pair(i,i);
			return ;
		}

		maketree(a,(2*node),i,(i+j)/2);//build left tree
		maketree(a,(2*node)+1,((i+j)/2)+1,j);//build right tree
		v[node]=v[node*2]+v[(node*2)+1];	//add sum of both the trees
		p[node]=make_pair(i,j);
	}

	long rangesum(long i, long j)
	{
		return rsum(1,i,j);
	}

	long rsum( long node, long i, long j)
	{
		if(p[node].first >j || p[node].second <i)
			return 0;

		if(p[node].first==i && p[node].second==j)
			return v[node];

		long m=p[2*node].second;
		if( j>m )
			return rsum(2*node,i,m) + rsum((2*node)+1,m+1,j);

		return rsum(2*node,i,j) + rsum(2*node+1,i,j);
	}

};


int main()
{
	std::ios_base::sync_with_stdio(false);

	long n, a[100];
	cout<<"How many array elements? : ";
	cin>>n;
	cout<<"Enter array elements: ";
	for(long i=0; i<n; i++ )
		cin>>a[n];

	segtree s(a,n);

	int i, j;
	cout<<"Enter the range for which sum is required: ";
	cin>>i>>j;

	cout<<"the range sum is: "<<s.rangesum(i-1,j-1)<<'\n';

	return 0;
}