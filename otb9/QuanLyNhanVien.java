/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class QuanLyNhanVien {
    private java.util.ArrayList<CanBo> danhSachCanBo = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong can bo: ");
        int soLuong = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin can bo thu " + (i + 1) + ":");
            CongNhan cn = new CongNhan(); // For simplicity, only using CongNhan
            cn.nhap();
            danhSachCanBo.add(cn);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach can bo:");
        for (CanBo cb : danhSachCanBo) {
            System.out.println(cb);
        }
    }

}

