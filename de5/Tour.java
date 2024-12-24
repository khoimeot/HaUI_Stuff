/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de5;

/**
 *
 * @author PC
 */
// Lớp Tour kế thừa từ Product
public class Tour extends Product {
    private int tourNumberDays;     // Số ngày đi tour
    private String tourTransport;  // Phương tiện di chuyển

    public Tour() {}

    public Tour(int productId, String productName, double productPrice, int productTotal,
                int tourNumberDays, String tourTransport) {
        super(productId, productName, productPrice, productTotal);
        this.tourNumberDays = tourNumberDays;
        this.tourTransport = tourTransport;
    }

    public int getTourNumberDays() {
        return tourNumberDays;
    }

    public void setTourNumberDays(int tourNumberDays) {
        this.tourNumberDays = tourNumberDays;
    }

    public String getTourTransport() {
        return tourTransport;
    }

    public void setTourTransport(String tourTransport) {
        this.tourTransport = tourTransport;
    }

    // Tính tổng giá trị tour (bao gồm 10% phí dịch vụ)
    @Override
    public double getTotalPrice() {
        return super.getTotalPrice() + 0.1 * super.getTotalPrice();
    }

    @Override
    public String toString() {
        return super.toString() + ", Days: " + tourNumberDays + 
               ", Transport: " + tourTransport + 
               ", Total Price (with service fee): " + getTotalPrice();
    }
}
