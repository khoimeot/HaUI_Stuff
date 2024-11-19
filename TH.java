
package com.mycompany.th;
import javax.swing.JOptionPane;
/**
 *
 * @author IT SUPPORTER
 */

public class TH {
    public static void main(String[] args) {
        NgayThang ngaySinh = new NgayThang(7,24,1991);
        NgayThang ngayVaoLam = new NgayThang(3,12,1998);
        NhanVien nv = new NhanVien("Vu thi " , "Lan anh" , ngaySinh , ngayVaoLam);
        JOptionPane.showMessageDialog(null , nv.toString() , "minh hoa lop Employee" , JOptionPane.INFORMATION_MESSAGE);
        System.exit(0);
        
    }
}
