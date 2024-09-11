#include <stdio.h>
#include <string.h>
//Ωªªª 
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
	
}
//≈≈–Ú 
void sequence(int a[],int len){
	for(int i=1;i<len;i++){
		for(int j=0;j<i;j++){
			if(a[i]<a[j]){
				swap(&a[i],&a[j]);
			}
		}
	}
}
int main(){
	int a[]={3,8,1,9,4,6,11};
	int len=sizeof(a)/sizeof(a[0]);
	sequence(a,len);
	for(int i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}
