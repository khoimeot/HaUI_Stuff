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
public class OTb63 {
    private double a ,b ,c;
    
    
    public void nhap() {
        Scanner scanner = new Scanner(System.in);
        do {
            System.out.print("Nhap he so a :");
            a = scanner.nextDouble();
        } while (a == 0);
        
        System.out.print("Nhap he so b :");
        b = scanner.nextDouble();
        System.out.print("Nhap he so c :");
        c = scanner.nextDouble();
    }
        // Giải phương trình bậc 2
    public String giaiPT() {
        double delta = b * b - 4 * a * c;

        if (delta < 0) {
            return "Phương trình vô nghiệm.";
        } else if (delta == 0) {
            double nghiemKep = -b / (2 * a);
            return "Phương trình có nghiệm kép: x1 = x2 = " + nghiemKep;
        } else {
            double x1 = (-b + Math.sqrt(delta)) / (2 * a);
            double x2 = (-b - Math.sqrt(delta)) / (2 * a);
            return "Phương trình có 2 nghiệm phân biệt: x1 = " + x1 + ", x2 = " + x2;
        }
    }

    // In tiêu đề
    public static void inTieuDe() {
        System.out.printf("%10s%10s%10s%30s%n", "Hệ số a", "Hệ số b", "Hệ số c", "Kết quả");
    }

    // In kết quả
    public void inKetQua() {
        System.out.printf("%10.2f%10.2f%10.2f%30s%n", a, b, c, giaiPT());
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        // TODO code application logic here
        Scanner scanner = new Scanner(System.in);
         System.out.print("Nhập số lượng phương trình cần nhập: ");
        int n = scanner.nextInt();

        OTb63[] mangPTB2 = new OTb63[n];

        // Nhập thông tin từng phương trình
        for (int i = 0; i < n; i++) {
            System.out.println("Nhập phương trình thứ " + (i + 1) + ":");
            mangPTB2[i] = new OTb63();
            mangPTB2[i].nhap();
        }

        // Hiển thị kết quả
        OTb63.inTieuDe();
        for (OTb63 pt : mangPTB2) {
            pt.inKetQua();
    }
}
}
