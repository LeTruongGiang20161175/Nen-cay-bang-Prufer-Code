#include <stdio.h>
#include <stdlib.h>


struct Dinh{
	int *a;
	int length;
	int bac;
	bool daXet;
};
int main(){
	// Nhap so canh
	int soCanh;
	printf("Nhap so canh cua cay: ");
	scanf("%d",&soCanh);
	
	// Khoi tao danh sach cac dinh
	Dinh listDinh[soCanh + 1];
	for(int i = 0; i < soCanh + 1; i++){
		listDinh[i].a = (int*)malloc(sizeof(int) * soCanh);
		listDinh[i].bac = 0;
		listDinh[i].daXet = false;
	}
	
	//Nhap cac canh 
	printf("Nhap cac canh: \n");
	for(int i = 0;i < soCanh; i++){
		int u;
		int v;
		scanf("%d",&u);
		scanf("%d",&v);
		listDinh[u].a[listDinh[u].bac++] = v;
		listDinh[v].a[listDinh[v].bac++] = u;
	}
	for(int i = 0;i < soCanh + 1; i++){
		listDinh[i].length = listDinh[i].bac;
	}
	
	
	//Dat 1 bien so Dinh de quan ly cac dinh con lai
	int soDinh = soCanh + 1;
	for(int i = 0;i < soCanh - 1; i++){
		for(int j = 1; j < soDinh; j++){
			if(!listDinh[j].daXet && listDinh[j].bac == 1){
				for(int k = 0; k < listDinh[j].length; k++){
					listDinh[listDinh[j].a[k]].bac--;
				}
				for(int k = 0; k < listDinh[j].length; k++){
					if(!listDinh[listDinh[j].a[k]].daXet){
						printf("%d ",listDinh[j].a[k]);
						break;
					}
				}
				listDinh[j].daXet = true;
				break;
			}
		}
	}	
	
}

