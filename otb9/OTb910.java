/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
public class OTb910 {

    private java.util.ArrayList<TheMuon> danhSachTheMuon = new java.util.ArrayList<>();

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap so luong the muon: ");
        int soLuong = sc.nextInt();
        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhap thong tin the muon thu " + (i + 1) + ":");
            TheMuon tm = new TheMuon();
            tm.nhap();
            danhSachTheMuon.add(tm);
        }
    }

    public void inDanhSach() {
        System.out.println("Danh sach the muon:");
        for (TheMuon tm : danhSachTheMuon) {
            System.out.println(tm);
        }
    }

    public static void main(String[] args) {
        OTb910 qlMuonTra = new OTb910();
        qlMuonTra.nhap();
        qlMuonTra.inDanhSach();
    }
}
