/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb6;

/**
 *
 * @author PC
 */
public class NhanVien {
    private String maNV;
    private int soSP;

    // Hàm khởi tạo không đối
    public NhanVien() {
        this.maNV = "";
        this.soSP = 0;
    }

    // Hàm khởi tạo có đối
    public NhanVien(String maNV, int soSP) {
        this.maNV = maNV;
        setSoSP(soSP); // Gọi setSoSP để kiểm tra số sản phẩm hợp lệ
    }

    // Getter và Setter cho maNV
    public String getMaNV() {
        return maNV;
    }

    public void setMaNV(String maNV) {
        this.maNV = maNV;
    }

    // Getter và Setter cho soSP (kiểm tra số sản phẩm > 0)
    public int getSoSP() {
        return soSP;
    }

    public void setSoSP(int soSP) {
        if (soSP > 0) {
            this.soSP = soSP;
        } else {
            System.out.println("Số sản phẩm phải lớn hơn 0. Gán mặc định là 0.");
            this.soSP = 0;
        }
    }

    // Kiểm tra vượt chuẩn
    public boolean coVuotChuan() {
        return soSP > 500;
    }

    // Tổng kết: "Vượt" nếu vượt chuẩn, ngược lại trả về chuỗi rỗng
    public String getTongKet() {
        return coVuotChuan() ? "Vượt" : "";
    }

    // Tính lương
    public double getLuong() {
        int spVuotChuan = coVuotChuan() ? soSP - 500 : 0;
        int spKhongVuotChuan = soSP - spVuotChuan;
        return spKhongVuotChuan * 20000 + spVuotChuan * 30000;
    }

    // Xuất tiêu đề
    public static void xuatTieuDe() {
        System.out.printf("%15s%15s%15s%15s%15s%n", "Mã NV", "Số SP", "Lương", "Tổng Kết", "Vượt Chuẩn");
    }

    // In thông tin nhân viên
    public void inDuLieu() {
        System.out.printf("%15s%15d%15.2f%15s%15b%n", maNV, soSP, getLuong(), getTongKet(), coVuotChuan());
    }
}
