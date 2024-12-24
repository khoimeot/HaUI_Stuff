/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de3;
import java.util.Scanner;
/**
 *
 * @author PC
 */
public abstract class Employee implements IEmployee {
    protected String name;
    protected int paymentPerHour;

    public Employee() {}

    public Employee(String name, int paymentPerHour) {
        this.name = name;
        this.paymentPerHour = paymentPerHour;
    }

    // Getter và Setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPaymentPerHour() {
        return paymentPerHour;
    }

    public void setPaymentPerHour(int paymentPerHour) {
        this.paymentPerHour = paymentPerHour;
    }

    @Override
    public void inputData() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập tên nhân viên: ");
        name = sc.nextLine();
        System.out.print("Nhập lương trên giờ: ");
        paymentPerHour = sc.nextInt();
    }

    @Override
    public void displayData() {
        System.out.println("Tên: " + name);
        System.out.println("Lương trên giờ: " + paymentPerHour);
    }

    // Phương thức trừu tượng tính lương
    public abstract int calculateSalary();
}