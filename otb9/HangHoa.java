/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
abstract class HangHoa {
    protected String maHang;
    protected String tenHang;
    protected double donGia;
    protected int soLuongTon;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ma hang: ");
        maHang = sc.nextLine();
        System.out.print("Nhap ten hang: ");
        tenHang = sc.nextLine();
        System.out.print("Nhap don gia: ");
        donGia = sc.nextDouble();
        System.out.print("Nhap so luong ton: ");
        soLuongTon = sc.nextInt();
    }

    public abstract String danhGiaBanHang();
}