#include <iostream>
#include <cmath>

using namespace std;

class node
{
private:
	int data, count;
	node *left, *right;
public:

	node(int n)
	{
		data=0;
		count=1;
		right=left=NULL;
	}

	int getdata()
	{return data;}

	node* getleft()
	{return left;}

	node* getright()
	{return right;}

	void setdata(int x)
	{data=x;}

	void setleft(node *t)
	{left=t;}

	void setright(node *t)
	{right=t;}

	int getcount()
	{return count;}

	void setcount(int n)
	{count=n;}

	void addcount()
	{count++;}

	void reducecount()
	{count--;}
};

class bst
{
private:
	node *head;
	int no_of_elements;

public:
	bst()
	{
		head=NULL;
		no_of_elements=0;
	}

	~bst()
	{empty(head);}

	void empty(node *t)
	{
		if( t->getleft()!=NULL )
			empty(t->getleft());
		if( t->getright()!=NULL)
			empty(t->getright());
		delete t;
	}
	/* in this implementation, we are not keeping duplicate nodes, however keeping count of the occurences of nodes */
	void insert(int n)
	{
		node *t;
		t->setdata(n);
		if ( head==NULL)
		{
			head = t;
		}

		else
		{
			node *t=head, *s;
			while(1)
			{
				if( n<t->getdata() )
				{
					if(t->getleft()==NULL)
					{
						s = new node(n);
						t->setleft(s);
						no_of_elements++;
						return;
					}
					t=t->getleft();
				}

				else if( n>t->getdata())
					{
						if(t->getright()==NULL)
						{
							s = new node(n);
							t->setright(s);
							no_of_elements++;
							return;
						}
						t=t->getright();
					}
				else
					{t->addcount(); return;}
			}
		}
	}
	// decrease count uptil 1, if count==0, remove node completely
	void del ( int n )
	{
		node *t=head;

		while(t!=NULL)
		{
			if(t->getdata()<n)
			{
				t=t->getright();
			}

			else if( t->getdata()>n)
				{t=t->getright();}

			else
			{
				if( t->getcount() > 1 )
				{
					t->reducecount();
					return;
				}

				else
				{
					t=remove(t);
					return;
				}
			}
		}
		cout<<"\nElement not present in tree\n";
	}//del ends

	node* remove( node *s)
	{
		node *t;
		//if no child
		if( s->getleft()==NULL && s->getright()==NULL)
			{
				delete s;
				t=NULL;
			}

		//if only left child
		else if( s->getleft()!=NULL && s->getright()==NULL)
		{
			t=s->getleft();
			delete s;
		}
		//only right child
		else if( s->getleft()==NULL && s->getright()!=NULL)
		{
			t=s->getright();
			delete s;
		}
		//both children
		else
		{
			t=findmin(s->getright());
			s->setdata(t->getdata());
			s->setcount(t->getcount());
			delete t;
			t=s;
		}

		return t;

	}

	node* findmin(node *t)
	{
		if( t->getleft()==NULL )
			return t;
		
		return ( findmin(t->getleft()));

	}

	int getdepth()
	{
		return log2(no_of_elements);
	}

	
};

int main()
{
	return 0;
}