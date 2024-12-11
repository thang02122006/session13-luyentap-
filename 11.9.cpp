#include<stdio.h>

void delayMenu(){
	printf("\n-------------------------MENU--------------------------\n");
	printf("1.Nhap gia tri cac phan tu cua ham\n");	
	printf("2.In cac gia tri cua mang theo ma tran\n");	
	printf("3.In ra cac phan tu o goc\n");	
	printf("4.In cac phan tu tren duong bien\n");	
	printf("5.In cac phan tu tren duong cheo chinh va duong cheo phu\n");	
	printf("6.In ra cac phan tu la so nguyen to\n");	
	printf("7.Thoat\n");	
}

void scan(int n, int m, int arr[][100]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Nhap phan tu arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
void print(int n, int m, int arr[][100]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			printf("%d\t", arr[i][j]);	
		}
		printf("\n");
	}
}
int testSize(int n, int m){
	if (n<=0 || m <=0){
			printf("Khong hop le\n");
	} else {
		return 1;
	}
}
int cornerNum(int n, int m, int arr[][100]){
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (i==0&&j==0 || i==0&&j==m-1 || i==n-1&&j==0 || i==n-1&&j==m-1){
				printf("%d\t", arr[i][j]);
			}
		}
		printf("\n");
	}
}
int borderNum(int n, int m, int arr[][100]){
    for (int i = 0; i < m; i++) {
        printf("%d ", arr[0][i]);
    }
    for (int i = 1; i < n - 1; i++) {
        printf("%d ", arr[i][m - 1]);
    }
    if (n > 1) {
        for (int i = m - 1; i >= 0; i--) {
            printf("%d ", arr[n - 1][i]);
        }
    }
    if (m > 1) {
        for (int i = n - 2; i > 0; i--) {
            printf("%d ", arr[i][0]);
        }
    }
}
int testSquare(int n, int m){
	if(n!=m){
		printf("Mang khong hop le\n");
		return 0;
	} else {
		return 1;
	}
}
int cross(int n, int m, int arr[][100]){
	printf("Cac phan tu tren duong cheo chinh: ");
    for (int i=0; i<n && i<m; i++){
        printf("%d ", arr[i][i]);
    }
    printf("\n");
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i=0; i<n && i<m; i++) {
        printf("%d ", arr[i][m - i - 1]);
    }
    printf("\n");
}
int prime(int n){
    if (n<=1){
		return 0;
	} else {
	    for (int i=2; i*i<=n; i++){
	        if (n%i==0) {
				return 0; 
			}
	    }
	}
    return 1;
}
int main(){
	int choice,row,col;
	int arr[100][100];
	do{
		delayMenu();
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				printf("Nhap so hang: ");
				scanf("%d", &row);
				printf("Nhap so cot: ");
				scanf("%d", &col);
				testSize(row,col);
				scan(row,col,arr);
				break;
			}
			case 2:{
				testSize(row,col);
				print(row,col,arr);
				break;
			}
			case 3:{
				testSize(row,col);
				cornerNum(row,col,arr);
				break;
			}
			case 4:{
				testSize(row,col);
				borderNum(row,col,arr);
				break;
			}
			case 5:{
				testSquare(row,col);
				cross(row,col,arr);
				break;
			}
			case 6:{
				testSize(row,col);
				printf("Cac so nguyen to trong mang la: ");
			    for (int i = 0; i < row; i++) {
			        for (int j = 0; j < row; j++) {
			            if (prime(arr[i][j])) {
			                printf("%d ", arr[i][j]);
			            }
			        }
			    }
			    printf("\n");
				break;
			}
			case 7:{
				break;
			}
			default:{
				printf("\nKhong hop le\n");
				break;
			}
		}
	}while(choice!=7);
	return 0;
}
