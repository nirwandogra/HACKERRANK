HACKERRANK
==========
PEG SOLITAIRE----HACK JULY
// Author: NIRWAN DOGRA
#include<bits/stdc++.h>
using namespace std;
int gr[111][111];
int visit[111][111];
int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};
int N,T;
int arr[5][5];

void find_cyclic(int x,int y,int per)
{
   visit[x][y]=per;
   for(int  i=0; i<4; i++)
   {
      int newx=(x+dx[i])%N;
      int newy=(y+dy[i])%N;
      if(gr[newx][newy]==per && newx<N && newy<N && newx>=0 && newy>=0 && visit[newx][newy]==0)
      {
         visit[newx][newy]=per;
         find_cyclic(newx,newy,per);
         return ;
      }
   }
   return ;
}
int validate()
{
   if(!(gr[arr[0][0]][arr[0][1]]==1 && gr[arr[1][0]][arr[1][1]]==2 && gr[arr[2][0]][arr[2][1]]!=gr[arr[3][0]][arr[3][1]]))
   {
      return 0;
   }
   visit[arr[0][0]][arr[0][1]]=0;
   visit[arr[1][0]][arr[1][1]]=0;
   find_cyclic(arr[0][0],arr[0][1],1);
   find_cyclic(arr[1][0],arr[1][1],2);
   int ret=1;
   for(int i=0; i<2; i++)
   {
      for(int j=0; j<N; j++)
      {
         if(visit[i][j]==0)
         {
            ret=0;
         }
         visit[i][j]=0;
      }
   }
   return ret;
}

void print(int x,int y,int per)
{
   cout<<per<<": "<<x<<" "<<y<<endl;
   visit[x][y]=per;
   for(int  i=0; i<4; i++)
   {
      int newx=(x+dx[i])%N;
      int newy=(y+dy[i])%N;
      if(gr[newx][newy]==per && newx<N && newy<N && newx>=0 && newy>=0 && visit[newx][newy]==0)
      {
         visit[newx][newy]=per;
         print(newx,newy,per);
         visit[newx][newy]=0;
         return ;
      }
   }
   return ;
}
int flag;
int cnt=0;
void solve(int x,int y)
{
   if(flag==1)
   {
      return;
   }
   if(x==0 && y==N)
   {
      solve(1,0);
      return ;
   }
   if(y==N && x==1)
   {
      int valid=validate();
      if(valid)
      {
         print(arr[0][0],arr[0][1],1);
         print(arr[1][0],arr[1][1],2);
         flag=1;
         return ;
      }
      return ;
   }
   gr[x][y]=1;
   solve(x,y+1);
   gr[x][y]=2;
   solve(x,y+1);
   gr[x][y]=-1;
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("in.txt","r",stdin);
#endif
   cin>>T;
   while(T--)
   {
      cin>>N;
      for(int i=0; i<2; i++)
      {
         for(int j=0; j<N; j++)
         {
            gr[i][j]=-1;
            visit[i][j]=0;
         }
      }
      int x,y;
      for(int i=0; i<4; i++)
      {
         cin>>x>>y;
         arr[i][0]=x;
         arr[i][1]=y;
      }
      flag=0;
      solve(0,0);
   }
}
