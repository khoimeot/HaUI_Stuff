/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb9;

/**
 *
 * @author PC
 */
class CongNhan extends CanBo {
    private int bac;

    @Override
    public void nhap() {
        super.nhap();
        java.util.Scanner sc = new java.util.Scanner(System.in);
        System.out.print("Nhap bac: ");
        bac = sc.nextInt();
    }

    @Override
    public String toString() {
        return super.toString() + ", Bac: " + bac;
    }
}