#include<stdio.h>
#include<string.h>          
#include<math.h>
int kt1(int n){
	int s=0;
	while (n>0){
		s=s+n%10;
		n=n/10;
	}
	if (s%10==0) return 1;
	return 0;
}           
int kt2(int n){
	int s=0,m=n;
	while (n>0){
		s=s*10+n%10;
		n=n/10;
	}
	if (s==m) return 1;
	return 0;
}        

main(){
	FILE *fi,*fo;
	int t,k,n;
	fi=fopen("input.dat","r+");
	fo=fopen("output.dat","w");
	fscanf(fi,"%d",&t);
	while (t--){
		fscanf(fi,"%d",&k);
		n=0;
		for (int i=pow(10,k-1);i<=pow(10,k)-1;i++){
			if (kt1(i)==1&&kt2(i)==1) n++;
		}
		fprintf(fo,"%d\n",n);
	}                                    
    fclose(fi);
    fclose(fo);                                                                 
}
