/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.de2;

/**
 *
 * @author PC
 */
import java.util.Scanner;

public class De2 {
    public static void main(String[] args) {
        CarManager carManager = new CarManager();
        Scanner sc = new Scanner(System.in);

        int choice;
        do {
            System.out.println("\nCHƯƠNG TRÌNH QUẢN LÝ Ô TÔ");
            System.out.println("--------------------------");
            System.out.println("1. Thêm ô tô");
            System.out.println("2. Hiển thị danh sách ô tô");
            System.out.println("3. Tìm kiếm ô tô theo ID");
            System.out.println("4. Tìm kiếm ô tô theo màu sắc");
            System.out.println("5. Cập nhật thông tin ô tô");
            System.out.println("6. Tính tổng giá tiền ô tô");
            System.out.println("7. Sắp xếp ô tô theo giá (giảm dần)");
            System.out.println("8. Sắp xếp ô tô theo ID");
            System.out.println("9. Thoát");
            System.out.print("Chọn chức năng: ");
            choice = sc.nextInt();
            sc.nextLine(); // Đọc ký tự xuống dòng

            switch (choice) {
                case 1:
                    addCar(carManager, sc);
                    break;
                case 2:
                    displayCars(carManager);
                    break;
                case 3:
                    searchCarByID(carManager, sc);
                    break;
                case 4:
                    searchCarByColor(carManager, sc);
                    break;
                case 5:
                    updateCar(carManager, sc);
                    break;
                case 6:
                    calculateTotalPrice(carManager);
                    break;
                case 7:
                    sortCarsByPrice(carManager);
                    break;
                case 8:
                    sortCarsByID(carManager);
                    break;
                case 9:
                    System.out.println("Thoát chương trình.");
                    break;
                default:
                    System.out.println("Vui lòng chọn đúng chức năng.");
            }
        } while (choice != 9);

        sc.close();
    }

    // Chức năng thêm ô tô
    private static void addCar(CarManager carManager, Scanner sc) {
        System.out.print("Nhập ID: ");
        int proid = sc.nextInt();
        sc.nextLine();

        System.out.print("Nhập tên: ");
        String name = sc.nextLine();

        System.out.print("Nhập số lượng: ");
        int quantity = sc.nextInt();

        System.out.print("Nhập giá: ");
        double price = sc.nextDouble();
        sc.nextLine();

        System.out.print("Nhập màu sắc: ");
        String color = sc.nextLine();

        System.out.print("Nhập cân nặng: ");
        double weight = sc.nextDouble();

        Car car = new Car(proid, name, quantity, price, color, weight);
        carManager.addCar(car);

        System.out.println("Thêm ô tô thành công!");
    }

    // Chức năng hiển thị danh sách ô tô
    private static void displayCars(CarManager carManager) {
        System.out.println("\nDanh sách ô tô:");
        for (Car car : carManager.cars) {
            System.out.println(car);
        }
    }

    // Chức năng tìm kiếm ô tô theo ID
    private static void searchCarByID(CarManager carManager, Scanner sc) {
        System.out.print("Nhập ID cần tìm: ");
        int proid = sc.nextInt();
        sc.nextLine();

        Car car = carManager.searchCarByID(proid);
        if (car != null) {
            System.out.println("Ô tô tìm được: " + car);
        } else {
            System.out.println("Không tìm thấy ô tô với ID: " + proid);
        }
    }

    // Chức năng tìm kiếm ô tô theo màu sắc
    private static void searchCarByColor(CarManager carManager, Scanner sc) {
        System.out.print("Nhập màu sắc cần tìm: ");
        String color = sc.nextLine();

        System.out.println("Các ô tô có màu " + color + ":");
        for (Car car : carManager.searchCarByColor(color)) {
            System.out.println(car);
        }
    }

    // Chức năng cập nhật thông tin ô tô
    private static void updateCar(CarManager carManager, Scanner sc) {
        System.out.print("Nhập ID ô tô cần cập nhật: ");
        int proid = sc.nextInt();
        sc.nextLine();

        System.out.print("Nhập tên mới: ");
        String name = sc.nextLine();

        System.out.print("Nhập số lượng mới: ");
        int quantity = sc.nextInt();

        System.out.print("Nhập giá mới: ");
        double price = sc.nextDouble();
        sc.nextLine();

        System.out.print("Nhập màu sắc mới: ");
        String color = sc.nextLine();

        System.out.print("Nhập cân nặng mới: ");
        double weight = sc.nextDouble();

        Car updatedCar = new Car(proid, name, quantity, price, color, weight);
        carManager.updateCar(updatedCar);

        System.out.println("Cập nhật thông tin ô tô thành công!");
    }

    // Chức năng tính tổng giá tiền
    private static void calculateTotalPrice(CarManager carManager) {
        double totalPrice = carManager.getTotalPrice();
        System.out.println("Tổng giá tiền của các ô tô: " + totalPrice);
    }

    // Chức năng sắp xếp ô tô theo giá (giảm dần)
    private static void sortCarsByPrice(CarManager carManager) {
        carManager.sortByPrice();
        System.out.println("Danh sách ô tô sau khi sắp xếp theo giá (giảm dần):");
        displayCars(carManager);
    }

    // Chức năng sắp xếp ô tô theo ID
    private static void sortCarsByID(CarManager carManager) {
        carManager.sortByID();
        System.out.println("Danh sách ô tô sau khi sắp xếp theo ID:");
        displayCars(carManager);
    }
}
