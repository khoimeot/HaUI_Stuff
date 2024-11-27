-- Drop tables and database if they exist
DROP TABLE IF EXISTS KetQua;
DROP TABLE IF EXISTS MON;
DROP TABLE IF EXISTS SV;
DROP DATABASE IF EXISTS QuanLyHocTap;

-- Create database and tables
CREATE DATABASE QuanLyHocTap;
GO
USE QuanLyHocTap;
GO

CREATE TABLE SV (
	MaSV char(10) PRIMARY KEY,
	Ho nvarchar(30),
	Ten nvarchar(30),
	TenLop nvarchar(50)
);

CREATE TABLE MON (
	MaMH char(10) PRIMARY KEY,
	TenMH nvarchar(30),
	SoTC int
);

CREATE TABLE KetQua (
	MaSV char(10),
	MaMH char(10),
	Diem Int,
	PRIMARY KEY (MaSV , MaMH),
	FOREIGN KEY (MaSV) REFERENCES SV(MaSV),
	FOREIGN KEY (MaMH) REFERENCES MON(MaMH)
);

-- Insert data into tables
INSERT INTO SV (MaSV , Ho , Ten , TenLop) VALUES 
('SV001', 'Nguyen', 'An', 'KTPM01'),
('SV002', 'Tran', 'Binh', 'CNTT01'),
('SV003', 'Le', 'Chi', 'KTPM02');
INSERT INTO MON (MaMH, TenMH, SoTC) VALUES
('MH001', 'Lap trinh C++', 3),
('MH002', 'Co so du lieu', 4),
('MH003', 'Mang may tinh', 3);
INSERT INTO KetQua (MaSV, MaMH, Diem) VALUES
('SV001', 'MH001', 8),
('SV001', 'MH002', 7),
('SV002', 'MH001', 9),
('SV002', 'MH003', 6),
('SV003', 'MH002', 5),
('SV003', 'MH003', 8);

-- Retrieve data from tables
SELECT * FROM SV;
SELECT * FROM MON;
SELECT * FROM KetQua;

-- Update data
UPDATE MON
SET SoTC = 3
WHERE SoTC = 4;

SELECT Ten
FROM SV
WHERE Ten LIKE 'H%';


SELECT SV.Ten
FROM SV
JOIN KetQua ON SV.MaSV = KetQua.MaSV
JOIN MON ON KetQua.MaMH = MON.MaMH
WHERE MON.TenMH = 'Co so du lieu' AND KetQua.Diem >= 7;


SELECT MON.MaMH, COUNT(KetQua.MaSV) AS SoSinhVien
FROM MON
LEFT JOIN KetQua ON MON.MaMH = KetQua.MaMH
GROUP BY MON.MaMH;


SELECT TenMH
FROM MON
WHERE SoTC = (SELECT MAX(SoTC) FROM MON);

