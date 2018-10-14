#include<iostream>
#include<vector>
using namespace std;

int ma = 0;
int masach = 0;
int i = 0;

class Nguoi {
protected:
	string hoten_ = "";
	string diachi_ = "";
	int mathedoc_ = 0;

public:
	Nguoi() {
		mathedoc_ = ma;
		ma++;
	}
	void setTen(string hoten);
	void setDiaChi(string diachi);
	string getTen();
	string getDiaChi();
	virtual void nhap();
	virtual void hienthi();
	virtual int getdanhdau(void)=0;
};

void Nguoi::nhap() {
	cin.ignore();
	cout << "Nhap ten: ";
	getline(cin, hoten_);
	cout << "Nhap dia chi: ";
	getline(cin, diachi_);
}
void Nguoi::hienthi() {
	cout << "Ma: " << mathedoc_ << endl;
	cout << "ten: " << hoten_ << endl;
	cout << "dia chi: " << diachi_ << endl;
}
void Nguoi::setTen(string hoten) {
	hoten_ = hoten;
}
void Nguoi::setDiaChi(string diachi) {
	diachi_ = diachi;
}
string Nguoi::getTen() {
	return hoten_;
}
string Nguoi::getDiaChi() {
	return diachi_;
}

class sinhvien: public Nguoi {
private:
	string namhoc_ = "";
	string lophoc_ = "";
	int danhdau = 1;
public:
	sinhvien() {
	}
	int getdanhdau();
	void nhap();
	void hienthi();
	friend class BangQL;
};
int sinhvien::getdanhdau() {
	return danhdau;
}
void sinhvien::nhap() {
	Nguoi::nhap();
	cout << "Nam hoc: ";
	getline(cin, namhoc_);
	cout << "Lop hoc: ";
	getline(cin, lophoc_);
}
void sinhvien::hienthi() {
	Nguoi::hienthi();
	cout << "Loai Ban Doc: Sinh Vien" << endl;
	cout << "nam hoc: " << namhoc_ << endl;
	cout << "lop hoc: " << lophoc_ << endl;
}
class hocvien: public Nguoi {
private:
	string congtac_ = "";
	int danhdau = 2;
public:
	hocvien() {
	}
	int getdanhdau();
	void nhap();
	void hienthi();
	friend class BangQL;
};
int hocvien::getdanhdau() {
	return danhdau;
}
void hocvien::nhap() {
	Nguoi::nhap();
	cout << "Nhap Don vi Cong tac: ";
	getline(cin, congtac_);
}
void hocvien::hienthi() {
	Nguoi::hienthi();
	cout << "Loai Ban Doc: Hoc Vien Cao Hoc" << endl;
	cout << "Cong tac tai: " << congtac_ << endl;
}
class giaovien: public Nguoi {
private:
	string chucvu_ = "";
	string khoa_ = "";
	int danhdau = 3;
public:
	giaovien() {
	}
	int getdanhdau();
	void nhap();
	void hienthi();
	friend class BangQL;
};
int giaovien::getdanhdau() {
	return danhdau;
}
void giaovien::nhap() {
	Nguoi::nhap();
	cout << "Nhap Chuc Vu: ";
	getline(cin, chucvu_);
	cout << "Nhap Khoa Giang Day: ";
	getline(cin, khoa_);
}
void giaovien::hienthi() {
	Nguoi::hienthi();
	cout << "Loai Ban Doc: Giao Vien" << endl;
	cout << "Chuc Vu: " << chucvu_ << endl;
	cout << "Khoa Giang Day: " << khoa_ << endl;
}
class Sach {
private:
	int masach_ = 0;
	string tensach_ = "";
	string tacgia_ = "";
	string chuyennganh_ = "";
	string namxb_ = "";
public:
	Sach() {
	}
	void setma(int);
	void nhap();
	void hienthi();
};

void Sach::setma(int p) {
	this->masach_ = p;
};

void Sach::nhap() {
	cin.ignore();
	cout << "Nhap Ten Sach: ";
	getline(cin, tensach_);
	cout << "Nhap Ten Tac Gia: ";
	getline(cin, tacgia_);
	cout << "Nhap Nam Xuat Ban: ";
	getline(cin, namxb_);
	cout << "Chon Chuyen Nganh: " << endl;
	cout << "\t1.Khoa Hoc Tu Nhien" << endl;
	cout << "\t2.Van Hoc - Nghe Thuat" << endl;
	cout << "\t3.Dien Tu Vien Thong" << endl;
	cout << "\t4.Cong Nghe Thong Tin" << endl;
	cout << "\tChon: ";
	int f;
	cin >> f;
	cin.ignore();
	switch (f) {
	case 1: {
		chuyennganh_ = "Khoa Hoc Tu Nhien";
		break;
	}
	case 2: {
		chuyennganh_ = "Van Hoc - Nghe Thuat";
		break;
	}
	case 3: {
		chuyennganh_ = "Dien Tu Vien Thong";
		break;
	}
	case 4: {
		chuyennganh_ = "Cong Nghe Thong Tin";
		break;
	}
	}
}
void Sach::hienthi() {
	cout << "Ma Sach: " << masach_ << endl;
	cout << "Ten Sach: " << tensach_ << endl;
	cout << "Ten Tac Gia: " << tacgia_ << endl;
	cout << "Nam Xuat Ban: " << namxb_ << endl;
	cout << "Chuyen Nganh: " << chuyennganh_ << endl;
}

///////////
Nguoi *a[1000];
vector<Sach> danhsach;
//////////
void khoitaodanhsachbandoc() {
	int n = 1;
	while (1) {
		cout << "=====Nhap thong tin ban doc=====" << endl;
		cout << "Chon loai ban doc: " << endl;
		cout << "\t1.Sinh Vien" << endl;
		cout << "\t2.Hoc Vien Cao Hoc" << endl;
		cout << "\t3.Giao Vien" << endl;
		cout << "\tChon: ";
		cin >> n;
		switch (n) {
		case 1: {
			cout << "==Nhap thong tin Sinh Vien==" << endl;
			a[i] = new sinhvien();
			a[i]->nhap();
			i++;
			break;
		}
		case 2: {
			cout << "==Nhap thong tin Hoc Vien==" << endl;
			a[i] = new hocvien();
			a[i]->nhap();
			i++;
			break;
		}
		case 3: {
			cout << "==Nhap thong tin Giao Vien==" << endl;
			a[i] = new giaovien();
			a[i]->nhap();
			i++;
			break;
		}
		}

		cout
				<< "Da cap nhat thong tin thanh cong. Bam 1 de tiep tuc, Bam 0 de ket thuc: ";
		cin >> n;
		if (n == 0)
			break;
	}
}
void hienthibandoc() {
	int k = 0;
	cout << "\n\n" << endl;
	cout << "========DANH SACH BAN DOC========" << endl;
	while (k < i) {
		cout << "=================================" << endl;
		a[k]->hienthi();
		k++;
	}
	cout << "\n" << endl;
}
void khoitaodanhsachsach() {
	int n = 1;
	while (1) {
		cout << "=====Nhap thong tin sach=====" << endl;
		Sach temp;
		temp.nhap();
		danhsach.push_back(temp);
		cout
				<< "Da cap nhat thong tin thanh cong. Bam 1 de tiep tuc, Bam 0 de ket thuc: ";
		cin >> n;
		if (n == 0)
			break;
	}
}
void hienthisach() {
	cout << "\n\n" << endl;
	cout << "========DANH SACH CAC CUON SACH TRONG THU VIEN========" << endl;
	for (int j = 0; j < danhsach.size(); j++) {
		danhsach.at(j).setma(j);
	}
	for (int j = 0; j < danhsach.size(); j++) {
		cout << "=================================" << endl;
		danhsach.at(j).hienthi();
	}
	cout << "\n" << endl;
}
class BangQL {
private:
	Nguoi *bandoc;
	Sach sach[10]; //?
	int socuon = 0;
public:
	BangQL() {
	}
	void muonsach(int);
	void hienthi();
};
void BangQL::muonsach(int n) {
	int maa;
	int j = 0;
	int y;
	cout << "Ban Doc: " << a[n]->getTen();
	bandoc = a[n];
	while (1) {
		cout << endl;
		hienthisach();
		cout << "Nhap Ma Sach can muon: ";
		cin >> maa;
		sach[socuon] = danhsach[maa];
		socuon++;
		if (a[n]->getdanhdau() == 1) {
			if (socuon == 3) {
				cout << "==Sinh vien chi duoc phep muon toi da 3 cuon sach!=="
						<< endl;
				cout << "\n" << endl;
				break;
			}
		}
		if (a[n]->getdanhdau() == 2) {
			if (socuon == 5) {
				cout << "==HVCH chi duoc phep muon toi da 5 cuon sach!=="
						<< endl;
				cout << "\n" << endl;
				break;
			}
		}
		if (a[n]->getdanhdau() == 3) {
			if (socuon == 7) {
				cout << "==Giao Vien chi duoc phep muon toi da 7 cuon sach!=="
						<< endl;
				cout << "\n" << endl;
				break;
			}
		}
		cout << "Muon sach thanh cong bam 1 de muon tiep, bam 0 ket thuc :";
		cin >> y;
		if (y == 0)
			break;
	}

}
void BangQL::hienthi() {
	cout << endl;
	cout << "======================";
	bandoc->hienthi();
	cout << "======================";
	cout << "So sach da muon:" << socuon << endl;
	cout << "Danh Sach sach muon: " << endl;
	for (int j = 0; j < socuon; j++) {
		cout << "======================";
		sach[j].hienthi();
	}
}
BangQL bql[1000];
void bangquanly() {
	int n;
	hienthibandoc();
	cout << endl;
	cout << "Nhap Ma So ban doc: ";
	cin >> n;
	bql[n].muonsach(n);
}
void timkiem() {
	cout << endl;
	string temp;
	cin.ignore();
	cout << "Nhap vao ten ban doc:";
	getline(cin, temp);
	for (int j = 0; j < i; j++) {
		if (temp == a[j]->getTen()) {
			bql[j].hienthi();
		}
	}
}
int main() {
	int yolo;
	while (1) {
		cout << "======CHUONG TRINH QUAN LY THU VIEN TOI DA 1000 BAN DOC======"
				<< endl;
		cout << "1.Khoi tao danh sach ban doc" << endl;
		cout << "2.Khoi tao danh sach sach" << endl;
		cout << "3.Quan ly muon sach" << endl;
		cout << "4.Tim kiem ban doc" << endl;
		cout << "Chon: ";
		cin >> yolo;
		if (yolo == 0)
			break;
		switch (yolo) {
		case 1: {
			khoitaodanhsachbandoc();
			hienthibandoc();
			break;
		}
		case 2: {
			khoitaodanhsachsach();
			hienthisach();
			break;
		}
		case 3: {
			bangquanly();
			break;
		}
		case 4: {
			timkiem();
			break;
		}
		}
	}
	return 0;
}
