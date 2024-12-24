/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OnThi;


import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class main {
    
    public static void main(String[] args) {
        QLGiangVien ql = new QLGiangVien();
        Scanner sc = new Scanner(System.in);

        int choice;
        do {
            System.out.println("\nCHUONG TRINH QUAN LY SINH VIEN");
            System.out.println("-------------------------------");
            System.out.println("1. Nhap ");
            System.out.println("2. Hien thi ");
            System.out.println("3. Tim kiem");
            System.out.println("4. Sua ban ghi\n"
                    + "5.Tinh tong tien");
            System.out.println("6. Thoat");
            System.out.print("\tChon chuc nang: ");
            choice = sc.nextInt();
            sc.nextLine();
            
            switch(choice) {
                case 1:
                    GiangVien gv = new GiangVien();
                    ql.addGiangVien(gv);
                    break;
                case 2:
                    ql.inDL();
                    break;
                case 3:
                    System.out.println("Nhap ma giao vien muon tim:");
                    String masv = sc.nextLine();
                    System.out.println(ql.searchGiangVien(masv));
                    break;
                case 4:
                    System.out.println("Nhap thong tin");
                    GiangVien gv1 = new GiangVien();
                    ql.nhap();
                    ql.editGiangVien(gv1);
                    break;
                case 5:
                    System.out.println("Nhap Hoc ham hoc vi: ");
                    String hocham = sc.nextLine();
                    System.out.println(ql.getTotalSalary(hocham));
                    
                    break;
                case 6:
                    break;
                default:
                    System.out.println("Vui long chon dung chuc nang");
                    break;
            }
        } while(choice != 8);
    }
}

