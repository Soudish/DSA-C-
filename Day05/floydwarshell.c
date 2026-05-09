#include<stdio.h>
#include<stdlib.h>
#define INF 99999
void floydwarshell(int **graph,int n){
	for(int k=0;k<n;k++){
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(graph[i][k]!=INF && graph[k][j]!=INF && graph[i][j]>graph[i][k]+graph[k][j]){
					graph[i][j]=graph[i][k]+graph[k][j];
				}
			}
		}
	}
	printf("Shortest Path:----\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(graph[i][j]==INF){
				printf("INF  ");
			}
			else{
				printf("%d  ",graph[i][j]);
			}
		}
		printf("\n");
	}


}
int main(){
	int n;
	printf("Enter the number of vertex:");
	scanf("%d",&n);
	int **graph=(int**)malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		graph[i]=(int*)malloc(n*sizeof(int));
	}	
	printf("Enter the adjacency matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&graph[i][j]);
		}
	}
	floydwarshell(graph,n);
	return 0;

}