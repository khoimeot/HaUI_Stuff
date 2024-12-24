/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class KetQuaHocTap {
    private String tenHocKy;
    private double diemTB;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ten hoc ky: ");
        tenHocKy = sc.nextLine();
        System.out.print("Nhap diem trung binh: ");
        diemTB = sc.nextDouble();
    }

    @Override
    public String toString() {
        return tenHocKy + ": " + diemTB;
    }
}
