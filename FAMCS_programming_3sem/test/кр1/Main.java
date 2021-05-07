package com.company;

import static java.lang.Integer.parseInt;

import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.*;
import java.text.NumberFormat;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Calendar;


class sort_Strings implements Comparator<String> {
    public int compare(String o1, String o2) {
        char a = o1.charAt(0);
        char b = o2.charAt(0);
        if (Character.isDigit(a) == true)
        {
            int a_int = (int)a;
        }
        else if (Character.isDigit(b) == true)
        {
            int b_int = (int)b;
        }
        else {
            return 0;
        }
        if (a > b)
            return 1;
        return -1;
    }
}

public class Main {

    static boolean check_for_double(String str) {
        boolean ret = true;
        int b = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                ret = false;
            }
            if (str.charAt(i) == '.') {
                b++;
            }
        }
        if (b < 2) {
            return ret;
        } else {
            return false;
        }
    }

    static boolean check_for_int(String str) {
        boolean ret = true;
        for (int i = 0; i < str.length(); i++) {
            if (!Character.isDigit(str.charAt(i))) {
                ret = false;
            }
        }
        return ret;
    }


    public static boolean isNumeric(String str) {
        try {
            Long.parseLong(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    public static void main(String[] args) throws Exception {

//	1)	Чтение строки из текстового файла;
        String mainStr = "";
        // открытие файла
        FileReader fr;
        try {
            fr = new FileReader("test1.txt");
            System.out.print("\nФайл открыт!");
        } catch (FileNotFoundException e) {
            System.out.print("Не удалось открыть файл, имя ошибки:\n" + e);
            return;
        }

        // чтение с файла, проход по файлу для прочтения
        Scanner scan = new Scanner(fr);
        while (scan.hasNextLine()) {
            mainStr = scan.nextLine(); // берет следующую строку
        }
        fr.close();


// 	2)	Разобрать строку на лексемы, записать в отдельный массив1;

        // Проход по строке, разделение на лексемы
        String separator = ", -_!;";
        String token = "";
        ArrayList<String> str_separated = new ArrayList<String>();

        StringTokenizer pch = new StringTokenizer(mainStr, separator);
        while (pch.hasMoreTokens()) {
            token = pch.nextToken();
            str_separated.add(token);
        }
        System.out.print("\n-----------------\n");

        System.out.print("Str, разбитые на лексемы ");
        for(String str: str_separated) {
            System.out.print(str + " ");
        }
        System.out.print("\n-----------------\n");

//	3)	Найти лексемы целые числа(не помещающиеся в long), записать в отдельный массив2 (тип BigDecimal), ;

        ArrayList<BigDecimal> arr_mas2 = new ArrayList<BigDecimal>();

//        for (String tmp : str_separated) {
//            if (check_for_double(tmp) == true) {
//
//                try {
//                    long tmp_tmp = Long.parseLong(tmp);
//                    if (tmp_tmp >= 922337299) {
//                        BigDecimal tmp1 = new BigDecimal(tmp);
//                        arr_dec.add(tmp1);
//                    }
//                } catch (Exception e) {
//                    BigDecimal tmp1 = new BigDecimal(tmp);
//                    arr_dec.add(tmp1);
//                }
//            }
//        }

        long tmp_number;
        for(String tmp: str_separated) {
            try {
                tmp_number = Long.parseLong(tmp);
            }
            catch (NumberFormatException e) {
                try {
                    arr_mas2.add(new BigDecimal(tmp));
                }
                catch (Exception e1)
                {
                }
            }
        }

        ArrayList<BigDecimal> to_del = new ArrayList<BigDecimal>();
        for (BigDecimal tmp_det : arr_mas2) {
            if (tmp_det.compareTo(BigDecimal.valueOf(100000)) < 0) {
                to_del.add(tmp_det);
            }
        }
        for (BigDecimal tmp_det : to_del) {
            arr_mas2.remove(tmp_det);
        }




// 	4)      Среди лексем, представляющих из себя дату: число-месяц-год, проверить корректные с помощью стандартных функций, регулярное выражение не использовать;

        StringTokenizer pch1 = new StringTokenizer(mainStr, ", _!;");
        String token2 = "";
        ArrayList<String> tokens_like_calendar = new ArrayList<String>();
        while (pch1.hasMoreTokens()) {
            token = pch1.nextToken();

            StringTokenizer pch2 = new StringTokenizer(token, "-");
            while (pch2.hasMoreTokens()) {
                token2 = pch2.nextToken();
                if (check_for_int(token2)) {
                    tokens_like_calendar.add(token);
                }
            }
        }

        ArrayList<String> to_detele = new ArrayList<String>();
        for(String str: tokens_like_calendar) {
            if (isNumeric(str) == true)
                to_detele.add(str);
        }
        for(String str: to_detele) {
            tokens_like_calendar.remove(str);
        }
        System.out.print("\n-----------------\n");

        System.out.print("Str,  Число-месяц-год ");
        for(String str: tokens_like_calendar) {
            System.out.print(str + "\n");
        }
        System.out.print("\n-----------------\n");

        // 5)      Написать регулярное выражение для поиска всех лексем (или подстрок -больше балл),
        // начинающихся латинским символом, заканчивающихся цифрой;

        ArrayList<String> str_lat_dig = new ArrayList<String>();

        Pattern ptrn = Pattern.compile("[a-zA-Z].*\\d");
        for (String tmp : str_separated) {
            Matcher matcher = ptrn.matcher(tmp);
            boolean matchFound = matcher.find();
            if (matchFound == true) {
                str_lat_dig.add(tmp);
            }
        }


// 6)	Сортировать лексемы из массив1 по первой встреченной цифре (если нет цифр считать 0) в лексеме.
// (Использовать Arrays, Comparator);

        Collections.sort(str_separated, new sort_Strings());

        System.out.print("отсортированные лексемы через comparator");
        for(String str: str_separated) {
            System.out.print(str + " ");
        }

        //7)	Вырезать из массива массив1 элементы c  K по К2 (Использовать метод из System.).

        // 8)      С помощью форматирования выводить числа массива 2 с разделением на группы цифр пробелом или запятой (по 3 цифры) :
        // 4 356 783 497.34 или 4,356,783,497.34

        System.out.print("\n-----------------\n");

        System.out.print("\nВосьмое задание\n");
        Formatter f = new Formatter();
        int aaa = arr_mas2.size();
        int tmptmp = 0;
        for(BigDecimal tmp : arr_mas2) {
            f.format("%,.0f\n", tmp);
            tmptmp++;
            if(tmptmp == aaa){
                System.out.println(f);
            }
        }
        System.out.print("\n-----------------\n");

    }
}
