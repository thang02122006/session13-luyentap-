#include<stdio.h>

int arr[100][100];
void bt7( int n , int m){
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ; j++){
			printf("nhap vao gia tri arr[%d][%d]= ",i,j);
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=0 ; i<n ; i++){
	    for(int j=0 ; j<m ; j++){
		    printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

	
}
int main(){
	int hang ,cot;
	printf("nhap so hang: ");
	scanf("%d",&hang);
	printf("nhap so cot: ");
	scanf("%d",&cot);
	bt7(hang,cot);


	
	return 0;
}
