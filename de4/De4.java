/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package com.mycompany.de4;

/**
 *
 * @author PC
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

public class De4 {
    public static void main(String[] args) {
        ArrayList<Person> people = new ArrayList<>();
        Scanner sc = new Scanner(System.in);

        // Tạo dữ liệu mẫu
        people.add(new Teacher("Alice", 30, "Math"));
        people.add(new Teacher("Bob", 45, "Physics"));
        people.add(new Employee("Charlie", 25, "HR"));
        people.add(new Employee("David", 40, "IT"));
        people.add(new Teacher("Eva", 35, "Chemistry"));

        int choice;
        do {
            System.out.println("\nQUẢN LÝ NHÂN VIÊN");
            System.out.println("1. Hiển thị danh sách nhân viên");
            System.out.println("2. Tìm kiếm nhân viên theo tên");
            System.out.println("3. Nhập phòng ban làm việc và hiển thị danh sách");
            System.out.println("4. Sắp xếp danh sách theo tên");
            System.out.println("5. Thoát");
            System.out.print("Chọn chức năng: ");
            choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.println("Danh sách nhân viên:");
                    for (Person person : people) {
                        System.out.println(person.getInfo());
                    }
                    break;

                case 2:
                    System.out.print("Nhập tên cần tìm: ");
                    String searchName = sc.nextLine();
                    boolean found = false;
                    for (Person person : people) {
                        if (person.getName().equalsIgnoreCase(searchName)) {
                            System.out.println(person.getInfo());
                            found = true;
                        }
                    }
                    if (!found) {
                        System.out.println("Không tìm thấy nhân viên với tên: " + searchName);
                    }
                    break;

                case 3:
                    System.out.print("Nhập phòng ban: ");
                    String department = sc.nextLine();
                    for (Person person : people) {
                        if (person instanceof Employee && 
                            ((Employee) person).getDepartment().equalsIgnoreCase(department)) {
                            System.out.println(person.getInfo());
                        }
                    }
                    break;

                case 4:
                    Collections.sort(people, Comparator.comparing(Person::getName));
                    System.out.println("Danh sách sau khi sắp xếp:");
                    for (Person person : people) {
                        System.out.println(person.getInfo());
                    }
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

