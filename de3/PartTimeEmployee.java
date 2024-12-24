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
public class PartTimeEmployee extends Employee {
    private int workingHours;

    public PartTimeEmployee() {}

    public PartTimeEmployee(String name, int paymentPerHour, int workingHours) {
        super(name, paymentPerHour);
        this.workingHours = workingHours;
    }

    public int getWorkingHours() {
        return workingHours;
    }

    public void setWorkingHours(int workingHours) {
        this.workingHours = workingHours;
    }

    @Override
    public int calculateSalary() {
        return paymentPerHour * workingHours;
    }

    @Override
    public void inputData() {
        super.inputData();
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhập số giờ làm việc: ");
        workingHours = sc.nextInt();
    }

    @Override
    public void displayData() {
        super.displayData();
        System.out.println("Số giờ làm việc: " + workingHours);
        System.out.println("Lương: " + calculateSalary());
    }
}