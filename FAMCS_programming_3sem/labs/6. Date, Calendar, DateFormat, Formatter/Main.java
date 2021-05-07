// Naidovich Oleg, 7gr
// 3 вариант
/*
                        Лабораторная работа № 6
Использовать Классы Date,  Calendar,  DateFormat,  Formatter,  SimpleDateFormat

Общее задание:
1.	Ввод, вывод(пребразование из строки в  Date,  Calendar  и наоборот).
2.	Проверить данные с неправильными : месяцами(>12),  номерами дней месяца (>31),
    часами, минутами, секундами (стандартный метод форматирующего класса )

3.	Для Calendar  изменять данные , использовать методы: settime, add, roll.
*/

package com.company;

import java.text.ParseException;
import java.util.*;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.concurrent.ExecutionException;

public class Main {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        System.out.print("Введите корректное время (год месяц час)(2002 05 23): ");
        String str = scan.nextLine();


        Calendar calendar = Calendar.getInstance();

        SimpleDateFormat sdf = new SimpleDateFormat("yyyy MM k");
        sdf.setLenient(false);

        try {
            // Чтение из строки (calendar):
            calendar.setTime(sdf.parse(str));

            // add, roll
            calendar.add(Calendar.YEAR, 1);
            calendar.roll(Calendar.YEAR, true);


            // Чтение из строки (date):
            SimpleDateFormat format = new SimpleDateFormat("yyyy MM k");
            Date date = format.parse(str);
            System.out.println("Date: " + date + "\n");


            // SimpleDateFormat
        /*
            - год (последние 2 цифры)
            - номер месяца (с лидирующими нулями если номер месяца < 10)
            - день месяца без лидирующих нулей
            - день недели в месяце с лидирующими нулями
            - часы в 24-часовом формате с лидирующим нулем
            - время в 12-часовом формате с лидирующим нулем
        */
            System.out.print("SimpleDateFormat:\n");
            SimpleDateFormat sdf1 = new SimpleDateFormat("yy - год\n" +
                    "MM - номер месяца (с лидирующими нулями если номер месяца < 10)\n" +
                    "d - день месяца без лидирующих нулей\n" +
                    "FF - день недели в месяце с лидирующими нулями\n" +
                    "HH - часы в 24-часовом формате с лидирующим нулем\n" +
                    "hh - время в 12-часовом формате с лидирующим нулем", Locale.ENGLISH);
            System.out.println(sdf1.format(calendar.getTime()) + "\n");


            // Formatter
        /*
            - Сокращенное название дня недели
            - Сокращенное название месяца
            - Региональный эквивалент AM или РМ заглавными буквами
         */
            System.out.print("Formatter: \n");
            Formatter fmt = new Formatter();
            fmt.format("%ta - Сокращенное название дня недели\n" +
                    "%tb - Сокращенное название месяца\n" +
                    "%tp - Региональный эквивалент AM или РМ заглавными буквами", calendar, calendar, calendar);
            System.out.print(fmt);
        } catch (Exception c) {
            System.out.print("Error. invalid date");
        }

    }
}