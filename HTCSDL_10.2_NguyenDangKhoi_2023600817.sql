--1. Hiển thị tên, địa chỉ và điện thoại của tất cả các giáo viên. Kết quả như sau:

SELECT TEN, DIA_CHI, DIEN_THOAI FROM GIAO_VIEN

--2. Hiển thị tên lớp, ngày bắt đầu, địa điểm và số sinh viên của các lớp học ở địa điểm ‘L210’. Kết quả như sau:

SELECT        TEN_LOP, NGAY_BAT_DAU, SO_SV, DIA_DIEM
FROM            LOP
WHERE        (DIA_DIEM = 'L210')

--3. Hiển thị mô tả và học phí các môn học sắp xếp theo mô tả môn học. Kết quả như sau:

SELECT        MO_TA, HOC_PHI
FROM            MON_HOC
ORDER BY MO_TA

-- 4. Hiển thị ghép tên và địa chỉ các giáo viên ở vùng có mã số ‘02155’ trong một cột với tiêu đề là [Giáo viên ở Cầu Giấy]. Kết quả như sau:
SELECT        CONCAT(GIAO_VIEN.TEN,' ', GIAO_VIEN.DIA_CHI) AS Giao_Vien_O_Cau_Giay
FROM            GIAO_VIEN INNER JOIN
                         VUNG ON GIAO_VIEN.MA_SO = VUNG.MA_SO
WHERE        (VUNG.MA_SO = '02155')

-- 5. Hiển thị ghép họ và tên giáo viên vào một cột có tiêu đề là [Giáo viên] trong đó tên giáo viên được viết in hoa với các giáo viên họ ‘Nguyen’ và ‘Dang’. Kết quả như sau:
SELECT      CONCAT(HO,' ',
	CASE 
		WHEN HO LIKE 'Nguyen%' OR HO LIKE 'Dang%' THEN UPPER(TEN)
		ELSE TEN
	END) AS GIAO_VIEN
FROM            GIAO_VIEN
WHERE HO LIKE 'Nguyen%' OR HO LIKE 'Dang%' 

--6. Hiển thị mã môn học và mô tả các môn học không có môn điều kiện (môn điều kiện là Null). Kết quả như sau
	SELECT        MA_MH, MO_TA
FROM            MON_HOC
WHERE        (MON_DIEU_KIEN IS NULL)

-- 7. Hiển thị học phí lớn nhất, học phí nhỏ nhất và học phí trung bình của tất cả các môn học, số môn học và tổng học phí của các môn học. Kết quả như sau :

SELECT  MAX(HOC_PHI) AS Hoc_Phi_Lon_Nhat , MIN(HOC_PHI)AS Hoc_Phi_Nho_Nhat, AVG(HOC_PHI) AS Hoc_Phi_Trung_Binh,COUNT(HOC_PHI) + 1 AS So_Mon_Hoc, SUM(HOC_PHI)AS Tong_Hoc_Phi
FROM            MON_HOC

--8. Đưa ra mã số vùng và số giáo viên ở trong vùng đó.

SELECT        VUNG.MA_SO , COUNT(*) AS SoLuongGiaoVien
FROM            GIAO_VIEN INNER JOIN
                         VUNG ON GIAO_VIEN.MA_SO = VUNG.MA_SO
GROUP BY VUNG.MA_SO

--9. Đưa ra mã giáo viên và số lớp mà giáo viên đó giảng dạy sắp xếp theo thứ tự giảm dần của số lớp
SELECT        GIAO_VIEN.MA_GV , COUNT(*) AS SoLop
FROM            LOP INNER JOIN
                         GIAO_VIEN ON LOP.MA_GV = GIAO_VIEN.MA_GV
GROUP BY GIAO_VIEN.MA_GV
ORDER BY SoLop DESC

--10. Đưa ra tên tỉnh và số huyện thuộc các tỉnh có tên bắt đầu là chữ ‘H

SELECT       TINH , COUNT(*) AS SOHUYEN
FROM            VUNG
WHERE TINH LIKE 'H%'
GROUP BY TINH

--	11. Lấy tên các huyện không ở ‘Ha Noi’

SELECT        HUYEN
FROM            VUNG
WHERE        (TINH != 'Ha Noi')

-- 12. Hiển thị mã, mô tả và học phí của các môn học có học phí trong khoảng từ 1000 đến 1500

SELECT        MA_MH, MO_TA, HOC_PHI
FROM            MON_HOC
WHERE        (HOC_PHI > 1000 AND HOC_PHI < 1500)

--13. Hiển thị họ và tên sinh viên không có số điện thoại (Dien_thoai is null)
	SELECT        HO, TEN
FROM            SINH_VIEN
WHERE        (DIEN_THOAI IS NULL)


--14. Đưa ra mã và tên lớp học môn học có mã môn học là 25 hoặc giáo viên có mã là 103 giảng dạy và có số sinh viên từ 20 trở lên
SELECT        MON_HOC.MA_MH, MON_HOC.MO_TA , GIAO_VIEN.MA_GV
FROM            MON_HOC CROSS JOIN
                         GIAO_VIEN CROSS JOIN
						 LOP
WHERE        (MON_HOC.MA_MH = 25) AND (GIAO_VIEN.MA_GV = 103) AND(LOP.SO_SV > 20)

-- 15. Đưa ra họ, tên, địa chỉ và cơ quan của các sinh viên làm việc tại ‘Viettel’, ‘Vien chien luoc’ hoặc ‘Ngan hang Dong A
SELECT        SINH_VIEN.HO, SINH_VIEN.TEN, SINH_VIEN.DIA_CHI, SINH_VIEN.CO_QUAN
FROM            SINH_VIEN INNER JOIN
                         DANG_KY ON SINH_VIEN.MA_SV = DANG_KY.MA_SV
WHERE        (SINH_VIEN.CO_QUAN = 'Viettel') OR
                         (SINH_VIEN.CO_QUAN = 'Vien chien luoc') OR
                         (SINH_VIEN.CO_QUAN = 'Ngan hang Dong A')

-- 16. Cho biết số sinh viên làm ở ‘Vien cong nghe’ và ‘Viettel’
SELECT        CO_QUAN , COUNT(*) AS SoSV
FROM            SINH_VIEN
WHERE        (CO_QUAN = 'Vien cong nghe') OR (CO_QUAN = 'Viettel')
GROUP BY CO_QUAN

--17. Đưa ra số sinh viên trung bình của tất cả các lớp học môn có mã là 25
SELECT        LOP.MA_MH, AVG(LOP.SO_SV) AS SOSV
FROM            LOP CROSS JOIN
                         SINH_VIEN
WHERE        (LOP.MA_MH = 25)
GROUP BY	LOP.MA_MH

-- 18. Đưa ra số lớp, sĩ số lớn nhất, sĩ số nhỏ nhất và sĩ số trung bình của các lớp

SELECT        COUNT(SO_SV) AS SoLop ,MAX(SO_SV) AS SiSoLonNhat , MIN(SO_SV)AS SiSoNhoNhat, AVG(SO_SV) AS SiSoTrungBinh
FROM            LOP

--19. Đếm xem có bao nhiêu mức học phí khác nhau và tính học phí trung bình của các môn học (dùng với DISTINCT)
SELECT       COUNT(DISTINCT(HOC_PHI)) AS SLHOCPHI , AVG(HOC_PHI) AS TBHOCPHI
FROM            MON_HOC

-- 20. Hiển thị ghép họ và tên sinh viên trong một cột với tiêu đề là “Họ và tên”, địa chỉ và mã số vùng của các sinh viên họ ‘Nguyen’
SELECT        CONCAT(SINH_VIEN.HO,' ', SINH_VIEN.TEN) AS HOVATEN, SINH_VIEN.DIA_CHI, VUNG.MA_SO
FROM            SINH_VIEN INNER JOIN
                         VUNG ON SINH_VIEN.MA_SO = VUNG.MA_SO
WHERE SINH_VIEN.HO LIKE 'Nguyen%'