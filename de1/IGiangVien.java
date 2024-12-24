/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package OnThi;

/**
 *
 * @author Admin
 */
public interface IGiangVien {
    void addGiangVien(GiangVien gv);
    void editGiangVien(GiangVien gv);
    GiangVien searchGiangVien(String magv);
    double getTotalSalary(String hocHamHocVi);
}
