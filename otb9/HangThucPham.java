/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class HangThucPham extends HangHoa {
    private String ngaySX;
    private String ngayHH;

    @Override
    public void nhap() {
        super.nhap();
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap ngay san xuat: ");
        ngaySX = sc.nextLine();
        System.out.print("Nhap ngay het han: ");
        ngayHH = sc.nextLine();
    }

    @Override
    public String danhGiaBanHang() {
        return (soLuongTon > 0) ? "Kho ban" : "Binh thuong";
    }
}
