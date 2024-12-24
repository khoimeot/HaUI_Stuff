/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de2;

/**
 *
 * @author PC
 */
import java.util.List;

public interface ICarManager {
    void addCar(Car e);
    void updateCar(Car e);
    Car searchCarByID(int proid);
    List<Car> searchCarByColor(String color);
    double getTotalPrice();
    void sortByPrice();
    void sortByID();
}
