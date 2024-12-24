/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de5;

/**
 *
 * @author PC
 */
// Lớp trừu tượng Product
public abstract class Product {
    protected int productId;         // ID sản phẩm
    protected String productName;    // Tên sản phẩm
    protected double productPrice;   // Giá sản phẩm
    protected int productTotal;      // Số lượng sản phẩm

    public Product() {}

    public Product(int productId, String productName, double productPrice, int productTotal) {
        this.productId = productId;
        this.productName = productName;
        this.productPrice = productPrice;
        this.productTotal = productTotal;
    }

    // Getter và Setter
    public int getProductId() {
        return productId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public String getProductName() {
        return productName;
    }

    public void setProductName(String productName) {
        this.productName = productName;
    }

    public double getProductPrice() {
        return productPrice;
    }

    public void setProductPrice(double productPrice) {
        this.productPrice = productPrice;
    }

    public int getProductTotal() {
        return productTotal;
    }

    public void setProductTotal(int productTotal) {
        this.productTotal = productTotal;
    }

    // Phương thức tính tổng giá trị sản phẩm
    public double getTotalPrice() {
        return productPrice * productTotal;
    }

    // Phương thức xuất thông tin sản phẩm
    @Override
    public String toString() {
        return "Product [ID: " + productId + ", Name: " + productName + 
               ", Price: " + productPrice + ", Total: " + productTotal + "]";
    }
}
