/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de2;

/**
 *
 * @author PC
 */
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class CarManager implements ICarManager {
    List<Car> cars = new ArrayList<>();

    @Override
    public void addCar(Car e) {
        cars.add(e);
    }

    @Override
    public void updateCar(Car e) {
        for (int i = 0; i < cars.size(); i++) {
            if (cars.get(i).getProid() == e.getProid()) {
                cars.set(i, e);
                return;
            }
        }
    }

    @Override
    public Car searchCarByID(int proid) {
    try {
        for (Car car : cars) {
            if (car.getProid() == proid) {
                return car;
            }
        }
        throw new Exception("Car with ID " + proid + " not found.");
    } catch (Exception e) {
        System.err.println(e.getMessage());
        return null;
        }
    }


    @Override
    public List<Car> searchCarByColor(String color) {
        List<Car> result = new ArrayList<>();
        for (Car car : cars) {
            if (car.getColor().equalsIgnoreCase(color)) {
                result.add(car);
            }
        }
        return result;
    }

    @Override
    public double getTotalPrice() {
        double total = 0;
        for (Car car : cars) {
            total += car.getPrice();
        }
        return total;
    }

    @Override
    public void sortByPrice() {
        cars.sort(Comparator.comparingDouble(Car::getPrice).reversed());
    }

    @Override
    public void sortByID() {
        cars.sort(Comparator.comparingInt(Car::getProid));
    }
}
