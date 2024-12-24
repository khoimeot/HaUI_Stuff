/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package OnThi;

/**
 *
 * @author Admin
 */
public class GiangVien extends CanBoNV{
    private String hoHamHocVi;
    private String khoaCongTac;
    private int soGioDay;
    private int luongBoSung;

    public GiangVien() {
    }

    public GiangVien(String hoHamHocVi, String khoaCongTac, int soGioDay, int luongBoSung) {
        this.hoHamHocVi = hoHamHocVi;
        this.khoaCongTac = khoaCongTac;
        this.soGioDay = soGioDay;
        this.luongBoSung = luongBoSung;
    }

    public GiangVien(String hoHamHocVi, String khoaCongTac, int soGioDay, String maCBNV, String hoTen, int namTuyenDung, float heSoLuong, float heSoPhuCap) {
        super(maCBNV, hoTen, namTuyenDung, heSoLuong, heSoPhuCap);
        this.hoHamHocVi = hoHamHocVi;
        this.khoaCongTac = khoaCongTac;
        this.soGioDay = soGioDay;
        switch(hoHamHocVi){
            case "TS":
                this.luongBoSung = 700000;
                break;
            case "PGS":
                this.luongBoSung = 9000000;
                break;
            case "GS":
                this.luongBoSung = 12000000;
                break;
            default:
                this.luongBoSung = 0;
        }
    }

    public String getHoHamHocVi() {
        return hoHamHocVi;
    }

    public void setHoHamHocVi(String hoHamHocVi) {
        this.hoHamHocVi = hoHamHocVi;
    }

    public String getKhoaCongTac() {
        return khoaCongTac;
    }

    public void setKhoaCongTac(String khoaCongTac) {
        this.khoaCongTac = khoaCongTac;
    }

    public int getSoGioDay() {
        return soGioDay;
    }

    public void setSoGioDay(int soGioDay) {
        this.soGioDay = soGioDay;
    }

    public int getLuongBoSung() {
        return luongBoSung;
    }

    public void setLuongBoSung(int luongBoSung) {
        this.luongBoSung = luongBoSung;
    }
    
    
    
    @Override
    public double getSalary(){
        return (getHeSoLuong() + super.getHeSoPhuCap())*2340000*1.25 + soGioDay*200000 + luongBoSung;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("GiangVien{");
        sb.append(super.toString()).append("\n");
        sb.append("hoHamHocVi=").append(hoHamHocVi);
        sb.append(", khoaCongTac=").append(khoaCongTac);
        sb.append(", soGioDay=").append(soGioDay);
        sb.append(", luongBoSung=").append(luongBoSung);
        sb.append('}');
        return sb.toString();
    }
    
    
}
