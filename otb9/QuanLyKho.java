/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class QuanLyKho {
    private java.util.ArrayList<HangHoa> danhSachHangHoa = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong hang hoa: ");
        int soLuong = sc.nextInt();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin hang hoa thu " + (i + 1) + ":");
            HangHoa hang = new HangThucPham(); // For simplicity, only using HangThucPham
            hang.nhap();
            danhSachHangHoa.add(hang);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach hang hoa:");
        for (HangHoa hang : danhSachHangHoa) {
            System.out.println(hang);
        }
    }

    public static void main(String[] args) {
        QuanLyKho qlKho = new QuanLyKho();
        qlKho.nhap();
        qlKho.inDanhSach();
    }
}

