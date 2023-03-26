#define infinity 9999
#define MAX 20
#include<iostream>
#include<stdlib.h>
using namespace std;

class graph{
int g[MAX][MAX];
int n;
public:
graph(){
n=0;
}
void readgraph();
void printgraph();
void dijkstra(int start);
};

void graph::readgraph(){
int i,j,vi,vj,edges,weight;
cout<<"\nEnter no. of Vertices: ";
cin>>n;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
g[i][j]=0;
}
}
cout<<"\nEnter no. of Edges: ";
cin>>edges;
cout<<"\nEnter the list of edges: ";
for(i=0;i<edges;i++)
{
cout<<"\nEnter an edge(u,v,weight) : ";
cin>>vi>>vj>>weight;
g[vi][vj]=g[vj][vi]=weight;
}
}

void graph::printgraph(){
int i,j;
cout<<"\nList of edges in the spanning tree: ";
for(i=0;i<n-1;i++){
for(j=i+1;j<n;j++){
if(g[i][j]!=0){
cout<<"\n(src,dest,weight) = ("<<i<<","<<j<<","<<g[i][j]<<")";
}
}
}
}

void graph::dijkstra(int start){
int cost[MAX][MAX];
int min_dist,distance[MAX],from[MAX];
int visited[MAX],i,j,cnt=0,nextnode;
//create cost matrix
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(g[i][j]==0){
cost[i][j]=infinity;
}
else
cost[i][j]=g[i][j];
}
}
for(i=0;i<n;i++){
distance[i]=cost[start][i];
from[i]=start;
visited[i]=0;
}
distance[start]=0;visited[start]=1;cnt=1;

while(cnt<=n-1){
//find the vertex at min distance from tree
min_dist=infinity;
for(i=0;i<n;i++){
if(visited[i]==0 && distance[i]<min_dist){
nextnode=i;
min_dist=distance[i];
}
}
visited[nextnode]=1;

//update the distance array
for(i=0;i<n;i++){
if(visited[i]==0 &&(min_dist+cost[nextnode][i])<distance[i]){
distance[i]=cost[nextnode][i]+min_dist;
from[i]=nextnode;
}
}
cnt++;
}

for(i=0;i<n;i++){
if(i!=start){
cout<<"\nDistance of "<<i<<" is: "<<distance[i];
cout<<"\tPath = "<<i;
j=i;
do{
j=from[j];
cout<<"<-"<<j;
}while(j!=start);
}
}
}
int main(){
graph g1;
int start;
g1.readgraph();
cout<<"\nGraph is: \n";
g1.printgraph();
cout<<"\nEnter start vertex: ";
cin>>start;
g1.dijkstra(start);
return 0;
}
