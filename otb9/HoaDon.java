/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class HoaDon {
    private String maHD;
    private String ngayBan;
    private KhachHang khachHang;
    private java.util.ArrayList<Hang> dsHang;

    public HoaDon() {
        khachHang = new KhachHang();
        dsHang = new java.util.ArrayList<>();
    }

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ma hoa don: ");
        maHD = sc.nextLine();
        System.out.print("Nhap ngay ban: ");
        ngayBan = sc.nextLine();
        khachHang.nhap();
        System.out.print("Nhap so mat hang: ");
        int soMatHang = sc.nextInt();
        for (int i = 0; i < soMatHang; i++) {
            System.out.println("Nhap thong tin mat hang thu " + (i + 1) + ":");
            Hang h = new Hang();
            h.nhap();
            dsHang.add(h);
        }
    }

    public void inHD() {
        System.out.println("Ma HD: " + maHD);
        System.out.println("Ngay ban: " + ngayBan);
        System.out.println("Khach hang: " + khachHang);
        System.out.println("Ten hang\tDon gia\tSo luong\tThanh tien");
        double tongTien = 0;
        for (Hang h : dsHang) {
            System.out.println(h);
            tongTien += h.tinhThanhTien();
        }
        System.out.println("Tong tien: " + tongTien);
    }
}