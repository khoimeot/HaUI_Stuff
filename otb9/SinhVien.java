/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class SinhVien {
    private String hoTen;
    private int tuoi;
    private String lop;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ho ten: ");
        hoTen = sc.nextLine();
        System.out.print("Nhap tuoi: ");
        tuoi = sc.nextInt();
        sc.nextLine(); // Clear buffer
        System.out.print("Nhap lop: ");
        lop = sc.nextLine();
    }

    @Override
    public String toString() {
        return hoTen + ", Tuoi: " + tuoi + ", Lop: " + lop;
    }
}