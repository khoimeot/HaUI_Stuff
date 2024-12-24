
package com.mycompany.otb4;

public class Projector {
    private String brand;
    private String model;
    private int brightness;
    private int resolution;
    private double price;

    public Projector(String brand, String model, int brightness, int resolution, double price) {
        this.brand = brand;
        this.model = model;
        this.brightness = brightness;
        this.resolution = resolution;
        this.price = price;
    }

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public int getBrightness() {
        return brightness;
    }

    public void setBrightness(int brightness) {
        this.brightness = brightness;
    }

    public int getResolution() {
        return resolution;
    }

    public void setResolution(int resolution) {
        this.resolution = resolution;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    @Override
    public String toString() {
        return "Projector{" + "brand=" + brand + ", model=" + model + ", brightness=" + brightness + ", resolution=" + resolution + ", price=" + price + '}';
    }
    
    
}
public class OTb4 {

    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
