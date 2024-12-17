--Câu 1
--1a
--Tạo cơ sở dữ liệu QlNhanVien
CREATE DATABASE QlNhanVien
GO

--1b
--Tạo bảng
--Chuyển vào cơ sở dữ liệu QlNhanVien
USE QlNhanVien
GO
--Tạo bảng NhanVien
CREATE TABLE NhanVien
(MaNV char(5) PRIMARY KEY,
 TenNV nvarchar(30),
 NgaySinh datetime,
 TrinhDo nvarchar(40),
 ChucVu nvarchar(50)
)
GO

--Tạo bảng KhoaHoc
CREATE TABLE KhoaHoc
(MaKH char(5) PRIMARY KEY,
 TenKH nvarchar(80),
 DiaDiem nvarchar(50)
)
GO

--Tạo bảng ThamGia
CREATE TABLE ThamGia
(MaNV char(5),
 MaKH char(5),
 SoBuoiNghi int,
 KetQua nvarchar(20),
 PRIMARY KEY (MaNV, MaKH),
 FOREIGN KEY (MaNV) REFERENCES NhanVien(MaNV),
 FOREIGN KEY (MaKH) REFERENCES KhoaHoc(MaKH)
)
GO

--1c
--Thiết lập dịnh dạng ngày tháng
SET DATEFORMAT mdy
--Chèn dữ liệu vào bảng NhanVien
INSERT NhanVien
VALUES ('NV01', N'Trần Văn Ước','12-5-1988', N'Đại học', N'Nhân viên'),
	   ('NV02', N'Hoàng Văn Huy','12-17-2000', N'Đại học', N'Trưởng phòng'),
	   ('NV03', N'Nguyễn Thị Chính','2-5-1982', N'Cao đẳng', N'Nhân viên')
GO
--Xem bảng NhanVien
SELECT *
FROM NhanVien

--Chèn dữ liệu vào bảng KhoaHoc
INSERT KhoaHoc
VALUES ('KH01', N'Giao tiếp cơ bản',N'Hà Nội'),
	   ('KH02', N'Giao tiếp nâng cao',N'Hà Nội'),
	   ('KH03', N'Phân tích số liệu',N'Hồ Chí Minh')
GO
--Xem bảng KhoaHoc
SELECT *
FROM KhoaHoc

----Chèn dữ liệu vào bảng ThamGia
INSERT ThamGia
VALUES ('NV01','KH01',1,N'Khá'),
	   ('NV01','KH02',2,N'Khá'),
	   ('NV02','KH01',0,N'Giỏi'),
	   ('NV02','KH02',1,N'Khá'),
	   ('NV02','KH03',1,N'Trung bình'),
	   ('NV03','KH01',4,N'Trung bình')
GO
--Xem bảng ThamGia
SELECT *
FROM ThamGia

--Câu 2. Truy vấn dữ liệu
--2a
--Lấy ra từ cơ sở dữ liệu tên các nhân viên có trình độ đại học
SELECT TenNV
FROM NhanVien
WHERE TrinhDo = N'Đại học'

--2b
--Đưa ra thông tin các nhân viên họ ‘Trần’ sinh năm 2000
SELECT *
FROM NhanVien
WHERE TenNV LIKE N'Trần%' AND YEAR(NgaySinh) = 2000

--2c
--Lấy ra tên các nhân viên tham gia 
--khóa học Giao tiếp nâng cao có kết quả Khá
SELECT TenNV
FROM NhanVien n
	INNER JOIN ThamGia t ON t.MaNV = n.MaNV
	INNER JOIN KhoaHoc k ON k.MaKH = t.MaKH
WHERE TenKH = N'Giao tiếp nâng cao'
	AND KetQua = N'Khá'

--2d
--Đưa ra thông tin các nhân viên tham gia các 
--khóa học ở Hà Nội có số buổi nghỉ học nhiều hơn 2
SELECT n.MaNV, TenNV, NgaySinh, TrinhDo, ChucVu
FROM NhanVien n
	INNER JOIN ThamGia t ON t.MaNV = n.MaNV
	INNER JOIN KhoaHoc k ON k.MaKH = t.MaKH
WHERE DiaDiem = N'Hà Nội' 
	AND SoBuoiNghi > 2

--2e
--Đưa ra mã nhân viên, tên nhân viên, tuổi của 
--các nhân viên. Sắp xếp theo tuổi từ cao đến thấp
SELECT MaNV, TenNV,
	   DATEDIFF(yy,NgaySinh, GETDATE()) [Tuổi]
FROM NhanVien
ORDER BY [Tuổi] DESC

--2f
--Lấy ra mã nhân viên, tên nhân viên, số buổi nghỉ 
--và kết quả của các nhân viên tham gia các khóa học 
--về giao tiếp.
SELECT n.MaNV, TenNV, SoBuoiNghi, KetQua
FROM NhanVien n
	INNER JOIN ThamGia t ON t.MaNV = n.MaNV
	INNER JOIN KhoaHoc k ON k.MaKH = t.MaKH
WHERE TenKH LIKE N'%giao tiếp%'

--2g
--Đưa ra danh sách mã khóa học, tên khóa học, 
--số người tham gia đạt kết quả giỏi trong mỗi khóa
SELECT k.MaKH, 
	   TenKH,
	   COUNT(MaNV) [Số người tham gia]
FROM KhoaHoc k
	INNER JOIN ThamGia t ON t.MaKH = k.MaKH
WHERE KetQua = N'Giỏi'
GROUP BY k.MaKH, TenKH


--2h
--Lấy ra mã nhân viên và số khóa học 
--nhân viên đó đã tham gia
SELECT MaNV, 
	   COUNT(MaKH) [Số khóa học tham gia]
FROM ThamGia
GROUP BY MaNV

--2i
--Lấy ra mã và tên các khóa học có từ 2 nhân viên 
--trở lên tham gia học.
SELECT k.MaKH, TenKH
FROM KhoaHoc k
	INNER JOIN ThamGia t ON t.MaKH = k.MaKH
GROUP BY k.MaKH, TenKH
HAVING COUNT(MaNV) >= 2

--2j 
--Đưa ra thông tin các nhân viên 
--già nhất khóa học ‘Phân tích số liệu’
SELECT n.MaNV, TenNV, NgaySinh, TrinhDo, ChucVu
FROM NhanVien n
	INNER JOIN ThamGia t ON t.MaNV = n.MaNV
	INNER JOIN KhoaHoc k ON k.MaKH = t.MaKH
WHERE TenKH = N'Phân tích số liệu' 
	AND NgaySinh =
		(SELECT MIN(NgaySinh)
		 FROM NhanVien n
			INNER JOIN ThamGia t ON t.MaNV = n.MaNV
			INNER JOIN KhoaHoc k ON k.MaKH = t.MaKH
		 WHERE TenKH = N'Phân tích số liệu')

--2k
--Lấy ra mã và tên nhân viên đã tham gia tất cả các khóa học.
SELECT MaNV, TenNV
FROM NhanVien
WHERE MaNV IN 
	(SELECT MaNV
	  FROM ThamGia
	  GROUP BY MaNV
	  HAVING COUNT(MaKH) = 
			(SELECT COUNT(MaKH)
			 FROM KhoaHoc)
	)

--2l
--Đưa ra nhân viên không tham gia khóa học nào
SELECT *
FROM NhanVien
WHERE MaNV NOT IN 
	(SELECT MaNV
	 FROM ThamGia)

--2m
--Đưa ra nhân viên tham gia nhiều khóa học nhất
SELECT *
FROM NhanVien
WHERE MaNV IN 
	(SELECT MaNV
	 FROM ThamGia
	 GROUP BY MaNV
	 HAVING COUNT(MaKH) >= ALL 
			(SELECT COUNT(MaKH)
			 FROM ThamGia
	  		 GROUP BY MaNV))

--2n
--Đưa ra khóa học không có học viên nào học lực ‘Kém’
SELECT *
FROM KhoaHoc
WHERE MaKH NOT IN
	(SELECT MaKH
	 FROM ThamGia
	 WHERE KetQua = N'Kém')

--2o
--Đưa ra nhân viên có số buổi nghỉ học nhiều nhất
SELECT *
FROM NhanVien
WHERE MaNV IN 
	(SELECT MaNV
	 FROM ThamGia
	 WHERE SoBuoiNghi >= ALL 
			(SELECT SoBuoiNghi
			 FROM ThamGia))