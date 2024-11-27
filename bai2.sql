
CREATE DATABASE BanHangDB;
GO

USE BanHangDB;
GO

CREATE TABLE NHANVIEN (
    MaNV INT PRIMARY KEY,          
    TenNV NVARCHAR(50)             
);

CREATE TABLE HOADON (
    SoHD INT PRIMARY KEY,           
    TenKH NVARCHAR(50),             
    GioVao DATETIME,                
    GioRa DATETIME,                 
    BanAn INT,                      
    SoLanIn INT,                    
    SoKhach INT,                  
    ChietKhau FLOAT,             
    GiamGiaDoAn FLOAT,         
    PhiPV FLOAT,                   
    ThueVAT FLOAT,                  
    MaNV INT,                  
    FOREIGN KEY (MaNV) REFERENCES NHANVIEN(MaNV)
);

CREATE TABLE HANG (
    MaHang INT PRIMARY KEY,        
    TenHang NVARCHAR(50),         
    DVT NVARCHAR(20)             
);


CREATE TABLE CHITIETHD (
    SoHD INT,                      
    MaHang INT,                  
    DonGia FLOAT,               
    SoLuong INT,                  
    PRIMARY KEY (SoHD, MaHang),   
    FOREIGN KEY (SoHD) REFERENCES HOADON(SoHD),
    FOREIGN KEY (MaHang) REFERENCES HANG(MaHang)
);
