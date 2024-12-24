
/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Other/File.java to edit this template
 */
package com.mycompany.otb6;
import java.util.Random;

/**
 *
 * @author PC
 */


public class OTb6 {
    public static class HinhChuNhat {
        private float dai;
        private float rong;
        public void nhap() {
            Random random = new Random();
            dai = random.nextFloat() * 10;
            rong = random.nextFloat() + 10;
        }

        public float Tinhdientich() {
            return dai*rong;
        }

        public float Tinhchuvi() {
            return (dai+rong) *2;
        }

        public static void inTieuDe() {
            System.out.printf("%15s%15s%15s%15s%n", "Chieu dai" , "Chieu rong " , "Chu vi" , "Dien tich");
        }

        public void InKQ() {
             System.out.printf("%15s%15s%15s%15s%n", dai , rong , Tinhchuvi(), Tinhdientich());
        }
    }
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        HinhChuNhat hcn = new HinhChuNhat();
        hcn.nhap();
        HinhChuNhat.inTieuDe();
        hcn.InKQ();
    }
}
