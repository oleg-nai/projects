package com.company;

import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.Scanner;

import java.util.Formatter;

public class Taylor {

    private static int k = read_k();
    private static double x = read_x();
    private static double e = Math.pow(10,-k);

    public static void FormatterFunc(int inumber, double dnumber) {
        System.out.println("-------------------------------------------------");
        Formatter f = new Formatter();
        f.format("Целое число в восьмеричной записи: %o", inumber);
        System.out.println(f);

        f = new Formatter();
        f.format("Целое число в шестнадцатеричной записи: %a", dnumber);
        System.out.println(f);

        f = new Formatter();
        f.format("Спецификация минимальной ширины поля: %07d", inumber);
        System.out.println(f);

        f = new Formatter();
        f.format("Спецификация точности: %3.6f", dnumber);
        System.out.println(f);

        System.out.println("5 вариантов использования флагов формата:");
        System.out.printf("Выравниване влево:\n%-10d%n", inumber);
        System.out.printf("Положительные числа предваряются пробелом: % 10d%n", inumber);
        System.out.printf("Положительные числа предваряются знаком +: %+10d%n", inumber);
        System.out.printf("Числовые значения включают разделители групп: %,10d%n"   , inumber);
        System.out.printf("Отрицательные значения выводятся в скобках: %(10d%n", inumber);

        f = new Formatter();
        Number n[] = { 4, 2.2, 3, 1.1 };
        f.format("%4$.1f %2$.1f %3$d %1$d", n[0], n[1],n[2], n[3]);

        System.out.println(f);
    }

    public static int read_k() {
        int k = 0;
        Scanner scan = new Scanner(System.in);
        System.out.println("Введите значение k (k > 0)");
        k = scan.nextInt();
        while (k <= 0) {
            System.out.println("Вы ввели неверное число, k > 0");
            k = scan.nextInt();
        }
        return k;
    }

    public static double read_x(){
        double x;
        Scanner scan = new Scanner(System.in);
        System.out.println("Введите значение x = [-1, +1)");
        x = scan.nextDouble();
        while (x < -1 || x >= 1) {
            System.out.println("Вы ввели неверное число, x = [-1, +1)");
            x = scan.nextInt();
        }
        return x;
    }

    public static void Taylor_simple() {
        int i = 1;
        double tmp = 0, ans_taylor = 0, x_little = x;
        do {
            tmp = Math.pow(x_little, i) / i;
            ans_taylor -= tmp;
            i++;
        } while (Math.abs(tmp) >= e);

        double math_ans = Math.log(1-x);

        System.out.println("--------------------Тейлор с использованием простых чисел--------------------");
        System.out.printf("Заданная точность:             e          = %f%n", e);
        System.out.println("Ответ по Тейлору:             ans_taylor = " + ans_taylor);
        System.out.println("Ответ встроенной функции:     ans_math   = " + math_ans);
        System.out.println("----------------------------------------");

        Scanner scan = new Scanner(System.in);
        System.out.println("Введите целое значение a: ");
        int a = scan.nextInt();
        FormatterFunc(a,ans_taylor);
    }

    public static void Taylor_BigDecimal_BigInteger() {

        BigInteger k_big = BigInteger.valueOf(k);
        BigDecimal e_big = BigDecimal.valueOf(e);
        BigDecimal x_big = BigDecimal.valueOf(x);

        int i = 1;
        BigDecimal tmp = BigDecimal.valueOf(0);
        BigDecimal ans_taylor = BigDecimal.valueOf(0);
        do{
            tmp = x_big.pow(i);
            tmp = tmp.divide(BigDecimal.valueOf(i), 4);
            ans_taylor = ans_taylor.subtract(tmp);
            i++;
        }while(tmp.abs().compareTo(e_big) == 1);

        BigDecimal math_ans = BigDecimal.valueOf(Math.log(1-x));
        System.out.println("--------------------Тейлор через BigDecimal--------------------");
        System.out.printf ("Заданная точность:            e          = %f%n", e);
        System.out.println("Ответ BigDecimal, BigInteger: ans_taylor = " + ans_taylor);
        System.out.println("Ответ встроенной функции:     ans_math   = " + math_ans);
    }
}