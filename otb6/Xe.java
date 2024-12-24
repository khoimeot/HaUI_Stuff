/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb6;

import java.util.Scanner;

/**
 *
 * @author PC
 */
public class Xe {
    private String tenChuXe;
    private String loaiXe;
    private int dungTich;
    private double triGia;
    public void nhap() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập tên chủ xe: ");
        tenChuXe = scanner.nextLine();

        System.out.print("Nhập loại xe: ");
        loaiXe = scanner.nextLine();

        System.out.print("Nhập dung tích xi lanh (cc): ");
        dungTich = scanner.nextInt();

        System.out.print("Nhập trị giá xe (triệu đồng): ");
        triGia = scanner.nextDouble();
    }
    public double tinhThue() {
        if (dungTich < 100) {
            return triGia * 0.01;
        } else if (dungTich <= 200) {
            return triGia * 0.03;
        } else {
            return triGia * 0.05;
        }
    }
     public static void inTieuDe() {
        System.out.printf("%20s%20s%20s%20s%20s%n", "Tên chủ xe", "Loại xe", "Dung tích", "Trị giá", "Thuế trước bạ");
    }

    // In thông tin xe
    public void inThongTin() {
        System.out.printf("%20s%20s%20d%20.2f%20.2f%n", tenChuXe, loaiXe, dungTich, triGia, tinhThue());
    }
}
