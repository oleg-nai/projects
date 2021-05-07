/*

Сдать до 25.10
Регулярные выражения.
Использовать классы : Matcher, Pattern, PatternSyntaxException.
Общее задание:

Данные считать из файла ( >=6 тестовых строк).
Записать результаты в файл. Использовать классы : FileReader, FileWriter, BufferedReader, BufferedWriter.


3. Написать регулярное выражение определяющее является ли заданная строка правильным MAC-адресом( числа в 16 с\с).
Пример правильных выражений:
01:32:54:67:89:AB
aE:dC:cA:5A:76:54
Пример неправильных выражений:
01:33:47:65:89:ab:cd
01:23:45:67:89:Az


Naidovich Oleg, 7gr


 */


/*
Дополнительное задание:

1.С помощью метода find (class Matcher) найти в строке с тегами  HTML-документа все теги,
строки между тегами, атрибуты. Результаты вывести.
2. С помощью регулярного выражения заменить слова в тексте на новые.

*/
package com.company;

import java.io.FileNotFoundException;

import java.util.ArrayList;

import java.util.Scanner;

import java.io.FileReader;
import java.io.FileWriter;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {

    public static void main(String[] args) throws Exception {

        FileReader fr;

        try {
            fr = new FileReader("test.txt");
            System.out.print("\nФайл открыт!");
        } catch (FileNotFoundException e) {
            System.out.print("Не удалось открыть файл, имя ошибки:\n" + e);
            return;
        }

        Scanner scan = new Scanner(fr);

        ArrayList<String> strIsMAC = new ArrayList<String>();
        ArrayList<String> strIsNotMAC = new ArrayList<String>();


//      String pattern = "(^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$)";
        Pattern ptrn = Pattern.compile("(^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$)");
        Pattern ptrn = Pattern.compile("[a-zA-Z].*\d");

        while (scan.hasNextLine()) {                // проходит по файлу по enter
            String tmp = scan.nextLine();
            Matcher matcher = ptrn.matcher(tmp);
            if (matcher.find()) {
                strIsMAC.add(matcher.group(0));
            } else if(!tmp.isEmpty()){
                    strIsNotMAC.add(tmp);
            }
        }
        fr.close();

        FileWriter fw = new FileWriter("write.txt");
        fw.write("\nПравильные MAC адреса:\n");
        System.out.print("\nПравильные MAC адреса:\n");
        for (int i = 0; i < strIsMAC.size(); i++) {
            fw.write(strIsMAC.get(i) + "\n");
            System.out.print(strIsMAC.get(i) + "\n");
        }
        fw.write("\nНеправильные MAC адреса:\n");
        System.out.print("\nНеправильные MAC адреса:\n");
        for (int i = 0; i < strIsNotMAC.size(); i++) {
            fw.write(strIsNotMAC.get(i) + "\n");
            System.out.print(strIsNotMAC.get(i) + "\n");
        }
        fw.close();
    }
}
