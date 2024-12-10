#include<stdio.h>
int  UCLN(int a, int b){
	
    if (b == 0) {
    	return a;
	}
    return UCLN(b, a % b);
}
int main(){
	int a,b;
	printf("nhap so nguyen duong thu nhat:");
	scanf("%d",&a);
	printf("nhap so nguyen duong thu hai:");
	scanf("%d",&b);
	if(a<0||b<0){
		printf("loi!"); 
	}else{
			 printf("UCLN cua %d và %d là: %d", a, b, UCLN(a, b));
	} 
    return 0; 
}	
