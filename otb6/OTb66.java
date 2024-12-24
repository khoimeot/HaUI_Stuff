/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb6;
import java.util.Scanner;
/**
 *
 * @author PC
 */
public class OTb66 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập số lượng nhân viên
        System.out.print("Nhập số lượng nhân viên: ");
        int n = scanner.nextInt();
        scanner.nextLine(); // Bỏ qua ký tự xuống dòng

        // Tạo mảng danh sách nhân viên
        NhanVien[] danhSachNhanVien = new NhanVien[n];

        // Nhập thông tin từng nhân viên
        for (int i = 0; i < n; i++) {
            System.out.println("Nhập thông tin nhân viên thứ " + (i + 1) + ":");
            System.out.print("Mã NV: ");
            String maNV = scanner.nextLine();
            System.out.print("Số SP: ");
            int soSP = scanner.nextInt();
            scanner.nextLine(); // Bỏ qua ký tự xuống dòng

            // Thêm nhân viên vào danh sách
            danhSachNhanVien[i] = new NhanVien(maNV, soSP);
        }

        // Hiển thị danh sách nhân viên
        System.out.println("\nDanh sách nhân viên:");
        NhanVien.xuatTieuDe();
        for (NhanVien nv : danhSachNhanVien) {
            nv.inDuLieu();
        }

        // In danh sách nhân viên vượt chuẩn
        System.out.println("\nDanh sách nhân viên vượt chuẩn:");
        NhanVien.xuatTieuDe();
        for (NhanVien nv : danhSachNhanVien) {
            if (nv.coVuotChuan()) {
                nv.inDuLieu();
            }
        }
    }
}
