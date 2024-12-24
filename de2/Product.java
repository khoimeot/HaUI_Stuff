/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de2;

/**
 *
 * @author PC
 */
public abstract class Product {
    private int proid;
    private String name;
    private int quantity;
    private double price;

    // Constructor không tham số
    public Product() {}

    // Constructor có tham số
    public Product(int proid, String name, int quantity, double price) {
        this.proid = proid;
        this.name = name;
        this.quantity = quantity;
        this.price = price;
    }

    // Getter và Setter
    public int getProid() { return proid; }
    public void setProid(int proid) { this.proid = proid; }

    public String getName() { return name; }
    public void setName(String name) { this.name = name; }

    public int getQuantity() { return quantity; }
    public void setQuantity(int quantity) { this.quantity = quantity; }

    public double getPrice() { return price; }
    public void setPrice(double price) { this.price = price; }

    // Phương thức trừu tượng
    public abstract double discount();

    // Phương thức toString
    @Override
    public String toString() {
        return "Product{" +
               "proid=" + proid +
               ", name='" + name + '\'' +
               ", quantity=" + quantity +
               ", price=" + price +
               '}';
    }
}
