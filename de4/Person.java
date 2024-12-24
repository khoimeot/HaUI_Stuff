/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de4;

/**
 *
 * @author PC
 */
// Lớp trừu tượng Person
public abstract class Person {
    protected String name;
    protected int age;

    public Person() {}

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Getter và Setter
    public String getName() {
        return name;
    }

    public void setName(String name) {
    if (name == null || name.trim().isEmpty()) {
        throw new IllegalArgumentException("Tên không được để trống!");
    }
    this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
    if (age <= 0) {
        throw new IllegalArgumentException("Tuổi phải lớn hơn 0!");
    }
    this.age = age;
    }

    // Phương thức trừu tượng
    public abstract String getInfo();
}
