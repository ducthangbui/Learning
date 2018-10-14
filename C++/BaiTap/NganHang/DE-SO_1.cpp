// copyright of Trieu Than 15/11/2015 //
// truy cap de biet them thong tin chi tiet: https://www.youtube.com/watch?v=PaDTHfHgTV4 //
// chuc cac ban thi tot! //
// *****Try your best!****** //
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
using namespace std;

class Nguoi{
	protected:
		string ten, diachi, sodt;
	public:
		Nguoi(){ ten = ""; diachi = ""; sodt ="";}
		void nhapN();
		void xuatN();
		string getTen(){ return ten; };
};

class BanDoc: public Nguoi{
	friend class QLMS;
	friend void sapxep();
	friend void timkiem();
	protected:
		static int mab;
		int maBD;
		int loaiBD;
	public:
		BanDoc():Nguoi::Nguoi(){ maBD = 0; loaiBD = 0;}
		void nhapB();
		void xuatB();
		void ghiB( fstream &ofsb ){
			ofsb.write( reinterpret_cast<const char*>(this),sizeof(BanDoc));
		}
		void docB( fstream &ifsb ){
			ifsb.read( reinterpret_cast<char*>(this),sizeof(BanDoc));
		}
		int getMa(){ return maBD;}
};

class Sach{
	friend class QLMS;						// copyright of Trieu Than 15/11/2015 //
	friend void sapxep();					// no thing is impossible! //
	friend void timkiem();
	protected:
		static int mas;
		int maS, loaiS;
		int namxb;
		int cnghanh;
		string tensach;
		string tentg;
	public:
		Sach(){
			maS = 0; namxb = 0; cnghanh = 0; tentg = ""; tensach = "";
		}
		void nhapS();
		void xuatS();
		void docS( fstream &ifss ){ ifss.read( reinterpret_cast <char*> (this), sizeof(Sach));}
		void ghiS( fstream &ofss ){	ofss.write( reinterpret_cast<const char*>(this), sizeof(Sach));}
		int getMaS(){ return maS; }
};

class QLMS{
	protected:
		BanDoc bdi;
		int sluong[15], tongsl;
		int sods, mads[5];
		int trthai[15];
	public:
		QLMS(){ ; sods = 0; }
		void nhapDS( BanDoc & );
		void setTongSL(int t){ tongsl = t;
			for( int i = 0; i< 15; i++ ) sluong[i]= trthai[i] = 0, mads[i] = 0; };
		void setSods(int sds ){ sods = sds;};
		void xuatDS( BanDoc & );
		void ghiDS( BanDoc & );
		void docQ( fstream & );
		int getTongSL(){ return tongsl;}
		int getSods(){ return sods;}
	friend void sapxep();
	friend void timkiem();
};

int BanDoc::mab = 10000;
int Sach::mas = 10000;

void Nguoi::nhapN(){
	cin.ignore();
	cout<<"Nhap ten: "; getline( cin, ten);
	cout<<"Nhap dia chi: "; getline( cin, diachi );
	cout<<"Nhap so DT: "; getline( cin, sodt );
}

void Nguoi::xuatN(){
	cout<<"\nTen: " << ten
		<<"\nDia chi: " << diachi
		<<"\nSo DT: " << sodt;
}

void BanDoc::nhapB(){
	Nguoi::nhapN();
	maBD = mab++;
	do{
		cout<<"\nNHap loai ban doc: \n1: SV. \n2: HVCH. \n3: GV.";
		cin>> loaiBD;
	} while( loaiBD < 1 || loaiBD > 3 );
}

void BanDoc::xuatB(){
	cout<<"Ma BD: " << maBD;
	Nguoi::xuatN();
	cout<<"\nLoai Ban Doc: ";
	if( loaiBD == 1 ) cout<<"SV.";
	if( loaiBD == 2 ) cout<<"HVCH.";
	if( loaiBD == 3 ) cout<<"GV." ;
	cout<<"\n";
}

void Sach::nhapS(){
	maS = mas++;
	cin.ignore();
	cout<<"\nNhap ten sach: "; getline( cin, tensach );
	cout<<"\nNhap ten TG: "; getline( cin, tentg );
	cout<<"\nNhap nam Xb: "; cin>> namxb;
	do{ cout<<"\nNhap CNganh: \n1: KHTN. \n2: VH_NT. \n3: DT_VT. \n4: CNTT. \n";
		cin>> loaiS;
	} while ( loaiS < 0 || loaiS > 4 );
}

void Sach::xuatS(){
	cout<<"\nMa Sach: " << maS 
	<< "\nTen Sach: " << tensach
	<<"\nTen TG: " << tentg
	<<"\nNam XB: " << namxb
	<<"\nChuyen Nghanh: ";
	if( cnghanh == 1 ) cout<<"KHTN." << endl;
	if( cnghanh == 2 ) cout<<"VH_NT." << endl;
	if( cnghanh == 3 ) cout<<"DT_VT." << endl;
	if( cnghanh == 4 ) cout<<"CNTT." << endl;
	cout<<"\n";
}

void QLMS::nhapDS( BanDoc &b ){
	system("cls");
	int ok, kt, l = 0; Sach s1[100]; fstream ifss("SACH.DAT",ios::in);
	while( ifss ) s1[l].docS( ifss ), l++; 
	cout<<"\nNhap thong tin muon sach cho ban doc \n"; b.xuatB();
	do{	cout<<"\nNhap so luong dau sach: "; cin>> sods;
	} while( sods < 0 || sods > 5 );
	for( int i = 0; i < sods; i++ ){
	do{
		ok = 0; kt = 0;
		cout<<"\nNhap ma Sach dang (100**): "; cin>> mads[i];
		for( int j = 0; j< i; j++ ) if( mads[i] == mads[j] ) ok = 1;
		for( int k = 0; k < l; k++ ) if( s1[k].getMaS() == mads[i] ) kt = 1;
		} while( kt == 0 || ok == 1 );
		
		cout<<"\nNhap so luong sach: "; cin>> sluong[i];
		while( sluong[i] < 0 || sluong[i] > 3 ) cout<<"\nNhap lai sluong: ", cin>> sluong[i];
		tongsl += sluong[i];
	}	
	for( int i = 0; i < tongsl; i++ ){
		cout<<"\nNhap trang thai quyen sach thu " << i+1 << " : ";
		cout<<"\n1: tot \n2: kha \n3: khac"; cin>> trthai[i];
		while( trthai[i] < 1 || trthai[i] > 3 ) cout<<"\nNhap lai trang thai: ", cin>> trthai[i];
	}	
}

void QLMS::ghiDS( BanDoc &b ){
	fstream ofs("QLMS.DAT", ios::app);
	ofs<< b.maBD << endl;
	ofs<< sods << endl;
	for( int i = 0; i < sods; i++ ) ofs << mads[i] << " "; ofs << endl;
	for( int i = 0; i < sods; i++ ) ofs << sluong[i] << " "; ofs << endl;
	ofs<< tongsl <<endl;
	for( int i = 0; i< tongsl; i++ ) ofs<< trthai[i] << " "; ofs<< endl;
	ofs.close();
}

void QLMS::docQ( fstream & ifs ){
	ifs>> bdi.maBD; ifs.ignore();
	ifs>> sods; ifs.ignore();
	for( int i = 0; i< sods; i++ ) ifs >> mads[i];
	for( int i = 0; i< sods; i++ ) ifs >> sluong[i];
	ifs>> tongsl;
	for( int i = 0; i< tongsl; i++ ) ifs >> trthai[i];
}

void QLMS::xuatDS( BanDoc &b ){
	cout<<"\n--------Thong tin mBan Doc--------\n";
	b.xuatB();
	cout<<"So Luong Dau Sach: " << sods;
	cout<<"\nMa sach: ";
	for( int i = 0; i < sods; i++ ){
		cout << setw(8) << mads[i];
	}
	cout<<"\nTong so: " << tongsl;
	for( int j = 0; j < tongsl; j++ ){
		cout<<"\nTrang thai quyen thu " << j+1 << " : ";
		if( trthai[j] == 1 ) cout<<"Tot.";
		if( trthai[j] == 2 ) cout<<"Kha.";
		if( trthai[j] == 3 ) cout<<"Khac.";			
	}
	cout<<"\n";
}

void sapxep(){
	int lc, nb = 0, nq = 0; QLMS q[100], tempt; BanDoc b[100]; 
	fstream ifsq( "QLMS.DAT",ios::in ); fstream ifsb( "BD.DAT", ios::in );
	while( ifsb ){	b[nb].docB( ifsb ); nb++; } nb--;
	while( !ifsq.eof() ){	q[nq].docQ( ifsq ); q[nq].bdi = b[nq];  nq++; }
	do{
		cout<<"\n----------CAC LUA CHON------------";
		cout<<"\n1: Sap xep theo ten."
			<<"\n2: Sap xep theo so luong(giam dan)."
			<<"\n0: Tro lai menu chinh."
			<<"\nBan chon ? "; cin>> lc;
			
		switch( lc ){ 
			case 1: system("cls"); for( int i = 0; i< nb; i++ )
						for( int j = i + 1; j < nb; j++ )
							if( q[i].bdi.getTen() > q[j].bdi.getTen() ){
								tempt = q[i]; q[i] = q[j]; q[j] = tempt;
							}
					for( int i = 0; i< nb; i++ ) q[i].xuatDS(q[i].bdi);
					break;
			case 2: system("cls"); for( int i = 0; i < nb; i++ )
						for( int j = 1 + i; j < nb; j++ )
							if( q[i].getTongSL() < q[j].getTongSL() ){
								tempt = q[i]; q[i] = q[j]; q[j] = tempt;
							}
						for( int i = 0; i < nb; i++ ) q[i].xuatDS( q[i].bdi );
				break;
			case 0: system("cls"); break;
			default: cout<<"\nNhap sai, hay nhap lai!";
		}
	} while( lc != 0 );
}

void timkiem(){
	int lc, nb = 0, nq = 0; QLMS q[100], tempt; BanDoc b[100]; 
	fstream ifsq( "QLMS.DAT",ios::in ); fstream ifsb( "BD.DAT", ios::in );
	while( ifsb ){	b[nb].docB( ifsb ); nb++; } nb--;
	while( !ifsq.eof() ){	q[nq].docQ( ifsq ); q[nq].bdi = b[nq];  nq++; }
	do{
		cout<<"\n----------CAC LUA CHON------------";
		cout<<"\n1: Tim kiem BD theo ten."
			<<"\n0: Tro lai menu chinh."
			<<"\nBan chon ? "; cin>> lc;
			
		switch( lc ){ 
			case 1: { string t; int ok = 0; cin.ignore();
				cout<<"\nNhap ten ban doc: "; getline( cin, t );
				for( int i = 0; i< nb; i++ )
					if( t.compare( q[i].bdi.getTen() ) == 0 ){
						q[i].xuatDS( q[i].bdi ); ok = 1;
					}
				if( ok == 0 ) cout<<"\nKhong co thong tin BD trong DS.\n";
				break;
			}
			case 0: system("cls"); break;
			default: cout<<"\nNhap lai.";
		}
	} while( lc != 0 );
}

void menu(){
	BanDoc b[100]; int nb, ns;
	Sach s[100];
	QLMS ql[100];
	fstream ofsb("BD.DAT",ios::out);
	fstream ofss("SACH.DAT",ios::out);
	fstream ofsq("QLMS.DAT",ios::out);
	int c;
	do{	
		cout<<"\n----------CAC CHUC NANG-----------"
			<<"\n1: Nhap 1 de TH y a)..."
			<<"\n2: Nhap 2 de TH y b)..."
			<<"\n3: Nhap 3 de TH y c)..."
			<<"\n4: Nhap 4 de TH y d)..."
			<<"\n5: Nhap 5 de TH y e)..."
			<<"\n0: Thoat khoi CT."
			<<"\nBan chon ? "; cin >> c;
		switch( c ){
			case 1:{ system("cls"); cout<<"\nNhap so luong Ban doc can them vao file:";
					cin>> nb;
					for( int i = 0; i< nb; i++ ){
						cout<<"\nNhap BD thu " << i+1 << " : ";
						b[i].nhapB();
						b[i].ghiB(ofsb);
					} ofsb.close(); system("cls");
					cout<<"\n--------CAC BAN DOC CO TRONG FILE--------\n";
					fstream ifsb("BD.DAT", ios::in)	;
					BanDoc *b1; if( !ifsb ) 
						cout<< "\nFIle could not be opened!", exit(1);
					while( ifsb ){
						b1 = new BanDoc;
						b1->docB( ifsb );
						if(!ifsb.eof() ) b1->xuatB();
					}	ifsb.close();		
				break;
			}
			case 2: { system("cls"); cout<<"\nNhap so luong dau sach moi: "; cin>> ns;
					for( int i = 0; i< ns; i++ ){
						cout<<"\nNhap thong tin dau sach  thu " << i+1 << " : ";
						s[i].nhapS(); s[i].ghiS( ofss );
					} ofss.close(); system("cls");
					cout<<"\n--------CAC DAU SACH CO TRONG FILE--------\n";
					fstream ifss("SACH.DAT", ios::in);
					Sach *s2; if( !ifss ) 
						cout<< "\nFIle could not be opened!", exit(1);
					while( ifss ){
						s2 = new Sach;
						s2->docS( ifss ); 
						if( !ifss.eof() ) s2->xuatS();
					} ifss.close();
				break;
			}
			case 3: system("cls"); for( int i = 0; i < nb; i++ ){
						ql[i].nhapDS(b[i]); ql[i].ghiDS(b[i]); }
					system("cls"); for( int i = 0; i< nb; i++ ) 
						ql[i].xuatDS( b[i] );
					break;
			case 4: system("cls"); sapxep(); break;
			case 5: system("cls"); timkiem(); break; 
			case 0: system("cls"); break;
			default: cout<<"\nChuc nang Khong dung! Hay nhap lai!";
		}
	} while( c != 0 );
}

int main(){
	menu();
	return 0;
} // code by Trieu Than PTIT. code chi mang tinh tham khao! //
