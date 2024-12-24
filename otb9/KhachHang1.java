/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class KhachHang1 {
    private String hoTenChuHo;
    private String soNha;
    private String maCongTo;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ho ten chu ho: ");
        hoTenChuHo = sc.nextLine();
        System.out.print("Nhap so nha: ");
        soNha = sc.nextLine();
        System.out.print("Nhap ma cong to: ");
        maCongTo = sc.nextLine();
    }

    @Override
    public String toString() {
        return hoTenChuHo + ", So nha: " + soNha + ", Ma cong to: " + maCongTo;
    }
}
