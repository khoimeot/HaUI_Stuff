/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OnThi;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Admin
 */
public class QLGiangVien implements IGiangVien{
    private ArrayList<GiangVien> ds = new ArrayList<>();
    private String[] VALID_HOC_HAM_HOC_VI  = {"GS","PGS","TS"};
    
    @Override
    public void addGiangVien(GiangVien gv) {
        try {
            if (gv.getHoTen() == null || gv.getHoTen().isEmpty()) {
                throw new IllegalArgumentException("Ho ten khong duoc de trong.");
            }
            if(gv.getMaCBNV() == null || gv.getMaCBNV().isEmpty()){
                throw new IllegalArgumentException("ma can bo giao vien khong hop le");
            }
            if(gv.getKhoaCongTac()== null || gv.getKhoaCongTac().isEmpty()){
                throw new IllegalArgumentException("khoa cong tac khong hop le");
            }
            if(gv.getSoGioDay() < 0 || gv.getLuongBoSung() < 0){
                throw new IllegalArgumentException("Số giờ dạy phải lớn hơn hoặc bằng 0.");
            }
            ds.add(gv);
                System.out.println("Giang vien da duoc them");
        } catch (IllegalArgumentException e) {
            System.out.println("Loi: " + e.getMessage());
        }
    }
    
    @Override
    public void editGiangVien(GiangVien gv){
        try {
            GiangVien newgv = searchGiangVien(gv.getMaCBNV());
            if(newgv == null){
                throw new IllegalArgumentException("khong co giang vien nao trong danh sach");
            }
            if (gv.getHoTen() == null || gv.getHoTen().isEmpty()) {
                throw new IllegalArgumentException("Ho ten khong duoc de trong.");
            }
            if(gv.getMaCBNV() == null || gv.getMaCBNV().isEmpty()){
                throw new IllegalArgumentException("ma can bo giao vien khong hop le");
            }
            if(gv.getKhoaCongTac()== null || gv.getKhoaCongTac().isEmpty()){
                throw new IllegalArgumentException("khoa cong tac khong hop le");
            }
            if(gv.getSoGioDay() < 0 || gv.getLuongBoSung() < 0){
                throw new IllegalArgumentException("Số giờ dạy phải lớn hơn hoặc bằng 0.");
            }
            for (int i = 0; i < ds.size(); i++) {
                if(ds.get(i).getMaCBNV().equals(gv.getMaCBNV())){    
                       ds.set(i, gv);
                       System.out.println("Sua thanh cong");
                       break;
                }
            }
        } catch (IllegalArgumentException  e) {
            System.out.println("Loi: " + e.getMessage());        
        }
    }
    
    @Override
    public GiangVien searchGiangVien(String magv){
        try {
            for (int i = 0; i < ds.size(); i++) {
                if(ds.get(i).getMaCBNV().equals(magv)){   
                    return ds.get(i);
                }
            }
            
            throw new IllegalArgumentException("khong ton tai giang vien trong danh sach");
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Loi: " + e.getMessage());    
            return null;
        }
    }
    
    public boolean check(String hohHam){
        for (String hh : VALID_HOC_HAM_HOC_VI) {
            if(hh.equals(hohHam)){
                return true;
            }
        }
        return false;
    }
    
    @Override
    public double getTotalSalary(String hocHamHocVi){
        try {
            if(!check(hocHamHocVi)){
                throw new IllegalArgumentException("Hoc Ham khong hop le");
            }
            double tong = 0;
            for (GiangVien d : ds) {
                tong += d.getSalary();
            }
            return tong;
        } catch (IllegalArgumentException e) {
            System.out.println("Loi: " + e.getMessage());    
            return 0;
        }
    }
    
    public void nhap(){
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Nhap ma CBGV: ");
        String maCBNV = sc.nextLine();
        System.out.print("Nhap ho ten: ");
        String hoTen = sc.nextLine();
        int namTuyenDung = getPositiveInt("Nam tuyen dung: ");
//        System.out.print("He so luong: ");
        float heSoLuong = getPositiveFloat("He so luong: ");
//        System.out.print("He so phu cap: ");
        float heSoPhuCap = getPositiveFloat("He so phu cap: ");
        sc.nextLine();
        System.out.print("Nhap hoc ham hoc vi TS/PGS/GS: ");
        String hoHamHocVi = sc.nextLine();
        System.out.print("Nhap khoa cong tac: ");
        String khoaCongTac = sc.nextLine();
//        System.out.print("so gio day: ");
        int soGioDay = getPositiveInt("so gio day: ");
        sc.nextLine();
        GiangVien newgv = new GiangVien(hoHamHocVi, khoaCongTac, soGioDay, maCBNV, hoTen, namTuyenDung, heSoLuong, heSoPhuCap);
        addGiangVien(newgv);
    }
    
    private int getPositiveInt(String message) {
        Scanner sc = new Scanner(System.in);
        int value = -1;
        while(value < 0) {
            System.out.print(message);
            value = sc.nextInt();
            if(value < 0) {
                System.out.println("Gia tri khong the nho hon 0, vui long nhap lai.");
            }
        }
        return value;
    }

    // Phương thức kiểm tra và nhận giá trị kiểu float không bé hơn 0
    private float getPositiveFloat(String message) {
        Scanner sc = new Scanner(System.in);
        float value = -1;
        while(value < 0) {
            System.out.print(message);
            value = sc.nextFloat();
            if(value < 0) {
                System.out.println("Gia tri khong the nho hon 0, vui long nhap lai.");
            }
        }
        return value;
    }
    
    public void inDL(){
        if(!ds.isEmpty()){
            for (GiangVien d : ds) {
                System.out.println(d);
            }
        }
        else
            System.out.println("Danh sach rong");
    }
}
