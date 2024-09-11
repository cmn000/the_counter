#include <stdio.h>
#include <string.h>
void minmax(int a[],int len,int *max,int *min){
	int i;
	*min=a[0];
	*max=a[0];
	for(i=1;i<len;i++){
		if(a[i]<*min){
			*min=a[i];
		}
		if(a[i]>*max){
			*max=a[i];
		}
	}
	printf("the max num is %d\n",*max);
	printf("the min num is %d\n",*min); 
} 
int main(){
	int a[]={8,3,6,2,3,1};
	int len=sizeof(a)/sizeof(a[1]);
	int max,min;
	minmax(a,len,max,min);
	return 0;
}
