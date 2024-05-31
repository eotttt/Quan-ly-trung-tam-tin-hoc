#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class HocVien {
private:
    struct ThongTinHocVien {
        char maHocVien[20];
        char tenHocVien[50];
        char ngaySinh[20];
        char gioiTinh[10];
        char email[50];
        char soDienThoai[20];
    };

    ThongTinHocVien danhSachHocVien[100];
    int soLuongHocVien;

public:
    HocVien() : soLuongHocVien(0) {}

    // Constructor
    HocVien(const char* ma, const char* ten, const char* ngaySinh, const char* gioiTinh, const char* email, const char* soDienThoai) : soLuongHocVien(0) {
    }

    // Getter methods
    const char* GetMaHocVien(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].maHocVien;
        else
            return "";
    }

    const char* GetTenHocVien(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].tenHocVien;
        else
            return "";
    }

    const char* GetNgaySinh(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].ngaySinh;
        else
            return "";
    }

    const char* GetGioiTinh(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].gioiTinh;
        else
            return "";
    }

    const char* GetEmail(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].email;
        else
            return "";
    }

    const char* GetSoDienThoai(int index) const {
        if (index >= 0 && index < soLuongHocVien)
            return danhSachHocVien[index].soDienThoai;
        else
            return "";
    }

    // Setter methods
    void SetMaHocVien(int index, const char* ma) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].maHocVien, ma);
    }

    void SetTenHocVien(int index, const char* ten) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].tenHocVien, ten);
    }

    void SetNgaySinh(int index, const char* ngaySinh) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].ngaySinh, ngaySinh);
    }

    void SetGioiTinh(int index, const char* gioiTinh) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].gioiTinh, gioiTinh);
    }

    void SetEmail(int index, const char* email) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].email, email);
    }

    void SetSoDienThoai(int index, const char* soDienThoai) {
        if (index >= 0 && index < soLuongHocVien)
            strcpy(danhSachHocVien[index].soDienThoai, soDienThoai);
    }

    // Method to add a new student
    void ThemHocVien() {
        if (soLuongHocVien < 100) {
            cout << "Nhap ma hoc vien: ";
            cin.ignore();
            cin.getline(danhSachHocVien[soLuongHocVien].maHocVien, 20);

            cout << "Nhap ten hoc vien: ";
            cin.getline(danhSachHocVien[soLuongHocVien].tenHocVien, 50);

            cout << "Nhap ngay sinh: ";
            cin.getline(danhSachHocVien[soLuongHocVien].ngaySinh, 20);

            cout << "Nhap gioi tinh: ";
            cin.getline(danhSachHocVien[soLuongHocVien].gioiTinh, 10);

            cout << "Nhap email: ";
            cin.getline(danhSachHocVien[soLuongHocVien].email, 50);

            cout << "Nhap so dien thoai: ";
            cin.getline(danhSachHocVien[soLuongHocVien].soDienThoai, 20);

            soLuongHocVien++;
        } else {
            cout << "Danh sach da day, khong the them hoc vien moi." << endl;
        }
    }

    // Method to update student information
    void SuaHocVien() {
        int index;
        cout << "Nhap vi tri hoc vien can sua: ";
        cin >> index;

        if (index >= 0 && index < soLuongHocVien) {
            cout << "Nhap ma hoc vien: ";
            cin.ignore();
            cin.getline(danhSachHocVien[index].maHocVien, 20);

            cout << "Nhap ten hoc vien: ";
            cin.getline(danhSachHocVien[index].tenHocVien, 50);

            cout << "Nhap ngay sinh: ";
            cin.getline(danhSachHocVien[index].ngaySinh, 20);

            cout << "Nhap gioi tinh: ";
            cin.getline(danhSachHocVien[index].gioiTinh, 10);

            cout << "Nhap email: ";
            cin.getline(danhSachHocVien[index].email, 50);

            cout << "Nhap so dien thoai: ";
            cin.getline(danhSachHocVien[index].soDienThoai, 20);
        } else {
            cout << "Khong ton tai hoc vien tai vi tri " << index << endl;
        }
    }
    // Method to remove a student
    void XoaHocVien(const char* maHocVien) {
        int viTri = -1;
        for (int i = 0; i < soLuongHocVien; ++i) {
            if (strcmp(danhSachHocVien[i].maHocVien, maHocVien) == 0) {
                viTri = i;
                break;
            }
        }
        if (viTri != -1) {
            for (int i = viTri; i < soLuongHocVien - 1; ++i) {
                danhSachHocVien[i] = danhSachHocVien[i + 1];
            }
            soLuongHocVien--;
            cout << "Da xoa hoc vien co ma " << maHocVien << endl;
        } else {
            cout << "Khong tim thay hoc vien co ma " << maHocVien << endl;
        }
    }

    void DocDanhSachHocVien(const char* tenTep) {
        ifstream file(tenTep);
        if (!file) {
            cerr << "Khong mo duoc file." << endl;
            return;
        }
        soLuongHocVien = 0;
        while (soLuongHocVien < 100 && file.getline(danhSachHocVien[soLuongHocVien].maHocVien, 20, ',') &&
                                            file.getline(danhSachHocVien[soLuongHocVien].tenHocVien, 50, ',') &&
                                            file.getline(danhSachHocVien[soLuongHocVien].ngaySinh, 20, ',') &&
                                            file.getline(danhSachHocVien[soLuongHocVien].gioiTinh, 10, ',') &&
                                            file.getline(danhSachHocVien[soLuongHocVien].email, 50, ',') &&
                                            file.getline(danhSachHocVien[soLuongHocVien].soDienThoai, 20)) {
            soLuongHocVien++;
        }
        file.close();
    }
    void InDanhSachHocVien() {
        for (int i = 0; i < soLuongHocVien; ++i) {
            cout << "Ma hoc vien: " << danhSachHocVien[i].maHocVien << endl;
            cout << "Ten hoc vien: " << danhSachHocVien[i].tenHocVien << endl;
            cout << "Ngay sinh: " << danhSachHocVien[i].ngaySinh << endl;
            cout << "Gioi tinh: " << danhSachHocVien[i].gioiTinh << endl;
            cout << "Email: " << danhSachHocVien[i].email << endl;
            cout << "So dien thoai: " << danhSachHocVien[i].soDienThoai << endl;
            cout << "--------------------------" << endl;
        }
    }
};
class KhoaHoc {
private:
    struct ThongTinKhoaHoc {
        char maKhoaHoc[10];
        char tenKhoaHoc[100];
        char moTa[200];
        char ngayBatDau[20];
        char ngayKetThuc[20];
    };

    ThongTinKhoaHoc danhSachKhoaHoc[100];
    int soLuongKhoaHoc;

public:
    KhoaHoc() : soLuongKhoaHoc(0) {}
    const char* GetMaKhoaHoc(int index) const {
        if (index >= 0 && index < soLuongKhoaHoc)
            return danhSachKhoaHoc[index].maKhoaHoc;
        else
            return "";
    }

    const char* GetTenKhoaHoc(int index) const {
        if (index >= 0 && index < soLuongKhoaHoc)
            return danhSachKhoaHoc[index].tenKhoaHoc;
        else
            return "";
    }

    const char* GetMoTa(int index) const {
        if (index >= 0 && index < soLuongKhoaHoc)
            return danhSachKhoaHoc[index].moTa;
        else
            return "";
    }

    const char* GetNgayBatDau(int index) const {
        if (index >= 0 && index < soLuongKhoaHoc)
            return danhSachKhoaHoc[index].ngayBatDau;
        else
            return "";
    }

    const char* GetNgayKetThuc(int index) const {
        if (index >= 0 && index < soLuongKhoaHoc)
            return danhSachKhoaHoc[index].ngayKetThuc;
        else
            return "";
    }
    void SetMaKhoaHoc(int index, const char* maKhoaHoc) {
        if (index >= 0 && index < soLuongKhoaHoc)
            strcpy(danhSachKhoaHoc[index].maKhoaHoc, maKhoaHoc);
    }

    void SetTenKhoaHoc(int index, const char* tenKhoaHoc) {
        if (index >= 0 && index < soLuongKhoaHoc)
            strcpy(danhSachKhoaHoc[index].tenKhoaHoc, tenKhoaHoc);
    }

    void SetMoTa(int index, const char* moTa) {
        if (index >= 0 && index < soLuongKhoaHoc)
            strcpy(danhSachKhoaHoc[index].moTa, moTa);
    }

    void SetNgayBatDau(int index, const char* ngayBatDau) {
        if (index >= 0 && index < soLuongKhoaHoc)
            strcpy(danhSachKhoaHoc[index].ngayBatDau, ngayBatDau);
    }

    void SetNgayKetThuc(int index, const char* ngayKetThuc) {
        if (index >= 0 && index < soLuongKhoaHoc)
            strcpy(danhSachKhoaHoc[index].ngayKetThuc, ngayKetThuc);
    }
    void ThemKhoaHocTuBanPhim() {
        if (soLuongKhoaHoc < 100) {
            cout << "Nhap ma khoa hoc: ";
            cin.ignore();
            cin.getline(danhSachKhoaHoc[soLuongKhoaHoc].maKhoaHoc, 10);
            
            cout << "Nhap ten khoa hoc: ";
            cin.getline(danhSachKhoaHoc[soLuongKhoaHoc].tenKhoaHoc, 100);

            cout << "Nhap mo ta: ";
            cin.getline(danhSachKhoaHoc[soLuongKhoaHoc].moTa, 200);

            cout << "Nhap ngay bat dau: ";
            cin.getline(danhSachKhoaHoc[soLuongKhoaHoc].ngayBatDau, 20);

            cout << "Nhap ngay ket thuc: ";
            cin.getline(danhSachKhoaHoc[soLuongKhoaHoc].ngayKetThuc, 20);

            soLuongKhoaHoc++;
        } else {
            cout << "Danh sach da day, khong the them khoa hoc moi." << endl;
        }
    }

    void XoaKhoaHoc() {
        char maKhoaHoc[10];
        cout << "Nhap ma khoa hoc can xoa: ";
        cin.ignore();
        cin.getline(maKhoaHoc, 10);

        for (int i = 0; i < soLuongKhoaHoc; ++i) {
            if (strcmp(danhSachKhoaHoc[i].maKhoaHoc, maKhoaHoc) == 0) {
                for (int j = i; j < soLuongKhoaHoc - 1; ++j) {
                    danhSachKhoaHoc[j] = danhSachKhoaHoc[j + 1];
                }
                soLuongKhoaHoc--;
                cout << "Da xoa khoa hoc co ma " << maKhoaHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay khoa hoc co ma " << maKhoaHoc << endl;
    }

    void SuaKhoaHoc() {
        char maKhoaHoc[10];
        cout << "Nhap ma khoa hoc can sua: ";
        cin.ignore();
        cin.getline(maKhoaHoc, 10);

        for (int i = 0; i < soLuongKhoaHoc; ++i) {
            if (strcmp(danhSachKhoaHoc[i].maKhoaHoc, maKhoaHoc) == 0) {
                cout << "Nhap ten khoa hoc moi: ";
                cin.getline(danhSachKhoaHoc[i].tenKhoaHoc, 100);

                cout << "Nhap mo ta moi: ";
                cin.getline(danhSachKhoaHoc[i].moTa, 200);

                cout << "Nhap ngay bat dau moi: ";
                cin.getline(danhSachKhoaHoc[i].ngayBatDau, 20);

                cout << "Nhap ngay ket thuc moi: ";
                cin.getline(danhSachKhoaHoc[i].ngayKetThuc, 20);

                cout << "Da sua khoa hoc co ma " << maKhoaHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay khoa hoc co ma " << maKhoaHoc << endl;
    }
    void DocDanhSachKhoaHoc(const char* tenTep) {
        ifstream file(tenTep);
        if (!file) {
            cerr << "Khong mo duoc file." << endl;
            return;
        }
        soLuongKhoaHoc = 0;
        char maKhoaHoc[10];
        char tenKhoaHoc[100];
        char moTa[200];
        char ngayBatDau[20];
        char ngayKetThuc[20];

        while (soLuongKhoaHoc < 100 && file.getline(maKhoaHoc, 10, ',') &&
                                        file.getline(tenKhoaHoc, 100, ',') &&
                                        file.getline(moTa, 200, ',') &&
                                        file.getline(ngayBatDau, 20, ',') &&
                                        file.getline(ngayKetThuc, 20)) {
            strcpy(danhSachKhoaHoc[soLuongKhoaHoc].maKhoaHoc, maKhoaHoc);
            strcpy(danhSachKhoaHoc[soLuongKhoaHoc].tenKhoaHoc, tenKhoaHoc);
            strcpy(danhSachKhoaHoc[soLuongKhoaHoc].moTa, moTa);
            strcpy(danhSachKhoaHoc[soLuongKhoaHoc].ngayBatDau, ngayBatDau);
            strcpy(danhSachKhoaHoc[soLuongKhoaHoc].ngayKetThuc, ngayKetThuc);
            soLuongKhoaHoc++;
        }
        file.close();
    }
    void InDanhSachKhoaHoc() {
        for (int i = 0; i < soLuongKhoaHoc; ++i) {
            cout << "Ma khoa hoc: " << danhSachKhoaHoc[i].maKhoaHoc << endl;
            cout << "Ten khoa hoc: " << danhSachKhoaHoc[i].tenKhoaHoc << endl;
            cout << "Mo ta: " << danhSachKhoaHoc[i].moTa << endl;
            cout << "Ngay bat dau: " << danhSachKhoaHoc[i].ngayBatDau << endl;
            cout << "Ngay ket thuc: " << danhSachKhoaHoc[i].ngayKetThuc << endl;
            cout << "--------------------------" << endl;
        }
    }
};
class GiangVien {
private:
    struct ThongTinGiangVien {
        char maGiangVien[10];
        char tenGiangVien[100];
        char trinhDo[100];
        char email[50];
        char soDienThoai[20];
    };

    ThongTinGiangVien danhSachGiangVien[100];
    int soLuongGiangVien;

public:
    GiangVien() : soLuongGiangVien(0) {}
    const char* GetMaGiangVien(int index) const {
        if (index >= 0 && index < soLuongGiangVien)
            return danhSachGiangVien[index].maGiangVien;
        else
            return "";
    }

    const char* GetTenGiangVien(int index) const {
        if (index >= 0 && index < soLuongGiangVien)
            return danhSachGiangVien[index].tenGiangVien;
        else
            return "";
    }

    const char* GetTrinhDo(int index) const {
        if (index >= 0 && index < soLuongGiangVien)
            return danhSachGiangVien[index].trinhDo;
        else
            return "";
    }

    const char* GetEmail(int index) const {
        if (index >= 0 && index < soLuongGiangVien)
            return danhSachGiangVien[index].email;
        else
            return "";
    }

    const char* GetSoDienThoai(int index) const {
        if (index >= 0 && index < soLuongGiangVien)
            return danhSachGiangVien[index].soDienThoai;
        else
            return "";
    }
    void SetMaGiangVien(int index, const char* maGiangVien) {
        if (index >= 0 && index < soLuongGiangVien)
            strcpy(danhSachGiangVien[index].maGiangVien, maGiangVien);
    }

    void SetTenGiangVien(int index, const char* tenGiangVien) {
        if (index >= 0 && index < soLuongGiangVien)
            strcpy(danhSachGiangVien[index].tenGiangVien, tenGiangVien);
    }

    void SetTrinhDo(int index, const char* trinhDo) {
        if (index >= 0 && index < soLuongGiangVien)
            strcpy(danhSachGiangVien[index].trinhDo, trinhDo);
    }

    void SetEmail(int index, const char* email) {
        if (index >= 0 && index < soLuongGiangVien)
            strcpy(danhSachGiangVien[index].email, email);
    }

    void SetSoDienThoai(int index, const char* soDienThoai) {
        if (index >= 0 && index < soLuongGiangVien)
            strcpy(danhSachGiangVien[index].soDienThoai, soDienThoai);
    }
    void ThemGiangVien() {
        if (soLuongGiangVien < 100) {
            cout << "Nhap ma giang vien: ";
            cin >> danhSachGiangVien[soLuongGiangVien].maGiangVien;
            cout << "Nhap ten giang vien: ";
            cin.ignore();
            cin.getline(danhSachGiangVien[soLuongGiangVien].tenGiangVien, 100);
            cout << "Nhap trinh do: ";
            cin.getline(danhSachGiangVien[soLuongGiangVien].trinhDo, 100);
            cout << "Nhap email: ";
            cin.getline(danhSachGiangVien[soLuongGiangVien].email, 50);
            cout << "Nhap so dien thoai: ";
            cin.getline(danhSachGiangVien[soLuongGiangVien].soDienThoai, 20);
            soLuongGiangVien++;
        } else {
            cout << "Danh sach da day, khong the them giang vien moi." << endl;
        }
    }
    void XoaGiangVien(int index) {
        if (index >= 0 && index < soLuongGiangVien) {
            for (int i = index; i < soLuongGiangVien - 1; ++i) {
                danhSachGiangVien[i] = danhSachGiangVien[i + 1];
            }
            soLuongGiangVien--;
        } else {
            cout << "Khong ton tai giang vien tai vi tri " << index << endl;
        }
    }
    void CapNhatThongTinGiangVien(int index) {
        if (index >= 0 && index < soLuongGiangVien) {
            cout << "Nhap ma giang vien: ";
            cin >> danhSachGiangVien[index].maGiangVien;
            cout << "Nhap ten giang vien: ";
            cin.ignore();
            cin.getline(danhSachGiangVien[index].tenGiangVien, 100);
            cout << "Nhap trinh do: ";
            cin.getline(danhSachGiangVien[index].trinhDo, 100);
            cout << "Nhap email: ";
            cin.getline(danhSachGiangVien[index].email, 50);
            cout << "Nhap so dien thoai: ";
            cin.getline(danhSachGiangVien[index].soDienThoai, 20);
        } else {
            cout << "Khong ton tai giang vien tai vi tri " << index << endl;
        }
    }
    void DocDanhSachGiangVien(const char* tenTep) {
        ifstream file(tenTep);
        if (!file) {
            cerr << "Khong mo duoc file." << endl;
            return;
        }
        soLuongGiangVien = 0;
        char maGiangVien[10];
        char tenGiangVien[100];
        char trinhDo[100];
        char email[50];
        char soDienThoai[20];

        while (soLuongGiangVien < 100 && file.getline(maGiangVien, 10, ',') &&
                                        file.getline(tenGiangVien, 100, ',') &&
                                        file.getline(trinhDo, 100, ',') &&
                                        file.getline(email, 50, ',') &&
                                        file.getline(soDienThoai, 20)) {
            strcpy(danhSachGiangVien[soLuongGiangVien].maGiangVien, maGiangVien);
            strcpy(danhSachGiangVien[soLuongGiangVien].tenGiangVien, tenGiangVien);
            strcpy(danhSachGiangVien[soLuongGiangVien].trinhDo, trinhDo);
            strcpy(danhSachGiangVien[soLuongGiangVien].email, email);
            strcpy(danhSachGiangVien[soLuongGiangVien].soDienThoai, soDienThoai);
            soLuongGiangVien++;
        }
        file.close();
    }
    void InDanhSachGiangVien() {
        for (int i = 0; i < soLuongGiangVien; ++i) {
            cout << "Ma giang vien: " << danhSachGiangVien[i].maGiangVien << endl;
            cout << "Ten giang vien: " << danhSachGiangVien[i].tenGiangVien << endl;
            cout << "Trinh do: " << danhSachGiangVien[i].trinhDo << endl;
            cout << "Email: " << danhSachGiangVien[i].email << endl;
            cout << "So dien thoai: " << danhSachGiangVien[i].soDienThoai << endl;
            cout << "--------------------------" << endl;
        }
    }
};
class LichHoc {
private:
    struct ThongTinLichHoc {
        char maLichHoc[10];
        char maKhoaHoc[10];
        char maPhongHoc[10];
        char ngay[11];
        char thoiGianBatDau[6];
        char thoiGianKetThuc[6];
    };

    ThongTinLichHoc danhSachLichHoc[100];
    int soLuongLichHoc;
public:
    LichHoc() : soLuongLichHoc(0) {}

    const char* GetMaLichHoc(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].maLichHoc;
        else
            return "";
    }

    const char* GetMaKhoaHoc(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].maKhoaHoc;
        else
            return "";
    }

    const char* GetMaPhongHoc(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].maPhongHoc;
        else
            return "";
    }

    const char* GetNgay(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].ngay;
        else
            return "";
    }

    const char* GetThoiGianBatDau(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].thoiGianBatDau;
        else
            return "";
    }

    const char* GetThoiGianKetThuc(int index) const {
        if (index >= 0 && index < soLuongLichHoc)
            return danhSachLichHoc[index].thoiGianKetThuc;
        else
            return "";
    }

    void SetMaLichHoc(int index, const char* maLichHoc) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].maLichHoc, maLichHoc);
    }

    void SetMaKhoaHoc(int index, const char* maKhoaHoc) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].maKhoaHoc, maKhoaHoc);
    }

    void SetMaPhongHoc(int index, const char* maPhongHoc) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].maPhongHoc, maPhongHoc);
    }

    void SetNgay(int index, const char* ngay) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].ngay, ngay);
    }

    void SetThoiGianBatDau(int index, const char* thoiGianBatDau) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].thoiGianBatDau, thoiGianBatDau);
    }

    void SetThoiGianKetThuc(int index, const char* thoiGianKetThuc) {
        if (index >= 0 && index < soLuongLichHoc)
            strcpy(danhSachLichHoc[index].thoiGianKetThuc, thoiGianKetThuc);
    }

    void ThemLichHocTuBanPhim() {
        if (soLuongLichHoc < 100) {
            cout << "Nhap ma lich hoc: ";
            cin.ignore();
            cin.getline(danhSachLichHoc[soLuongLichHoc].maLichHoc, 10);
            
            cout << "Nhap ma khoa hoc: ";
            cin.getline(danhSachLichHoc[soLuongLichHoc].maKhoaHoc, 10);

            cout << "Nhap ma phong hoc: ";
            cin.getline(danhSachLichHoc[soLuongLichHoc].maPhongHoc, 10);

            cout << "Nhap ngay (yyyy-mm-dd): ";
            cin.getline(danhSachLichHoc[soLuongLichHoc].ngay, 11);

            cout << "Nhap thoi gian bat dau (hh:mm): ";
            cin.getline(danhSachLichHoc[soLuongLichHoc].thoiGianBatDau, 6);

            cout << "Nhap thoi gian ket thuc (hh:mm): ";
            cin.getline(danhSachLichHoc[soLuongLichHoc].thoiGianKetThuc, 6);

            soLuongLichHoc++;
        } else {
            cout << "Danh sach da day, khong the them lich hoc moi." << endl;
        }
    }

    void XoaLichHoc() {
        char maLichHoc[10];
        cout << "Nhap ma lich hoc can xoa: ";
        cin.ignore();
        cin.getline(maLichHoc, 10);

        for (int i = 0; i < soLuongLichHoc; ++i) {
            if (strcmp(danhSachLichHoc[i].maLichHoc, maLichHoc) == 0) {
                for (int j = i; j < soLuongLichHoc - 1; ++j) {
                    danhSachLichHoc[j] = danhSachLichHoc[j + 1];
                }
                soLuongLichHoc--;
                cout << "Da xoa lich hoc co ma " << maLichHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay lich hoc co ma " << maLichHoc << endl;
    }

    void SuaLichHoc() {
        char maLichHoc[10];
        cout << "Nhap ma lich hoc can sua: ";
        cin.ignore();
        cin.getline(maLichHoc, 10);

        for (int i = 0; i < soLuongLichHoc; ++i) {
            if (strcmp(danhSachLichHoc[i].maLichHoc, maLichHoc) == 0) {
                cout << "Nhap ma khoa hoc moi: ";
                cin.getline(danhSachLichHoc[i].maKhoaHoc, 10);

                cout << "Nhap ma phong hoc moi: ";
                cin.getline(danhSachLichHoc[i].maPhongHoc, 10);

                cout << "Nhap ngay moi (yyyy-mm-dd): ";
                cin.getline(danhSachLichHoc[i].ngay, 11);

                cout << "Nhap thoi gian bat dau moi (hh:mm): ";
                cin.getline(danhSachLichHoc[i].thoiGianBatDau, 6);

                cout << "Nhap thoi gian ket thuc moi (hh:mm): ";
                cin.getline(danhSachLichHoc[i].thoiGianKetThuc, 6);

                cout << "Da sua lich hoc co ma " << maLichHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay lich hoc co ma " << maLichHoc << endl;
    }

    void DocDanhSachLichHoc(const char* tenTep) {
        ifstream file(tenTep);
        if (!file) {
            cerr << "Khong mo duoc file." << endl;
            return;
        }
        soLuongLichHoc = 0;
        char maLichHoc[10];
        char maKhoaHoc[10];
        char maPhongHoc[10];
        char ngay[11];
        char thoiGianBatDau[6];
        char thoiGianKetThuc[6];

        while (soLuongLichHoc < 100 && 
               file.getline(maLichHoc, 10, ',') &&
               file.getline(maKhoaHoc, 10, ',') &&
               file.getline(maPhongHoc, 10, ',') &&
               file.getline(ngay, 11, ',') &&
               file.getline(thoiGianBatDau, 6, ',') &&
               file.getline(thoiGianKetThuc, 6)) {
            strcpy(danhSachLichHoc[soLuongLichHoc].maLichHoc, maLichHoc);
            strcpy(danhSachLichHoc[soLuongLichHoc].maKhoaHoc, maKhoaHoc);
            strcpy(danhSachLichHoc[soLuongLichHoc].maPhongHoc, maPhongHoc);
            strcpy(danhSachLichHoc[soLuongLichHoc].ngay, ngay);
            strcpy(danhSachLichHoc[soLuongLichHoc].thoiGianBatDau, thoiGianBatDau);
            strcpy(danhSachLichHoc[soLuongLichHoc].thoiGianKetThuc, thoiGianKetThuc);
            soLuongLichHoc++;
        }
        file.close();
    }

    void InDanhSachLichHoc() {
        for (int i = 0; i < soLuongLichHoc; ++i) {
            cout << "Ma lich hoc: " << danhSachLichHoc[i].maLichHoc << endl;
            cout << "Ma khoa hoc: " << danhSachLichHoc[i].maKhoaHoc << endl;
            cout << "Ma phong hoc: " << danhSachLichHoc[i].maPhongHoc << endl;
            cout << "Ngay: " << danhSachLichHoc[i].ngay << endl;
            cout << "Thoi gian bat dau: " << danhSachLichHoc[i].thoiGianBatDau << endl;
            cout << "Thoi gian ket thuc: " << danhSachLichHoc[i].thoiGianKetThuc << endl;
            cout << "--------------------------" << endl;
        }
    }
};
class PhongHoc {
private:
    struct ThongTinPhongHoc {
        char maPhongHoc[10];
        char soPhong[10];
        int sucChua;
    };

    ThongTinPhongHoc danhSachPhongHoc[100];
    int soLuongPhongHoc;

public:
    PhongHoc() : soLuongPhongHoc(0) {}

    const char* GetMaPhongHoc(int index) const {
        if (index >= 0 && index < soLuongPhongHoc)
            return danhSachPhongHoc[index].maPhongHoc;
        else
            return "";
    }

    const char* GetSoPhong(int index) const {
        if (index >= 0 && index < soLuongPhongHoc)
            return danhSachPhongHoc[index].soPhong;
        else
            return "";
    }

    int GetSucChua(int index) const {
        if (index >= 0 && index < soLuongPhongHoc)
            return danhSachPhongHoc[index].sucChua;
        else
            return -1;
    }

    void SetMaPhongHoc(int index, const char* maPhongHoc) {
        if (index >= 0 && index < soLuongPhongHoc)
            strcpy(danhSachPhongHoc[index].maPhongHoc, maPhongHoc);
    }

    void SetSoPhong(int index, const char* soPhong) {
        if (index >= 0 && index < soLuongPhongHoc)
            strcpy(danhSachPhongHoc[index].soPhong, soPhong);
    }

    void SetSucChua(int index, int sucChua) {
        if (index >= 0 && index < soLuongPhongHoc)
            danhSachPhongHoc[index].sucChua = sucChua;
    }

    void ThemPhongHocTuBanPhim() {
        if (soLuongPhongHoc < 100) {
            cout << "Nhap ma phong hoc: ";
            cin.ignore();
            cin.getline(danhSachPhongHoc[soLuongPhongHoc].maPhongHoc, 10);
            
            cout << "Nhap so phong: ";
            cin.getline(danhSachPhongHoc[soLuongPhongHoc].soPhong, 10);

            cout << "Nhap suc chua: ";
            cin >> danhSachPhongHoc[soLuongPhongHoc].sucChua;

            soLuongPhongHoc++;
        } else {
            cout << "Danh sach da day, khong the them phong hoc moi." << endl;
        }
    }

    void XoaPhongHoc() {
        char maPhongHoc[10];
        cout << "Nhap ma phong hoc can xoa: ";
        cin.ignore();
        cin.getline(maPhongHoc, 10);

        for (int i = 0; i < soLuongPhongHoc; ++i) {
            if (strcmp(danhSachPhongHoc[i].maPhongHoc, maPhongHoc) == 0) {
                for (int j = i; j < soLuongPhongHoc - 1; ++j) {
                    danhSachPhongHoc[j] = danhSachPhongHoc[j + 1];
                }
                soLuongPhongHoc--;
                cout << "Da xoa phong hoc co ma " << maPhongHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay phong hoc co ma " << maPhongHoc << endl;
    }

    void SuaPhongHoc() {
        char maPhongHoc[10];
        cout << "Nhap ma phong hoc can sua: ";
        cin.ignore();
        cin.getline(maPhongHoc, 10);

        for (int i = 0; i < soLuongPhongHoc; ++i) {
            if (strcmp(danhSachPhongHoc[i].maPhongHoc, maPhongHoc) == 0) {
                cout << "Nhap so phong moi: ";
                cin.getline(danhSachPhongHoc[i].soPhong, 10);

                cout << "Nhap suc chua moi: ";
                cin >> danhSachPhongHoc[i].sucChua;
                
                cout << "Da sua phong hoc co ma " << maPhongHoc << endl;
                return;
            }
        }
        cout << "Khong tim thay phong hoc co ma " << maPhongHoc << endl;
    }
    void DocDanhSachPhongHoc(const char* tenTep) {
    ifstream file(tenTep);
    if (!file) {
        cerr << "Khong mo duoc file." << endl;
        return;
    }
    soLuongPhongHoc = 0;
    char maPhongHoc[10];
    char soPhong[10];
    int sucChua;

    while (soLuongPhongHoc < 100 && file.getline(maPhongHoc, 10, ',') &&
                                    file.getline(soPhong, 10, ',') &&
                                    file >> sucChua) {
        file.ignore();
        strcpy(danhSachPhongHoc[soLuongPhongHoc].maPhongHoc, maPhongHoc);
        strcpy(danhSachPhongHoc[soLuongPhongHoc].soPhong, soPhong);
        danhSachPhongHoc[soLuongPhongHoc].sucChua = sucChua;
        soLuongPhongHoc++;
    }
    file.close();
}

    void InDanhSachPhongHoc() {
        for (int i = 0; i < soLuongPhongHoc; ++i) {
            cout << "Ma phong hoc: " << danhSachPhongHoc[i].maPhongHoc << endl;
            cout << "So phong: " << danhSachPhongHoc[i].soPhong << endl;
            cout << "Suc chua: " << danhSachPhongHoc[i].sucChua << endl;
            cout << "--------------------------" << endl;
        }
    }
};
void menu() {
    cout << "----------------------------QUAN LY TIN HOC------------------------------\n";
    cout << "| 1. THEM HOC VIEN                                                       |\n";
    cout << "| 2. SUA HOC VIEN                                                        |\n";
    cout << "| 3. XOA HOC VIEN                                                        |\n";
    cout << "| 4. DOC FILE DANH SACH HOC VIEN                                         |\n";
    cout << "| 5. IN DANH SACH HOC VIEN                                               |\n";
    cout << "| 6. THEM GIANG VIEN                                                     |\n";
    cout << "| 7. SUA GIANG VIEN                                                      |\n";
    cout << "| 8. XOA GIANG VIEN                                                      |\n";
    cout << "| 9. DOC FILE DANH SACH GIANG VIEN                                       |\n";
    cout << "| 10. IN DANH SACH GIANG VIEN                                            |\n";
    cout << "| 11. THEM PHONG HOC                                                     |\n";
    cout << "| 12. SUA PHONG HOC                                                      |\n";
    cout << "| 13. XOA PHONG HOC                                                      |\n";
    cout << "| 14. DOC FILE DANH SACH PHONG HOC                                       |\n";
    cout << "| 15. IN DANH SACH PHONG HOC                                             |\n";
    cout << "| 16. THEM KHOA HOC                                                      |\n";
    cout << "| 17. SUA KHOA HOC                                                       |\n";
    cout << "| 18. XOA KHOA HOC                                                       |\n";
    cout << "| 19. DOC FILE DANH SACH KHOA HOC                                        |\n";
    cout << "| 20. IN DANH SACH KHOA HOC                                              |\n";
    cout << "| 21. THEM LICH HOC                                                      |\n";
    cout << "| 22. SUA LICH HOC                                                       |\n";
    cout << "| 23. XOA LICH HOC                                                       |\n";
    cout << "| 24. DOC FILE DANH SACH LICH HOC                                        |\n";
    cout << "| 25. IN DANH SACH LICH HOC                                              |\n";
    cout << "| 26. THOAT                                                              |\n";
    cout << "-------------------------------------------------------------------------\n";
    cout << "LUA CHON: ";
}
int main() {
    HocVien danhSachHocVien;
    KhoaHoc danhSachKhoaHoc;
    GiangVien danhSachGiangVien;
    LichHoc lichHoc;
    PhongHoc phongHoc;
    int luaChon;
    do {
        menu();
        cin >> luaChon;
        switch(luaChon) {
            case 1:
            	danhSachHocVien.ThemHocVien();
                break;
            case 2:
                danhSachHocVien.SuaHocVien();
                break;
            case 3:
                char maHocVienXoa[20];
                cout << "Nhap ma hoc vien can xoa: ";
                cin.ignore();
                cin.getline(maHocVienXoa, 20);
                danhSachHocVien.XoaHocVien(maHocVienXoa);
                break;
            case 4:
                danhSachHocVien.DocDanhSachHocVien("DanhSachHocVien.txt");
                break;
            case 5:
                danhSachHocVien.InDanhSachHocVien();
                break;
             case 6:
            	danhSachGiangVien.ThemGiangVien();
                break;
            case 7:
                int index;
                cout << "Nhap vi tri giang vien can sua: ";
                cin >> index;
                danhSachGiangVien.CapNhatThongTinGiangVien(index);
                break;
            case 8:
                int ind;
                cout << "Nhap vi tri giang vien can xoa: ";
                cin >> ind;
                danhSachGiangVien.XoaGiangVien(ind);
                break;
            case 9:
                danhSachGiangVien.DocDanhSachGiangVien("DanhSachGiangVien.txt");
                break;
            case 10:
                danhSachGiangVien.InDanhSachGiangVien();
                break;
            case 11:
                phongHoc.ThemPhongHocTuBanPhim();
                break;
            case 12:
                phongHoc.SuaPhongHoc();
                break;
            case 13:
                phongHoc.XoaPhongHoc();
                break;
            case 14:
                phongHoc.DocDanhSachPhongHoc("DanhSachPhongHoc.txt");
                break;
            case 15:
                phongHoc.InDanhSachPhongHoc();
                break;
            case 16:
                danhSachKhoaHoc.ThemKhoaHocTuBanPhim();
                break;
            case 17:
                danhSachKhoaHoc.SuaKhoaHoc();
                break;
            case 18:
                danhSachKhoaHoc.XoaKhoaHoc();
                break;
            case 19:
                danhSachKhoaHoc.DocDanhSachKhoaHoc("DanhSachKhoaHoc.txt");
                break;
            case 20:
                danhSachKhoaHoc.InDanhSachKhoaHoc();
                break;
            case 21:
                lichHoc.ThemLichHocTuBanPhim();
                break;
            case 22:
                lichHoc.SuaLichHoc();
                break;
            case 23:
                lichHoc.XoaLichHoc();
                break;
            case 24:
                lichHoc.DocDanhSachLichHoc("DanhSachLichHoc.txt");
                break;
            case 25:
                lichHoc.InDanhSachLichHoc();
                break;
            case 26:
                cout << "Ket thuc chuong trinh.";
                break;
            default:
                cout << "Lua chon khong hop le.";
        }
    } while(luaChon != 26);

    return 0;
}

