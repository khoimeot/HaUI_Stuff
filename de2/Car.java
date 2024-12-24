/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de2;

/**
 *
 * @author PC
 */
public class Car extends Product {
    private String color;
    private double weight;

    // Constructor không tham số
    public Car() {
        super();
    }

    // Constructor có tham số
    public Car(int proid, String name, int quantity, double price, String color, double weight) {
        super(proid, name, quantity, price);
        this.color = color;
        this.weight = weight;
    }

    // Getter và Setter
    public String getColor() { return color; }
    public void setColor(String color) { this.color = color; }

    public double getWeight() { return weight; }
    public void setWeight(double weight) { this.weight = weight; }

    // Cài đặt phương thức discount
    @Override
    public double discount() {
        return getQuantity() >= 10 ? 0.1 * getPrice() : 0;
    }

    // Phương thức toString
    @Override
    public String toString() {
        return super.toString() + 
               ", Car{" +
               "color='" + color + '\'' +
               ", weight=" + weight +
               '}';
    }
}
