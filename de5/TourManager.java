/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.de5;

/**
 *
 * @author PC
 */
import java.util.List;

public interface TourManager {
    void addTour(Tour tour);    // Thêm tour
    void delTour(Tour tour);    // Xóa tour
    Tour searchTour(String name);  // Tìm kiếm tour theo tên
    List<Tour> sortedTour();    // Sắp xếp danh sách tour
    double getTotalStorage();   // Tính tổng giá trị tồn kho
}
