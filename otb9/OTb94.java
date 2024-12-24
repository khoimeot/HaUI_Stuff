/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
public class OTb94 {
private java.util.ArrayList<TaiLieu> danhSachTaiLieu = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong tai lieu: ");
        int soLuong = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin tai lieu thu " + (i + 1) + ":");
            TaiLieu tl = new TaiLieu();
            tl.nhap();
            danhSachTaiLieu.add(tl);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach tai lieu:");
        for (TaiLieu tl : danhSachTaiLieu) {
            System.out.println(tl);
        }
    }

    public static void main(String[] args) {
        OTb94 qlThuVien = new OTb94();
        qlThuVien.nhap();
        qlThuVien.inDanhSach();
    }
}
