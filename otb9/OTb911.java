/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
public class OTb911 {
    private java.util.ArrayList<BienLai> danhSachBienLai = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong bien lai: ");
        int soLuong = sc.nextInt();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin bien lai thu " + (i + 1) + ":");
            BienLai bl = new BienLai();
            bl.nhap();
            danhSachBienLai.add(bl);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach bien lai:");
        for (BienLai bl : danhSachBienLai) {
            System.out.println(bl);
        }
    }

    public static void main(String[] args) {
        OTb911 qlTienDien = new OTb911();
        qlTienDien.nhap();
        qlTienDien.inDanhSach();
    }
}
