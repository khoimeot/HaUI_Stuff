/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.main;

/**
 *
 * @author IT SUPPORTER
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Nhập thông tin cho 2 nhân viên
        NhanVien[] danhSachNhanVien = new NhanVien[2];

        for (int i = 0; i < danhSachNhanVien.length; i++) {
            System.out.println("Nhập thông tin cho nhân viên " + (i + 1) + ": ");
            
            System.out.print("Mã nhân viên: ");
            String maNV = scanner.nextLine();
            
            System.out.print("Số sản phẩm: ");
            int soSP = scanner.nextInt();
            scanner.nextLine(); // Bỏ qua dòng trống
            
            // Tạo nhân viên với thông tin vừa nhập
            danhSachNhanVien[i] = new NhanVien(maNV, soSP);
        }

        // Xuất tiêu đề
        NhanVien.xuatTieuDe();

        // In thông tin của từng nhân viên
        for (NhanVien nv : danhSachNhanVien) {
            nv.inDL();
        }

        scanner.close();
    }
}

