/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
public class Hang {
    private String tenHang;
    private int soLuong;
    private double donGia;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ten hang: ");
        tenHang = sc.nextLine();
        System.out.print("Nhap so luong: ");
        soLuong = sc.nextInt();
        System.out.print("Nhap don gia: ");
        donGia = sc.nextDouble();
    }

    public double tinhThanhTien() {
        return soLuong * donGia;
    }

    @Override
    public String toString() {
        return tenHang + "\t" + donGia + "\t" + soLuong + "\t" + tinhThanhTien();
    }
}
