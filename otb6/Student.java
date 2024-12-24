/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.otb6;

/**
 *
 * @author PC
 */
public class Student extends Person {
    private String program;
    private int year;
    private double score;

    // Constructor
    public Student(String name, String address, String program, int year, double score) {
        super(name, address);
        this.program = program;
        this.year = year;
        this.score = score;
    }

    // Getter và Setter
    public String getProgram() {
        return program;
    }

    public void setProgram(String program) {
        this.program = program;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public double getScore() {
        return score;
    }

    public void setScore(double score) {
        this.score = score;
    }

    // toString
    @Override
    public String toString() {
        return super.toString() + ", Program: " + program + ", Year: " + year + ", Score: " + score;
    }
}

