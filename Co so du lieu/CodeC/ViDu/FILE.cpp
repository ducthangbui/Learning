# include <conio.h>
# include <stdio.h>
# define in "SO.INP"
# define out "SO.OUT"

int n,M;

void Nhap()
{
FILE *fi;
fi=fopen(in,"rt");
fscanf(fi,"%d%d ",&n,&M );
fclose(fi);
}

void Xuat()
{
FILE  *fo;
fo=fopen(out,"t");
fprintf (fo,"%d\n",n );
for (;n>0;n--) // v?ng l?p kh�ng c� gi� tr? g�n ban �?u
                  fprintf (fo,"%d\n",((2*M+1)-M));
fclose (fo);
}
main()
{

Nhap();
Xuat();
getch();
}

