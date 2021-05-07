package com.company;


import java.lang.reflect.Array;
import java.util.List;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.text.NumberFormat;


class sort_numbers implements Comparator<Integer> {
    @Override
    public int compare(Integer o1, Integer o2) {
        if (o1 >= o2)
            return -1;
        return 1;
    }
}


public class matrix {

    private static List<Integer> last_numbers;

    public static Integer read_number() {
        int i;
        Scanner scan = new Scanner(System.in);
        i = scan.nextInt();
        while (i <= 0) {
            System.out.println("Вы ввели неверное число");
            i = scan.nextInt();
        }
        return i;
    }

    public static void filling_random(int[][] mat, int n, int m) {
        Random random = new Random();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                mat[i][j] = random.nextInt(51);
    }

    public static List<Integer> find_biggest(int[][] mat, int n, int m) {
        int tmp = 0, n_tmp = 0, m_tmp = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (tmp < mat[i][j]) {
                    tmp = mat[i][j];
                    n_tmp = i;
                    m_tmp = j;
                }
            }
        return Arrays.asList(tmp, n_tmp, m_tmp);
    }

    public static void output_mat(int[][] mat, Integer n, Integer m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(mat[i][j] + "\t");
            }
            System.out.print("\n");
        }
        System.out.print("\n");
    }

    public static void change_mat(int[][] mat, int n, int m, List list) {
        int n_bigger = (int) list.get(1);
        int m_bigger = (int) list.get(2);
        if (n_bigger <= 0 && m_bigger <= 0)
            return;
        if (n_bigger > 0) {
            for (int j = 0; j < m; j++) {
                mat[0][j] = mat[0][j] ^ mat[n_bigger][j];
                mat[n_bigger][j] = mat[0][j] ^ mat[n_bigger][j];
                mat[0][j] = mat[0][j] ^ mat[n_bigger][j];
            }
        }
        if (m_bigger > 0) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = mat[i][0] ^ mat[i][m_bigger];
                mat[i][m_bigger] = mat[i][0] ^ mat[i][m_bigger];
                mat[i][0] = mat[i][0] ^ mat[i][m_bigger];
            }
        }
    }

    public static void sort_last(int[][] mat, int n, int m) {
        List<Integer> last_list_mat = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            last_list_mat.add(mat[n - 1][i]);
        }
        Collections.sort(last_list_mat, new sort_numbers());
        for (int i = 0; i < m; i++) {
            mat[n-1][i] = last_list_mat.get(i);
        }
        last_numbers = last_list_mat;
    }

    public static void matrix_solve() {

        Integer n, m;
        System.out.print("Введите натуральное число n: ");
        n = read_number();
        System.out.print("Введите натуральное число m: ");
        m = read_number();
        System.out.print("\nИсходная матрица: \n");
        int[][] mat = new int[n][m];
        filling_random(mat, n, m);
        output_mat(mat, n, m);

        List bigger_number = find_biggest(mat, n, m);
        System.out.print("Самое большое число в матрице, строка и столбец(считая от 0):\n " + bigger_number + "\n\n");
        change_mat(mat, n, m, bigger_number);
        System.out.print("Перенос строк и столбцов так, чтобы max элемент матрицы был на позиции [0][0]\n");
        output_mat(mat, n, m);

        sort_last(mat,n,m);
        System.out.print("Последняя страка отсортирована:\n");
        output_mat(mat, n, m);

        System.out.print("Последняя строка в массиве: \n");
        NumberFormat numberFormat1 = NumberFormat.getInstance();
        for(Integer number: last_numbers){
            System.out.print(numberFormat1.format(number) + " ");
        }

    }
}
