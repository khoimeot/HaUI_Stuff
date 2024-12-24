
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb6;
import java.util.Scanner;

/**
 *
 * @author PC
 */


public class OTB62 {
    public static class HinhTron {
        public float bankinh;
        public void nhap() {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Nhap ban kinh");
            bankinh = scanner.nextFloat();
        }
        
        public float tinhdientich() {
            return (float )Math.PI * bankinh*bankinh;
        }
        
        public float tinhchuvi() {
            return  2*(float )Math.PI*bankinh;
        }
        
        public void InTD() {
            System.out.printf("%15s%15s%15s%n","Ban Kinh" , "Chu vi" , "Dien tich");
        }
        
        public void xuat() {
            System.out.printf("%15s%15s%15s%n",bankinh , tinhchuvi() , tinhdientich());

        }
    }
    public static void main(String args[]) {
        HinhTron ht = new HinhTron();
        ht.nhap();
        ht.InTD();
        ht.xuat();
        
    }
}
