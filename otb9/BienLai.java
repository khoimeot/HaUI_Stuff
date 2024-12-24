/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class BienLai {
    private KhachHang1 khachHang;
    private int chiSoCu;
    private int chiSoMoi;

    public BienLai() {
        khachHang = new KhachHang1();
    }

    public void nhap() {
        khachHang.nhap();
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap chi so cu: ");
        chiSoCu = sc.nextInt();
        System.out.print("Nhap chi so moi: ");
        chiSoMoi = sc.nextInt();
    }

    public double tinhTienDien() {
        return (chiSoMoi - chiSoCu) * 5.0;
    }

    @Override
    public String toString() {
        return khachHang + ", Chi so cu: " + chiSoCu + ", Chi so moi: " + chiSoMoi + ", Tien dien: " + tinhTienDien();
    }
}
