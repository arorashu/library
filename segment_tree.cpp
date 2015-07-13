#include <iostream>
#include <vector>
#define left 2*node
#define right (2*node)+1
using namespace std;

class segtree //for range sum query
{
private:
	vector<long> v;
	vector<pair<long, long> > p;

public:
	segtree(vector<long> &a)
	{
	    long n=a.size();
		v.resize(4*n+4);
		p.resize(4*n+4);
		maketree(a,1,0,n-1);
	}

	void maketree(vector<long> &a,long node, long i, long j)
	{
		if(i==j) // leaf nodes ,
		{
			v[node]=a[i];
			p[node]=make_pair(i,i);
			return ;
		}

		maketree(a,(left),i,(i+j)/2);//build left tree
		maketree(a,right,((i+j)/2)+1,j);//build right tree
		v[node]=v[left]+v[right];	//add sum of both the trees
		p[node]=make_pair(i,j);
	}

	long rangesum(long i, long j)
    {   return rsum(1,i-1,j-1); }

	long rsum( long node, long i, long j)
	{
		if(p[node].first>j || p[node].second<i)//out of range
            return 0;

		if(p[node].first>=i && p[node].second<=j)// all in range
			return v[node];

		return rsum(left,i,j) + rsum(right, i, j);
	}

	void addvalue(long i, long j, long diff)
    {   addval(1,i-1,j-1, diff); }

    void addval(long node, long i, long j, long diff) // perform basic(non-lazy) updation
    {
        if(p[node].first>j || p[node].second<i)// out of range
            return ;

        if(p[node].first==p[node].second)// if leaf node
        {
        	v[node]+=diff;
        	return;
        }

        addval(left,i,j, diff);
		addval(right, i, j, diff);
		v[node]=v[left]+v[right];
    }

    void setval(long node, long i, long j, long val)
    {
    	if(p[node].first>j || p[node].second<i)// out of range
            return ;

        if(p[node].first==p[node].second)// if leaf node
        {
        	v[node]=val;
        	return;
        }

        setval(left,i,j, val);
		setval(right, i, j, val);
		v[node]=v[left]+v[right];	
    }

    void setvalue(long i, long j, long val)
    {setval(1,i-1,j-1,val);}

    void multiplyvalue(long i, long j, long val)
    { multiplyval( 1,i-1,j-1,val); }

    void multiplyval(long node, long i, long j, long val)
    {
    	if(p[node].first>j || p[node].second<i)// out of range
            return ;

        if(p[node].first==p[node].second)// if leaf node
        {
        	v[node]*=val;
        	return;
        }

        multiplyval(left,i,j, val);
		multiplyval(right, i, j, val);
		v[node]=v[left]+v[right];
    }

};


int main()
{
	std::ios_base::sync_with_stdio(false);

	long n;
	vector<long> a;
	cout<<"How many array elements? : ";
	cin>>n;
	a.resize(n);
	cout<<"Enter array elements: ";
	for(long i=0; i<n; i++ )
		cin>>a[i];

	segtree s(a);
    //s.addvalue(2,3,4);
    s.setvalue(1,1,5);
	int i, j;
	cout<<"Enter the range for which sum is required: ";
	cin>>i>>j;

	cout<<"the range sum is: "<<s.rangesum(i,j)<<'\n';

	return 0;
}
