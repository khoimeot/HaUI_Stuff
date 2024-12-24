/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb6;
import java.util.Scanner;
import java.util.ArrayList;
/**
 *
 * @author PC
 */
public class OTb64 {
    private static ArrayList<Xe> danhSachXe = new ArrayList<>();
    public static void nhapDanhSachXe() {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Nhập số lượng xe cần quản lý: ");
        int soLuong = scanner.nextInt();
        scanner.nextLine(); // Bỏ qua ký tự xuống dòng

        for (int i = 0; i < soLuong; i++) {
            System.out.println("Nhập thông tin xe thứ " + (i + 1) + ":");
            Xe xe = new Xe();
            xe.nhap();
            danhSachXe.add(xe);
        }
    }
    public static void xuatBangKeKhai() {
        Xe.inTieuDe();
        for (Xe xe : danhSachXe) {
            xe.inThongTin();
        }
    }
    public static void main(String args[]) {
        // TODO code application logic here
        Scanner scanner = new Scanner(System.in);
        int chon;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Nhập thông tin và tạo danh sách xe");
            System.out.println("2. Xuất bảng kê khai tiền thuế trước bạ của các xe");
            System.out.println("3. Thoát");
            System.out.print("Nhập lựa chọn của bạn: ");
            chon = scanner.nextInt();

            switch (chon) {
                case 1 -> nhapDanhSachXe();
                case 2 -> xuatBangKeKhai();
                case 3 -> System.out.println("Chương trình kết thúc.");
                default -> System.out.println("Lựa chọn không hợp lệ. Vui lòng chọn lại.");
            }
        } while (chon != 3);
    }
}
