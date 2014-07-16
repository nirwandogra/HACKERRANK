//==========================================================================
// Author      : NIRWAN DOGRA
// Version     : 4.3.2
// Copyright   : Your copyright notice
// Description : C++, Ansi-style
//============================================================================
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cassert>
#include<vector>
#include<string>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<bitset>
#include<cstdio>
#include<cmath>
#include<climits>
#include<ctime>
#include<string>
#include<fstream>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#ifndef ONLINE_JUDGE
#define DEBUG 1
//#include<conio.h>
#endif
//////////definitions
#define he cout<<"HERE"<<endl;
#define ones7 1111111
#define ones6 111111
#define ones5 11111
#define ge getch();
#define pi pair<int,int>
#define pii pair<pi,int>
#define ff first
#define ss second
#define ST set<int>
#define VEC vector<int>
#define QU queue<int>
#define MAP map<int ,int>
#define l long
#define ll long long
#define forr(i,n) for(int i=0;i<n;i++)
#define forrr(i,j,n) for(int i=j;i<n;i++)
#define S(n) scanf("%d",&n);
#define P(n) printf("%d\n",n);
#define SL(n) scanf("%lld",&n);
#define PL(n) printf("%lld\n",n);
#define C(n) cin>>n;
#define PAUSE system("pause");
#define SET(a,val) memset(a,val,sizeof a);
#define pb push_back
#define CO(n) cout<<n<<endl;
#define MOD 1000000007
#define INF 1000000007
#define foreach(it,container) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define NAME "problem"

using namespace std;
//power function
inline int max_(int a,int b){if(a>=b){return a;}else return b;}
inline int min_(int a,int b){if(a>=b){return b;}else {return a;}}
inline int mod(int a,int b){return (a < b ? a : a % b); }
long long powmod(int n, int p) {long long r = 1, b = n;while(p > 0) {if(p & 1) { r = r * b; if(r >= MOD) r %= MOD; }p >>= 1;b = b * b; if(b >= MOD) b %= MOD;}return r;}
int dx[] = {0, 1, 0, -1};int dx2[] = {0, 1, 0, -1,1,-1,1,-1};
int dy[] = {1, 0, -1, 0};int dy2[] = {1, 0, -1, 0,1,-1,-1,1};

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

////MAIN CODE BEGINS NOW...........
void generatetests(int N)
{
  srand(time(NULL));
  ofstream myfile;
  myfile.open ("in.txt");
  myfile<<N<<endl;
  for(int i=0;i<N;i++)
  myfile<<rand()<<" ";

  myfile.close();
}

 queue<pi>empty;
 int T;int a[11][11];vector<pii>mov;char str[111];
int N, M;

int check(int r,int c)
{
    if(r>=N || c>=M || r<0 || c<0)
    {
    	return  0;
    }
   return 1;
}

int print()
{
	forr(i,N)
	{
		forr(j,N)
		{
			if(a[i][j]==-1) printf("x ");
			if(a[i][j]==1) printf("P ");
			if(a[i][j]==0) printf("O ");
		}
		CO("")
	}
	CO("")
//	ge
}

int main()
{
	//#ifndef ONLINE_JUDGE
	//generatetests(1000);
//	freopen("in.txt","r",stdin);
  //   freopen("out.txt","w",stdout);
    //#endif
     
 string s[4]={"LEFT","RIGHT","DOWN","UP"};
 int dx[4]={0,0,-2,2};int dy[4]={2,-2,0,0};int d2x[4]={0,0,-1,1};int d2y[4]={1,-1,0,0};
 
 C(N>>M);
 forr(i,N)
 {
 	C(str)
 	forr(j,M)
 	{
 		if(str[j]=='x') a[i][j]=-1;;
 		if(str[j]=='.') a[i][j]=1;
 		if(str[j]=='-')
 	     {
 	     	a[i][j]=0;
 	     	empty.push(pi(i,j));
 	     }
 	}
 }
 int cnt=0;
 
 while(empty.size()>0)
 {
       pi hole=empty.front();
	  empty.pop();int x=hole.ff;int y=hole.ss;
	//  CO(x<<" hole "<<y)
	  forr(j,4)
	  {
	  	int newx=x+dx[j];int newy=y+dy[j];
	  	int jumpx=x+d2x[j];int jumpy=y+d2y[j];
		if(check(newx,newy)==1 && a[newx][newy]==1 && a[jumpx][jumpy]==1)
	  	{
	  	//	CO("picking "<<newx<<" "<<	newy)
	  		cnt++;
	  		a[jumpx][jumpy]=0;
	  		a[newx][newy]=0;
	  		a[x][y]=1;
	  		empty.push(pi(newx,newy));empty.push(pi(jumpx,jumpy));
	  		mov.pb(pii(pi(newx,newy),j));
	  //		print();
	  		break;
	  	}
	  } 	
 }
 CO(mov.size())
 forr(i,mov.size())
 {
 	CO(mov[i].ff.ss<<" "<<mov[i].ff.ff<<" "<<s[mov[i].ss])
 }
 return 0;
 double cl = clock();
 fprintf(stderr, "Total Time: %lf\n", (clock() - cl) / CLOCKS_PER_SEC);
return 0;
}




