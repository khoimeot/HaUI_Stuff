CREATE DATABASE KhoHangDB
GO
USE KhoHangDB
GO

CREATE TABLE KhachHang
(MaKH char(8) PRIMARY KEY,
TenKh nvarchar(30),
DiaChi nvarchar(50)
)
CREATE TABLE Hang
(MaHang int PRIMARY KEY,
TenHang nvarchar(45),
HangSX nvarchar(35),
DonGia decimal(8,2)
)
CREATE TABLE HangDat 
(MaKh char(8) ,
MaHang int ,
SoLuong decimal(8,2),
NgayGiao datetime

CONSTRAINT PK_HangDat PRIMARY KEY (MaKh , MaHang),
)
INSERT KhachHang
VALUES ('K001' , N'Bùi Bài Bình' , 'Hà Nội')
INSERT KhachHang
VALUES ('K002' , N'Nguyễn Mai Hương' , 'Hà Nội')
INSERT KhachHang
VALUES ('K003' , N'Nguyễn Hồng Hà' , 'Hải Phòng')

INSERT Hang
VALUES (12 , N'TV 24 inch' , 'Samsung' , 1200)
INSERT Hang
VALUES (13 , N'Laptop C500 màn hình 17' , 'Sony' , 1000)
INSERT Hang
VALUES (14 , N'Điều hòa 1200kw' , 'Misumi' , 700)

INSERT HangDat
VALUES ('K001' , 12 , 26 , '2012/08/13')
INSERT HangDat
VALUES ('K002' , 13 , 37 , '2012/10/27')
INSERT HangDat
VALUES ('K003' , 14 , 14 , '2012/10/3')
INSERT HangDat
VALUES ('K004' , 14 , 20 , '2012/11/13')


SELECT * 
FROM KhachHang
SELECT * 
FROM Hang
SELECT * 
FROM HangDat

DROP TABLE KhachHang
DROP TABLE Hang
DROP TABLE HangDat


DROP DATABASE KhoHangDB