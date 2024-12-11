#include<stdio.h>

int size;
int sapXep = 0;
void inMenu(){
	printf("\n\--------MENU--------\n");
	printf("\n1. Nhap vao so phan tu va gia tri cho mang.\n");
	printf("2. In ra cac phan tu trong mang.\n");
	printf("3. Them vao phan tu moi.\n");
	printf("4. Sua phan tu.\n");
	printf("5. Xoa phan tu.\n");
	printf("6. Sap xep cac phan tu.\n");
	printf("7. Tim kiem phan tu.\n");
	printf("8. Thoat\n");	
}
void nhapMang(int arr[]){
	printf("Nhap vao kich thuoc cua mang: ");
	scanf("%d", &size);
	if(size > 0){
		for(int i = 0; i < size; i++){
			printf("Nhap vao phan tu thu %d cua mang: ", i + 1);
			scanf("%d", &arr[i]);
		}
	}else{
		printf("kich thuoc mang khong hop le");
	}
}

void inMang(int arr[]){
	if(size > 0){
		for(int i = 0; i < size; i++){
			printf("arr[%d] = %d\n", i, arr[i]);
		}
	}else{
		printf("chua khoi tao mang");
	}
}

int themPhanTu(int arr[]){
	if(size > 0){
		int viTri, phanTu;
		printf("Nhap vao vi tri muon them: ");
		scanf("%d", &viTri);
		if(viTri < 0|| viTri > size){
			printf("vi tri khong hop le\n");
			return -1;
		}
		printf("Nhap vao phan tu muon them: ");
		scanf("%d", &phanTu);
		for(int i = size; i > viTri-1; i--){
			arr[i] = arr[i - 1];
		}
		arr[viTri - 1] = phanTu;
		size ++;
	}else{
		printf("chua khoi tao mang");
	}
}

int suaPhanTu(int arr[]){
	if(size > 0){
		int viTri, phanTu;
		printf("Nhap vao vi tri muon sua: ");
		scanf("%d", &viTri);
		if(viTri < 0|| viTri > size){
			printf("vi tri khong hop le\n");
			return -1;
		}
		printf("Nhap vao phan tu muon sua: ");
		scanf("%d", &phanTu);
		arr[viTri - 1] = phanTu;
	}else{
		printf("chua khoi tao mang");
	}
}

int xoaPhanTu(int arr[]){
	if(size > 0){
		int viTri;
		printf("Nhap vao vi tri muon xoa: ");
		scanf("%d", &viTri);
		if(viTri < 0|| viTri > size){
			printf("vi tri khong hop le\n");
			return 1;
		}
		for(int i = viTri - 1; i < size; i++){
			arr[i] = arr[i + 1];
		}
		size --;
	}else{
		printf("chua khoi tao mang");
	}
}

void hamSapXep(int arr[]){
	int choice;
	printf("1. sap xep giam dan\n");
	printf("2. sap xep tang dan\n");
	printf("Nhap kieu sap xep: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			for(int i = size - 1; i > 0; i--){
				for(int j = 0; j < i; j++){
					if(arr[j] < arr[j+1]){
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
			sapXep = 1;
			break;
		case 2:
			for(int i = size - 1; i > 0; i--){
				for(int j = 0; j < i; j++){
					if(arr[j] > arr[j+1]){
						int temp = arr[j];
						arr[j] = arr[j+1];
						arr[j+1] = temp;
					}
				}
			}
			sapXep = 1;
			break;
		default:
			printf("sai cu phap\n");
	}
	
}

void hamTimKiem(int arr[]){
	int choice;
	int search;
	int check = 0;
	printf("1. tim kiem tuyen tinh\n");
	printf("2. tim kiem nhi phan\n");
	printf("Nhap kieu sap xep: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("nhap vao phan tu can tim: ");
			scanf("%d", &search); 
			for(int i = 0; i < size; i++){
				if(search == arr[i]){
					printf("Phan tu ton tai trong mang\n");
					check++;
				}
			}
			if(check == 0){
				printf("Phan tu khong ton tai trong mang\n");
			}
			break;
		case 2:
			if(sapXep == 1){
				int left = 0;
				int right = size - 1;
				printf("So can tim: ");
				scanf("%d", &search);
				while (left <= right) {
			        int mid = left + (right - left) / 2;
			        if (arr[mid] == search) { 
			        	check =1;
			            break;
			        }
			        if (arr[mid] > search) {
			            right = mid - 1;
			        } 
			        else {
			            left = mid + 1;
			        }
			    }
			    left = 0;
				right = size - 1;
			    while (left <= right) {
			        int mid = left + (right - left) / 2;
			        if (arr[mid] == search) { 
			        	check =1;
			            break;
			        }
			        if (arr[mid] > search) {
			        	left = mid + 1;
			        } 
			        else {
			            right = mid - 1;
			        }
			    }
			    if (check != 0) {
			        printf("Phan tu ton tai trong mang\n");
			    } else {
			        printf("Phan tu khong ton tai trong mang\n");
			    }
			}else{
				printf("chua sap xep mang");
			}
			break;
		default:
			printf("sai cu phap\n");
	}
	
}

int main(){
	int arr[100];
	int choice;
	do{
		inMenu();
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				nhapMang(arr);
				break;
			case 2:
				inMang(arr);
				break;
			case 3:
				themPhanTu(arr);
				break;
			case 4:
				suaPhanTu(arr);
				break;
			case 5:
				xoaPhanTu(arr);
				break;
			case 6:
				hamSapXep(arr);
				break;
			case 7:
				hamTimKiem(arr);
				break;
			case 8:
				printf("thoat!");
				break;
			default:
				printf("sai cu phap!\n");
				
				
		}	
	}while(choice != 8);
	
	return 0;
}
