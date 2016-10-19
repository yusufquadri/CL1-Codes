#include<stdio.h>
#include<omp.h>
 int x[25],used[25];
 int adj[25][25]={0};
 int path[25][25],wght[25];
 int c,min;
 int path_ok(int k,int n)
 {
 if(used[x[k]])
 return 0;
 if(k<n-1)
 return(adj[x[k-1]][x[k]]);
 else
 return(adj[x[k-1]][x[k]] && adj[x[k]][x[0]]);
 }
 void TSP(int k,int n)
 {
 int i,sum;
 
 for(x[k]=1;x[k]<n;x[k]++)
 {
 if(path_ok(k,n))
{
 used[x[k]]=1;
 if(k==n-1)
 {
 sum=0;
 printf("\n\n\tPOSSIBLE PATH %d : ",c+1);
  
 for(i=0;i<n;i++)
 {
 printf("%d\t",x[i]);
 path[c][i]=x[i];
 sum+=adj[x[i]][x[i+1]];
 }
 printf(" : %d",sum);
 wght[c]=sum;
 if(c==0 || sum<min)
 min=sum;
 c++;
 used[x[k]]=0;
 }
 else
 TSP(k+1,n);
 used[x[k]]=0;
}
 }
 }
 void findmin(int n)
 {
 int i,j;
   #pragma omp parallel for 
 for(i=0;i<c;i++)
if(wght[i]==min)
{
 printf("\n\n\tMINIMUM PATH : ");
 
 for(j=0;j<n;j++)
 printf("%d\t",path[i][j]);
}
 }
 int main()
 {
 int i,n,j;
 int edg;
 printf("\n\n\t\tTRAVELLING SALESMAN PROBLEM\n\n");
 printf("\n\tEnter the no. of Cities : ");
 scanf("%d",&n);
 printf("\n\n Enter the Cost if path Exist Between cities.:{c1,c2}.Else Enter 0\n\n");
 printf("\n\tCITIES\t\tCOST\n\n");
 
 for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
{
 printf("\n\t %d------ %d \t:",i,j);
 scanf("%d",&edg);
 if(edg)
 adj[i][j]=adj[j][i]=edg;
 }
 used[0]=1;
 TSP(1,n);
 if(!c)
 printf("\n\n\t\tNO PATH FOUND TO COVER ALL THE CITIES\n\n");
 else
 {
 printf("\n\n\t\tMINIMUM COST IS %d AND THE PATHS ARE \n\n",min);
 findmin(n);
 }
 printf("\n");
 return 0;
 }
