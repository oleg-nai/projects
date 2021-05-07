/*

- Разбить первую строку на лексемы (используя разделители из  второй строки),
определить в ней целые числа 8-й с\с  Числа записать в новый отдельные массив.
- Среди лексем не являющихся числами,
найти лексемы с хотя бы одной парой одинаковых символов и чётным количеством символов.
- Найти число Р(если есть, то должно совпадать с лексемой) , вывести позицию в изначальной строке.
- Добавить в строку случайное число до числа Р или в начало строки(если нет P).
- Подстроку из цифр (с самой маленькой длиной),  - удалить из строки .
- Все результаты сформировать в строки и вывести.

Naidovich Oleg, 7gr, 3var

*/

package com.company;
import java.util.*;
import static java.lang.Integer.parseInt;

public class Main {

    public static boolean isNumeric(String str) {
        try {
            Double.parseDouble(str);
            return true;
        } catch(NumberFormatException e){
            return false;
        }
    }

    public static boolean isNumberIn8(String str) {
        try{
            parseInt(str, 8);
            return true;
        }
        catch (Exception e){
            return false;
        }
//         /* indexOf(String str) — возвращает индекс в данной строке первого вхождения указанной подстроки.
//           Если эта подстрока не встречается, возвращается -1.
//
//           charAt() — возвращает символ, расположенный по указанному индексу строки. */
    }


    public static void findSameStr(String main) {
        System.out.print("\n\nИщем лексемы (не int) с четным количеством символов, которые встречаются более 1 раза:");

        String[] str_tmp = new String[50];
        int k = 0;

        String token;
        StringTokenizer pch = new StringTokenizer(main, " ");
        while (pch.hasMoreTokens()){
            token = pch.nextToken();
            str_tmp[k++] = token;
        }

        String[] str = new String[k];
        for(int i =0; i < k; i++){
        str[i] = str_tmp[i];
        }

        boolean boo = false;
        for (int i = 0; i < str.length; i++) {
            for (int j = i + 1; j < str.length; j++) {
                if (str[i].equals(str[j]) && str[i].length() % 2 == 0) {
                    System.out.print("\nДанная лексема встречается более 1 раза: " + str[i]);
                    boo = true;
                }
            }
        }
        if(!boo){
            System.out.print("\nНет одинаковых лексем");
        }
    }


    public static String fewestNumberInStr(String tokens) {

        int[] numbers = new int[50];
        int k = 0;

        String token;
        StringTokenizer pch = new StringTokenizer(tokens, " ");
        while (pch.hasMoreTokens()) {
            token = pch.nextToken();
            numbers[k++] = parseInt(token);
        }
        int[] numbers_tmp = new int[k];
        for(int i = 0; i < k;i++) {
            numbers_tmp[i] = numbers[i];
        }

        Arrays.sort(numbers_tmp);
        return Integer.toString(numbers_tmp[0]);
    }

    public static void main(String[] args) {

        Scanner s = new Scanner(System.in);

        System.out.print("Введите строку: ");
        String mainStr = s.nextLine();

        System.out.print(String.format("\nВведите разделитель: "));
        String separator = s.nextLine();

        System.out.print(String.format("\nВВедите число: "));
        int numberP = s.nextInt();





        boolean was_again_P = false;
        String token_in_8 = "";
        String token_int = "";
        String tokens = "";
        String tokens_without_int = "";
        int positionP = 0;


        String token;
        int tokenInt;

        StringTokenizer pch = new StringTokenizer(mainStr, separator);
        while (pch.hasMoreTokens()){
            token = pch.nextToken();
            tokens += token + " ";
            if(isNumeric(token)) {              // Проверяет, является ли token числом
                tokenInt = Integer.valueOf(token);
                token_int += token + " ";
                if(numberP == tokenInt && was_again_P == false)
                {
                    positionP = mainStr.indexOf(token); // находит P
                    was_again_P = true;
                }

                // определить в ней целые числа 8-й с\с
                // Числа записать в новый отдельные массив
                if(isNumberIn8(token)) {
                    token_in_8 += token + " ";
                }
            } else {
                tokens_without_int += token + " ";
            }
        }




        System.out.print(String.format("\nИсходная строка\n" + tokens + "\n\n"));
        System.out.print(String.format("Числа из исходной строки\n" + token_int + "\n\n"));
        System.out.print(String.format("Числа в 8-ой с/c\n" + token_in_8 + "\n\n") );

        // - Среди лексем не являющихся числами,
        //   найти лексемы с хотя бы одной парой одинаковых символов и чётным количеством символов
//        findSameStr(tokens_without_int);
        findSameStr(tokens);
        System.out.print("\n\n");




        // - Подстроку из цифр (с самой маленькой длиной),  - удалить из строки .

        if(was_again_P == true){
            System.out.print(String.format("Номер позиции числа P в исходной строке: " + positionP + "\n\n"));
        } else {
            System.out.print(String.format("Номер позиции числа P в исходной строке: данного числоа нету в исходной строке\n\n"));
        }

        // - Добавить в строку случайное число до числа Р или в начало строки(если нет P).
        Random random = new Random();
        if(was_again_P == true) {
            tokens = Integer.toString(random.nextInt(100)) + " " + tokens;
        } else {
            tokens = Integer.toString(numberP) + " " + tokens;
        }
        System.out.print(String.format("Основная строка после добавления случайного числа до числа Р или в начало строки(если нет P)\n" + tokens + "\n\n" ));


        String numbers_to_delete =" " + fewestNumberInStr(token_int) + " ";
        tokens = tokens.replaceFirst(numbers_to_delete, "");
        System.out.print(String.format("Число, которое мы удаляем: " + numbers_to_delete + "\n"));
        System.out.print(String.format("Основная строка после удаления числа с самой маленькой длинной:\n" + tokens + "\n\n"));

    }
}

