/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.th;

/**
 *
 * @author IT SUPPORTER
 */
public class NgayThang {
    private int ngay;
    private int thang;
    private int nam;
    
    public NgayThang(int thang1 , int ngay1 , int nam1) {
        if ( thang1 > 0 && thang1 <= 12) {
            this.thang = thang1;
        }
        else {
            this.thang = 1;
            System.out.println("Thang " +thang1 + "khong hop le , dat lai thang 1" );
            
        }
        if ( nam1 <= 2024 && nam1 > 1950){
            nam = nam1;
        }
        
        ngay = checkDay(ngay1);
        System.out.println("in thong tin ngay thang " + toString());
    }
    public final int checkDay(int ngayKiemTra) {
        int ngayTrongThang[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(ngayKiemTra > 0 && ngayKiemTra < ngayTrongThang[thang]) {
            return ngayKiemTra;
        }
        else {
            if (((thang == 2) && (ngayKiemTra == 29)) && ((nam % 400 == 0 ) || ((nam % 4 == 0) &&(nam % 100 !=0)))) {
                return ngayKiemTra;
            }
            else {
                System.out.println("Ngay khong hop le , dat lai thanh 1");
                return 1;
            }
        }
    }
    
    @Override
    public final String toString() {
        return thang +"/" +ngay +"/"+nam ;
    }
}
