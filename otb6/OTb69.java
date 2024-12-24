/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb6;
import java.util.ArrayList;
import java.util.Scanner;
/*
 *
 * @author PC
 */
public class OTb69 {

    private static ArrayList<Staff> staffList = new ArrayList<>();
    private static ArrayList<Student> studentList = new ArrayList<>();
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n--- MENU ---");
            System.out.println("1. Hiển thị toàn bộ Staff");
            System.out.println("2. Hiển thị toàn bộ Student");
            System.out.println("3. Tìm kiếm theo tên");
            System.out.println("4. Tìm Staff có lương cao nhất");
            System.out.println("5. Lọc Student có điểm < 5");
            System.out.println("6. Thoát");
            System.out.print("Lựa chọn của bạn: ");
            choice = scanner.nextInt();
            scanner.nextLine(); // Bỏ qua ký tự xuống dòng

            switch (choice) {
                case 1:
                    displayAllStaff();
                    break;
                case 2:
                    displayAllStudents();
                    break;
                case 3:
                    searchByName(scanner);
                    break;
                case 4:
                    findHighestPaidStaff();
                    break;
                case 5:
                    filterLowScoreStudents();
                    break;
                case 6:
                    System.out.println("Kết thúc chương trình.");
                    break;
                default:
                    System.out.println("Lựa chọn không hợp lệ.");
            }
        } while (choice != 6);
    }
    public static void displayAllStaff() {
        System.out.println("\nDanh sách Staff:");
        for (Staff staff : staffList) {
            System.out.println(staff);
        }
    }

    // Hiển thị tất cả Student
    public static void displayAllStudents() {
        System.out.println("\nDanh sách Student:");
        for (Student student : studentList) {
            System.out.println(student);
        }
    }

    // Tìm kiếm theo tên
    public static void searchByName(Scanner scanner) {
        System.out.print("\nNhập tên cần tìm: ");
        String name = scanner.nextLine();
        System.out.println("Kết quả tìm kiếm:");
        for (Staff staff : staffList) {
            if (staff.getName().equalsIgnoreCase(name)) {
                System.out.println(staff);
            }
        }
        for (Student student : studentList) {
            if (student.getName().equalsIgnoreCase(name)) {
                System.out.println(student);
            }
        }
    }

    // Tìm Staff có lương cao nhất
    public static void findHighestPaidStaff() {
        if (staffList.isEmpty()) {
            System.out.println("\nDanh sách Staff trống.");
            return;
        }

        Staff highestPaid = staffList.get(0);
        for (Staff staff : staffList) {
            if (staff.getPay() > highestPaid.getPay()) {
                highestPaid = staff;
            }
        }
        System.out.println("\nStaff có lương cao nhất:");
        System.out.println(highestPaid);
    }

    // Lọc Student có điểm < 5
    public static void filterLowScoreStudents() {
        System.out.println("\nDanh sách Student có điểm < 5:");
        for (Student student : studentList) {
            if (student.getScore() < 5) {
                System.out.println(student);
            }
        }
    }
}
