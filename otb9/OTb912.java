/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
public class OTb912 {
    private java.util.ArrayList<SinhVienDH> danhSachSinhVien = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong sinh vien: ");
        int soLuong = sc.nextInt();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin sinh vien thu " + (i + 1) + ":");
            SinhVienDH sv = new SinhVienDH();
            sv.nhap();
            danhSachSinhVien.add(sv);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach sinh vien:");
        for (SinhVienDH sv : danhSachSinhVien) {
            System.out.println(sv);
        }
    }

    public static void main(String[] args) {
        OTb912 qlSinhVien = new OTb912();
        qlSinhVien.nhap();
        qlSinhVien.inDanhSach();
    }
}
