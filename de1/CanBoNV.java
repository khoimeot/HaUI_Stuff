/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OnThi;

/**
 *
 * @author Admin
 */
abstract class CanBoNV {
    private String maCBNV;
    private String hoTen;
    private int namTuyenDung;
    private float heSoLuong;
    private float heSoPhuCap;
    public abstract double getSalary();

    public CanBoNV() {
    }

    public CanBoNV(String maCBNV, String hoTen, int namTuyenDung, float heSoLuong, float heSoPhuCap) {
        this.maCBNV = maCBNV;
        this.hoTen = hoTen;
        this.namTuyenDung = namTuyenDung;
        this.heSoLuong = heSoLuong;
        this.heSoPhuCap = heSoPhuCap;
    }

    public String getMaCBNV() {
        return maCBNV;
    }

    public void setMaCBNV(String maCBNV) {
        this.maCBNV = maCBNV;
    }

    public String getHoTen() {
        return hoTen;
    }

    public void setHoTen(String hoTen) {
        this.hoTen = hoTen;
    }

    public int getNamTuyenDung() {
        return namTuyenDung;
    }

    public void setNamTuyenDung(int namTuyenDung) {
        this.namTuyenDung = namTuyenDung;
    }

    public float getHeSoLuong() {
        return heSoLuong;
    }

    public void setHeSoLuong(float heSoLuong) {
        this.heSoLuong = heSoLuong;
    }

    public float getHeSoPhuCap() {
        return heSoPhuCap;
    }

    public void setHeSoPhuCap(float heSoPhuCap) {
        this.heSoPhuCap = heSoPhuCap;
    }

    @Override
    public String toString() {
        return "\n" + "maCBNV=" + maCBNV + ", hoTen=" + hoTen + ", namTuyenDung=" + namTuyenDung + ", heSoLuong=" + heSoLuong + ", heSoPhuCap=" + heSoPhuCap ;
    }
    
    
}
