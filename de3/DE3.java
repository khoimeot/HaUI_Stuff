/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.de3;

/**
 *
 * @author PC
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class DE3 {
    private ArrayList<Employee> employees = new ArrayList<>();

    // Thêm nhân viên
    public void addEmployee(Employee employee) {
        employees.add(employee);
    }

    // Hiển thị danh sách nhân viên
    public void displayEmployees() {
        for (Employee employee : employees) {
            employee.displayData();
        }
    }

    // Tìm kiếm nhân viên theo tên
    public Employee searchEmployeeByName(String name) {
        for (Employee employee : employees) {
            if (employee.getName().equalsIgnoreCase(name)) {
                return employee;
            }
        }
        return null;
    }

    // Cập nhật thông tin nhân viên
    public void updateEmployee(String name) {
        Employee employee = searchEmployeeByName(name);
        if (employee != null) {
            System.out.println("Nhập thông tin mới cho nhân viên:");
            employee.inputData();
        } else {
            System.out.println("Không tìm thấy nhân viên với tên: " + name);
        }
    }

    // Sắp xếp danh sách theo lương
    public void sortEmployeesBySalary() {
        Collections.sort(employees, Comparator.comparingInt(Employee::calculateSalary).reversed());
    }

    // Chương trình chính
    public static void main(String[] args) {
        DE3 manager = new DE3();
        Scanner sc = new Scanner(System.in);

        // Tạo dữ liệu mẫu
        manager.addEmployee(new PartTimeEmployee("John", 50, 20));
        manager.addEmployee(new FullTimeEmployee("Alice", 80));
        manager.addEmployee(new PartTimeEmployee("Bob", 30, 40));

        int choice;
        do {
            System.out.println("\nQUẢN LÝ NHÂN VIÊN");
            System.out.println("1. Thêm nhân viên");
            System.out.println("2. Hiển thị danh sách");
            System.out.println("3. Tìm kiếm nhân viên theo tên");
            System.out.println("4. Cập nhật thông tin nhân viên");
            System.out.println("5. Sắp xếp nhân viên theo lương");
            System.out.println("6. Thoát");
            System.out.print("Chọn chức năng: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Chọn loại nhân viên:");
                    System.out.println("1. Nhân viên part-time");
                    System.out.println("2. Nhân viên full-time");
                    int type = sc.nextInt();
                    sc.nextLine();

                    Employee employee;
                    if (type == 1) {
                        employee = new PartTimeEmployee();
                    } else {
                        employee = new FullTimeEmployee();
                    }
                    employee.inputData();
                    manager.addEmployee(employee);
                    break;

                case 2:
                    manager.displayEmployees();
                    break;

                case 3:
                    System.out.print("Nhập tên nhân viên cần tìm: ");
                    String name = sc.nextLine();
                    Employee found = manager.searchEmployeeByName(name);
                    if (found != null) {
                        found.displayData();
                    } else {
                        System.out.println("Không tìm thấy nhân viên.");
                    }
                    break;

                case 4:
                    System.out.print("Nhập tên nhân viên cần cập nhật: ");
                    String updateName = sc.nextLine();
                    manager.updateEmployee(updateName);
                    break;

                case 5:
                    manager.sortEmployeesBySalary();
                    System.out.println("Danh sách sau khi sắp xếp:");
                    manager.displayEmployees();
                    break;

                case 6:
                    System.out.println("Thoát chương trình.");
                    break;

                default:
                    System.out.println("Vui lòng chọn đúng chức năng.");
            }
        } while (choice != 6);

        sc.close();
    }
}
