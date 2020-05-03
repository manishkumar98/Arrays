#include<stdio.h>
#include<stdlib.h>
int* repeatedNumber(int *A,int n,int *length_of_array){
	*length_of_array=2;
	int* result=(int*)malloc(*length_of_array*sizeof(int));
	long long int diff=0;
	long long int sq_sum=0;
	for(int i=0;i<n;i++){
		diff+=(long long int)A[i]-(long long int)i-1;
		sq_sum+=(long long int)A[i]*(long long int)A[i]-((long long int)i+1)*((long long int)i+1);
	}
		long long int sum=(long long int)(sq_sum/diff);
		result[0]=(int)((sum+diff)/2);
		result[1]=(int)((sum-diff)/2);
		return result;
	
}
int main(){
	int n=0;
	int *length_of_array=(int*)malloc(sizeof(int));
	scanf("%d",&n);
	 int A[n];
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	int *B=repeatedNumber(A, n,length_of_array);
	for(int i=0;i<*length_of_array;i++)
	printf("%d\n",B[i]);
	return 0;
}



