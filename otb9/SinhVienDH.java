/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class SinhVienDH {
    private String maSV;
    private String hoTen;
    private String ngaySinh;
    private int namVaoHoc;
    private java.util.ArrayList<KetQuaHocTap> ketQua;

    public SinhVienDH() {
        ketQua = new java.util.ArrayList<>();
    }

    public void nhap() {
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ma sinh vien: ");
        maSV = sc.nextLine();
        System.out.print("Nhap ho ten: ");
        hoTen = sc.nextLine();
        System.out.print("Nhap ngay sinh: ");
        ngaySinh = sc.nextLine();
        System.out.print("Nhap nam vao hoc: ");
        namVaoHoc = sc.nextInt();
        System.out.print("Nhap so luong hoc ky: ");
        int soHK = sc.nextInt();
        for (int i = 0; i < soHK; i++) {
            System.out.println("Nhap thong tin hoc ky thu " + (i + 1) + ":");
            KetQuaHocTap kq = new KetQuaHocTap();
            kq.nhap();
            ketQua.add(kq);
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Ma SV: ").append(maSV).append(", Ho ten: ").append(hoTen).append(", Ngay sinh: ").append(ngaySinh).append(", Nam vao hoc: ").append(namVaoHoc).append("\nKet qua hoc tap:\n");
        for (KetQuaHocTap kq : ketQua) {
            sb.append(kq).append("\n");
        }
        return sb.toString();
    }
}
