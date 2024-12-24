/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de4;

/**
 *
 * @author PC
 */
public class Employee extends Person {
    private String department; // Phòng ban làm việc

    public Employee() {}

    public Employee(String name, int age, String department) {
        super(name, age);
        this.department = department;
    }

    public String getDepartment() {
        return department;
    }

    public void setDepartment(String department) {
        this.department = department;
    }

    @Override
    public String getInfo() {
        return "Employee [Name: " + name + ", Age: " + age + ", Department: " + department + "]";
    }
}