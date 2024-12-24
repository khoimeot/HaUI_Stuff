/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class TheMuon {
    private String maPhieuMuon;
    private int ngayMuon;
    private int hanTra;
    private String soHieuSach;
    private SinhVien sinhVien;

    public TheMuon() {
        sinhVien = new SinhVien();
    }

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ma phieu muon: ");
        maPhieuMuon = sc.nextLine();
        System.out.print("Nhap ngay muon (so nguyen): ");
        ngayMuon = sc.nextInt();
        System.out.print("Nhap han tra (so nguyen): ");
        hanTra = sc.nextInt();
        sc.nextLine(); // Clear buffer
        System.out.print("Nhap so hieu sach: ");
        soHieuSach = sc.nextLine();
        sinhVien.nhap();
    }

    @Override
    public String toString() {
        return "Ma phieu: " + maPhieuMuon + ", Ngay muon: " + ngayMuon + ", Han tra: " + hanTra + ", So hieu sach: " + soHieuSach + "\nSinh vien: " + sinhVien;
    }
}
