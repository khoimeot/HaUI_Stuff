/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de3;

/**
 *
 * @author PC
 */
public class FullTimeEmployee extends Employee {
    public FullTimeEmployee() {}

    public FullTimeEmployee(String name, int paymentPerHour) {
        super(name, paymentPerHour);
    }

    @Override
    public int calculateSalary() {
        return 8 * paymentPerHour; // Tính lương theo 8 giờ làm việc
    }

    @Override
    public void displayData() {
        super.displayData();
        System.out.println("Lương: " + calculateSalary());
    }
}