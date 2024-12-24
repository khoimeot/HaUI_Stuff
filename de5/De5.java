/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.de5;

/**
 *
 * @author PC
 */
import java.util.Scanner;

public class De5 {
    public static void main(String[] args) {
        TourManagerImpl manager = new TourManagerImpl();
        Scanner sc = new Scanner(System.in);

        // Thêm dữ liệu mẫu
        manager.addTour(new Tour(1, "Tour Sapa", 300.0, 50, 2, "Bus"));
        manager.addTour(new Tour(2, "Tour Hạ Long", 500.0, 30, 3, "Ship"));
        manager.addTour(new Tour(3, "Tour Đà Nẵng", 400.0, 20, 4, "Plane"));

        int choice;
        do {
            System.out.println("\nQUẢN LÝ TOUR DU LỊCH");
            System.out.println("1. Hiển thị tất cả tour");
            System.out.println("2. Tìm tour theo tên");
            System.out.println("3. Sắp xếp tour theo tên");
            System.out.println("4. Tính tổng giá trị tồn kho");
            System.out.println("5. Thoát");
            System.out.print("Chọn chức năng: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Danh sách tất cả tour:");
                    manager.displayAllTours();
                    break;

                case 2:
                    System.out.print("Nhập tên tour cần tìm: ");
                    String name = sc.nextLine();
                    Tour found = manager.searchTour(name);
                    if (found != null) {
                        System.out.println("Tìm thấy: " + found);
                    } else {
                        System.out.println("Không tìm thấy tour với tên: " + name);
                    }
                    break;

                case 3:
                    System.out.println("Danh sách sau khi sắp xếp:");
                    manager.sortedTour();
                    manager.displayAllTours();
                    break;

                case 4:
                    System.out.println("Tổng giá trị tồn kho: " + manager.getTotalStorage());
                    break;

                case 5:
                    System.out.println("Thoát chương trình.");
                    break;

                default:
                    System.out.println("Vui lòng chọn đúng chức năng.");
            }
        } while (choice != 5);

        sc.close();
    }
}

