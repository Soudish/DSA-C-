#include<stdio.h>
#include<stdlib.h>
#define INF 99999
struct edge{
    int src,dest,weight;
};
void bellmanford(struct edge *edges,int source,int e,int v){
    int *dist=(int*)malloc(v*sizeof(int));
    for(int i=0;i<v;i++){
        dist[i]=INF;
    }
    dist[source]=0;
    for(int i=0;i<v-1;i++){
        for(int j=0;j<e;j++){
            int u=edges[j].src;
            int d=edges[j].dest;
            int w=edges[j].weight;
            if(dist[u]!=INF && dist[u]+w<dist[d]){
                dist[d]=dist[u]+w;
            }
        }
    }
    
    for(int j=0;j<e;j++){
        int u=edges[j].src;
        int d=edges[j].dest;
        int w=edges[j].weight;
        if(dist[u]!=INF && dist[u]+w<dist[d]){
            printf("Negative weight cycle found");
            return;
        }
    }
    
        
    printf("--------Single source shortest path-------\n");
    for(int i=0;i<v;i++){
        printf("%d\t%d\n",i,dist[i]);
    }

}
int main(){
    int e,v,source;
    printf("Enter the number of edges and vertices respectively:");
    scanf("%d %d",&e,&v);
    printf("Enter the source vertex:");
    scanf("%d",&source);
    struct edge *edges=(struct edge*)malloc(e*sizeof(struct edge));
    printf("Enter the adjacency List:\n");
    for(int i=0;i<e;i++){
        scanf("%d %d %d",&edges[i].src,&edges[i].dest,&edges[i].weight);
    }
    bellmanford(edges,source,e,v);
    return 0;
}
