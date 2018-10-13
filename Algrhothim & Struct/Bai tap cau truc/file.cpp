/***************************** THAO TAC VOI FILE ********************/
#include	<fstream>
ifstream fi;
ofstream fo;

int mo_fDoc(char a[]){
	fi.open(a);
	if(fi) return 1;
	return 0;
}
int mo_fGhi(char a[]){
	fo.open(a);
	if(fo) return 1;
	return 0;
}
void dong_FDoc(){
	fi.close();
}
void dong_FGhi(){
	fo.close();
}
