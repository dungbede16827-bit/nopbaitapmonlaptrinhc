#include <stdio.h>
int main () {
	int arr[100],size=0,choice,sum=0,pos,value,search=0;
	int flag = -1;
	int found =0;
	char choice2;

while (1) {
	printf("\n");
	printf("+--------------------Quan ly danh sach so nguyen----------------------+\n");
	printf("+----------------------------------MENU-------------------------------+\n");
	printf("|--------1.khoi tao mang ban dau -------------------------------------|\n");
	printf("|--------2.hien thi danh sach phan tu --------------------------------|\n");
	printf("|--------3. chen them 1 so vao vi tri nhap vao------------------------|\n");
	printf("|--------4.xoa xoa cap nhat theo vi tri ------------------------------|\n");
	printf("|--------5.cap nhat gia tri tai vi tri -------------------------------|\n");
	printf("|--------6. thoat chuong trinh ---------------------------------------|\n");

		
		printf("moi ban nhap chuc nang : ");
		scanf("%d",&choice);
		
	switch (choice) {
			case 1:
					while (1) {
					printf("nhap so luong phan tu : ");
					scanf("%d",&size);
					if(size > 0 || size <= 100){
						break;
					}
						printf("nhap so khong hop le , vui long nhap lai [1-100] \n");
						printf("vui long nhap lai \n");
				}
			
				
				for(int i=0;i<size;i++){
					printf("nhap gia tri cho mang : ");
					scanf("%d",&arr[i]);
				}
				printf("nhap thanh cong %d phan tu !! \n",size);
				break;
		break;
		
	case 2:
			if(size==0) {
					printf ("chua co phan tu nao vui long chon gia tri 1");
				}
				printf("gia tri cua tung mang la : \n");
				for(int i=0;i<size;i++){
					printf("%d, ",arr[i]);
				}
				
		break;
	case 3:
		printf("nhap vi tri muon them phan tu(0-%d) : ",size);
				scanf("%d",&pos);
				printf("nhap gia tri muon them : ");
				scanf("%d",&value);
				
				if(pos<0 || pos > size) {
					printf("vi tri khong hop le ! \n");
					
				} else {
					for(int i = size; i > pos; i--) {
						arr[i] = arr[i-1];
					}
					arr[pos] = value; 
					size++;
					printf ("them thanh cong gia tri %d vao vi tri %d  \n",value,pos);
				
					printf("\n");
				}
		break;
	case 4:
		 printf("Nhap vi tri muon xoa (0-%d): ", size - 1);
   				 scanf("%d", &pos);

    			if(pos < 0 || pos >= size) {
       			 printf("Vi tri khong hop le!\n");
    			} else  {
			  	 printf("Ban co chac chan muon xoa tai vi tri nay khong (Y/N)? ");
   				 scanf(" %c", &choice2);   

    			if (choice2 == 'Y' || choice2 == 'y') {

        
    			    for (int i = pos; i < size - 1; i++) {
       				     arr[i] = arr[i + 1];
      				  }
      				  size--; 

        			printf("Phan tu da duoc xoa thanh cong tai vi tri %d\n", pos);

   				 } else {
        			printf("Huy thao tac xoa.\n");
   						 }
				}
			
		break;
	case 5:
			printf("cap nhat vi tri muon thay doi(0-%d) ",size-1);
				scanf("%d",&pos);
				
				if(pos<0 || pos > size ) {
					printf("gia tri khong hop le");
				} else {
					printf("nhap gia tri can thay doi : ");
					scanf("%d",&value);
					
					arr[pos] = value;
					
					printf("cap nhat thanh cong tai vi tri  %d ",pos);
		break;
	case 6:
		printf("thoat chuong trinh !");
				return 0;
			
		break;

	}











}


}





return 0; 
}



