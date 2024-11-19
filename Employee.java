
package com.mycompany.main;
/*
 *
 * @author IT SUPPORTER
 */
public class NhanVien {
    // Thuộc tính
    private String maNV;
    private int soSP;

    // Hằng số
    private static final int DON_GIA = 20000;
    private static final int DON_GIA_VUOT_CHUAN = 30000;
    private static final int MUC_CHUAN = 500;

    // Phương thức khởi dựng không đối
    public NhanVien() {
        this.maNV = "";
        this.soSP = 0;
    }

    // Phương thức khởi dựng có đối
    public NhanVien(String ma, int sp) {
        this.maNV = ma;
        setSoSP(sp); // Gọi setSoSP để kiểm tra hợp lệ cho số sản phẩm
    }

    // Getter và Setter
    public String getMaNV() {
        return maNV;
    }

    public void setMaNV(String ma) {
        this.maNV = ma;
    }

    public int getSoSP() {
        return soSP;
    }

    public void setSoSP(int sp) {
        if (sp > 0) {
            this.soSP = sp;
        } else {
            System.out.println("Số sản phẩm phải lớn hơn 0");
        }
    }

    // Phương thức kiểm tra vượt chuẩn
    public boolean coVuotChuan() {
        return soSP > MUC_CHUAN;
    }

    // Phương thức tổng kết
    public String getTongKet() {
        return coVuotChuan() ? "Vượt" : "";
    }

    // Phương thức lấy lương
    public double getLuong() {
        if (coVuotChuan()) {
            int soSPVuot = soSP - MUC_CHUAN;
            return MUC_CHUAN * DON_GIA + soSPVuot * DON_GIA_VUOT_CHUAN;
        } else {
            return soSP * DON_GIA;
        }
    }

    // Phương thức xuất tiêu đề
    public static void xuatTieuDe() {
        System.out.printf("%-10s %-15s %-15s %-10s%n", "Mã NV", "Số SP", "Lương", "Tổng Kết");
    }

    // Phương thức in dữ liệu của đối tượng
    public void inDL() {
        System.out.printf("%-10s %-15d %-15.2f %-10s%n", maNV, soSP, getLuong(), getTongKet());
    }

    // Phương thức toString
    @Override
    public String toString() {
        return String.format("Mã NV: %s, Số SP: %d, Lương: %.2f, Tổng Kết: %s", maNV, soSP, getLuong(), getTongKet());
    }
}
