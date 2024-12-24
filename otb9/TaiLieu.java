/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class TaiLieu {
    protected String maTL;
    protected String tenNXB;
    protected int soBanPH;

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ma tai lieu: ");
        maTL = sc.nextLine();
        System.out.print("Nhap ten nha xuat ban: ");
        tenNXB = sc.nextLine();
        System.out.print("Nhap so ban phat hanh: ");
        soBanPH = sc.nextInt();
    }

    @Override
    public String toString() {
        return maTL + ", " + tenNXB + ", So ban PH: " + soBanPH;
    }
}
