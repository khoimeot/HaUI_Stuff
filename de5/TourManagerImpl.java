/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de5;

/**
 *
 * @author PC
 */
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class TourManagerImpl implements TourManager {
    private List<Tour> tours;

    public TourManagerImpl() {
        this.tours = new ArrayList<>();
    }

    @Override
    public void addTour(Tour tour) {
        tours.add(tour);
    }

    @Override
    public void delTour(Tour tour) {
        tours.remove(tour);
    }

    @Override
    public Tour searchTour(String name) {
        for (Tour tour : tours) {
            if (tour.getProductName().equalsIgnoreCase(name)) {
                return tour;
            }
        }
        return null;
    }

    @Override
    public List<Tour> sortedTour() {
        Collections.sort(tours, Comparator.comparing(Tour::getProductName));
        return tours;
    }

    @Override
    public double getTotalStorage() {
        double total = 0;
        for (Tour tour : tours) {
            total += tour.getTotalPrice();
        }
        return total;
    }

    public void displayAllTours() {
        for (Tour tour : tours) {
            System.out.println(tour);
        }
    }
}
