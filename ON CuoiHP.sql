CREATE DATABASE Karaoke_Management;
GO
USE Karaoke_Management;
GO


CREATE TABLE PHONG (
    MaPhong CHAR(5) PRIMARY KEY,
    LoaiPhong VARCHAR(10),
    SoKhachToiDa INT,
    GiaPhong INT,
    MoTa VARCHAR(50)
);

INSERT INTO PHONG VALUES
('P0001', 'Loai 1', 20, 60000, NULL),
('P0002', 'Loai 1', 25, 80000, NULL),
('P0003', 'Loai 2', 15, 50000, NULL),
('P0004', 'Loai 3', 20, 50000, NULL);


CREATE TABLE KHACH_HANG (
    MaKH CHAR(6) PRIMARY KEY,
    TenKH VARCHAR(50),
    DiaChi VARCHAR(50),
    SoDT CHAR(11)
);

INSERT INTO KHACH_HANG VALUES
('KH0001', 'Nguyen Van A', 'Hoa xuan', '11111111111'),
('KH0002', 'Nguyen Van B', 'Hoa hai', '11111111112'),
('KH0003', 'Phan Van C', 'Cam le', '11111111113'),
('KH0004', 'Phan Van B', 'Hoa xuan', '11111111114');


CREATE TABLE DICH_VU_DI_KEM (
    MaDV CHAR(5) PRIMARY KEY,
    TenDV VARCHAR(50),
    DonViTinh VARCHAR(10),
    DonGia INT
);

INSERT INTO DICH_VU_DI_KEM VALUES
('DV001', 'Beer', 'lon', 10000),
('DV002', 'Nuoc ngot', 'lon', 8000),
('DV003', 'Trai cay', 'dia', 35000),
('DV004', 'Khan uot', 'cai', 2000);


CREATE TABLE DAT_PHONG (
    MaDatPhong CHAR(7) PRIMARY KEY,
    MaPhong CHAR(5),
    MaKH CHAR(6),
    NgayDat DATE,
    GioBatDau TIME,
    GioKetThuc TIME,
    TienDatCoc INT,
    GhiChu VARCHAR(50),
    TrangThaiDat VARCHAR(10),
    FOREIGN KEY (MaPhong) REFERENCES PHONG(MaPhong),
    FOREIGN KEY (MaKH) REFERENCES KHACH_HANG(MaKH)
);

INSERT INTO DAT_PHONG VALUES
('DP0001', 'P0001', 'KH0002', '2018-03-26', '11:00', '13:30', 100000, 'Da dat', NULL),
('DP0002', 'P0002', 'KH0003', '2018-03-27', '17:15', '19:15', 50000, 'Da huy', NULL),
('DP0003', 'P0003', 'KH0004', '2018-03-26', '20:30', '22:15', 150000, 'Da dat', NULL),
('DP0004', 'P0002', 'KH0001', '2018-04-01', '19:30', '21:15', 200000, 'Da dat', NULL);


CREATE TABLE CHI_TIET_SU_DUNG_DV (
    MaDatPhong CHAR(7),
    MaDV CHAR(5),
    SoLuong INT,
    PRIMARY KEY (MaDatPhong, MaDV),
    FOREIGN KEY (MaDatPhong) REFERENCES DAT_PHONG(MaDatPhong),
    FOREIGN KEY (MaDV) REFERENCES DICH_VU_DI_KEM(MaDV)
);

INSERT INTO CHI_TIET_SU_DUNG_DV VALUES
('DP0001', 'DV001', 20),
('DP0001', 'DV002', 10),
('DP0002', 'DV003', 5),
('DP0003', 'DV004', 1),
('DP0004', 'DV002', 10);


-- Câu 1: Liệt kê MaDatPhong, MaDV, SoLuong của các dịch vụ có số lượng lớn hơn 3 và nhỏ hơn 10
SELECT MaDatPhong, MaDV, SoLuong
FROM CHI_TIET_SU_DUNG_DV
WHERE SoLuong > 3 AND SoLuong < 10;
--Câu 2: Cập nhật trường GiaPhong của bảng PHONG tăng thêm 10,000 VNĐ cho phòng có số khách tối đa lớn hơn 10

UPDATE PHONG
SET GiaPhong = GiaPhong + 10000
WHERE SoKhachToiDa > 10;


--Câu 3: Xóa tất cả các đơn đặt phòng có trạng thái "Da huy" trong bảng DAT_PHONG
DELETE FROM DAT_PHONG
WHERE TrangThaiDat = 'Da huy';
--Câu 4: Hiển thị TenKH có tên bắt đầu bằng “H”, “N”, “M” và độ dài tối đa là 20 ký tự
SELECT TenKH
FROM KHACH_HANG
WHERE (TenKH LIKE 'H%' OR TenKH LIKE 'N%' OR TenKH LIKE 'M%')
  AND LEN(TenKH) <= 20;
--Câu 5: Hiển thị TenKH, loại bỏ các tên trùng nhau (hai cách)

SELECT DISTINCT TenKH
FROM KHACH_HANG;
--Câu 6: Hiển thị MaDV, TenDV, DonViTinh, DonGia với điều kiện cho trước

SELECT MaDV, TenDV, DonViTinh, DonGia
FROM DICH_VU_DI_KEM
WHERE (DonViTinh = 'lon' AND DonGia > 10000)
   OR (DonViTinh = 'cai' AND DonGia < 5000);
--Câu 7: Hiển thị thông tin đặt phòng với năm đặt phòng là “2016” hoặc “2017” và giá phòng > 50,000 VNĐ/giờ

SELECT DP.MaDatPhong, P.MaPhong, P.LoaiPhong, P.SoKhachToiDa, P.GiaPhong, 
       KH.MaKH, KH.TenKH, KH.SoDT, DP.NgayDat, DP.GioBatDau, DP.GioKetThuc, 
       CSDV.MaDV AS MaDichVu, CSDV.SoLuong, DV.DonGia
FROM DAT_PHONG DP
JOIN PHONG P ON DP.MaPhong = P.MaPhong
JOIN KHACH_HANG KH ON DP.MaKH = KH.MaKH
JOIN CHI_TIET_SU_DUNG_DV CSDV ON DP.MaDatPhong = CSDV.MaDatPhong
JOIN DICH_VU_DI_KEM DV ON CSDV.MaDV = DV.MaDV
WHERE YEAR(DP.NgayDat) IN (2016, 2017) 
  AND P.GiaPhong > 50000;
-- Câu 8: Hiển thị thông tin đặt phòng và tính tổng tiền thanh toán

SELECT DP.MaDatPhong, P.MaPhong, P.LoaiPhong, P.GiaPhong, KH.TenKH, 
       DP.NgayDat,
       P.GiaPhong * DATEDIFF(HOUR, DP.GioBatDau, DP.GioKetThuc) AS TongTienHat,
       ISNULL(SUM(CSDV.SoLuong * DV.DonGia), 0) AS TongTienSuDungDichVu,
       (P.GiaPhong * DATEDIFF(HOUR, DP.GioBatDau, DP.GioKetThuc)) 
       + ISNULL(SUM(CSDV.SoLuong * DV.DonGia), 0) AS TongTienThanhToan
FROM DAT_PHONG DP
JOIN PHONG P ON DP.MaPhong = P.MaPhong
JOIN KHACH_HANG KH ON DP.MaKH = KH.MaKH
LEFT JOIN CHI_TIET_SU_DUNG_DV CSDV ON DP.MaDatPhong = CSDV.MaDatPhong
LEFT JOIN DICH_VU_DI_KEM DV ON CSDV.MaDV = DV.MaDV
GROUP BY DP.MaDatPhong, P.MaPhong, P.LoaiPhong, P.GiaPhong, KH.TenKH, DP.NgayDat, 
         DP.GioBatDau, DP.GioKetThuc;
-- Câu 9: Hiển thị thông tin khách hàng có địa chỉ “Hoa xuan” đã từng đặt phòng

SELECT DISTINCT KH.MaKH, KH.TenKH, KH.DiaChi, KH.SoDT
FROM KHACH_HANG KH
JOIN DAT_PHONG DP ON KH.MaKH = DP.MaKH
WHERE KH.DiaChi = 'Hoa xuan';
--Câu 10: Hiển thị thông tin phòng có số lần đặt lớn hơn 2 và trạng thái đặt là “Da dat”
SELECT P.MaPhong, P.LoaiPhong, P.SoKhachToiDa, P.GiaPhong, 
       COUNT(DP.MaDatPhong) AS SoLanDat
FROM PHONG P
JOIN DAT_PHONG DP ON P.MaPhong = DP.MaPhong
WHERE DP.TrangThaiDat = 'Da dat'
GROUP BY P.MaPhong, P.LoaiPhong, P.SoKhachToiDa, P.GiaPhong
HAVING COUNT(DP.MaDatPhong) > 2;
