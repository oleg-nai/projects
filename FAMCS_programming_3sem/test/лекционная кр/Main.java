import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

// Найдович Олег, 7 группа, 2 курс

class sort_String implements Comparator<String> {
    @Override
    public int compare(String o1, String o2) {
        if (o1.length() > o2.length())
            return -1;
        else if (o1.length() < o2.length())
            return 1;
        return 0;
    }
}

public class Main {

    public static void main(String[] args) throws IOException {

        ArrayList<String> boot = new ArrayList<String>();

        // открытие файла
        FileReader fr;
        try {
            fr = new FileReader("input.txt");
//            System.out.print("\nФайл открыт!\n");
        } catch (FileNotFoundException e) {
//            System.out.print("Не удалось открыть файл, имя ошибки:\n" + e);
            return;
        }

        // чтение с файла, проход по файлу для прочтения
        Scanner scan = new Scanner(fr);
        String mainStr, separator = " \t,", token;
        while (scan.hasNextLine()) {
            mainStr = scan.nextLine(); // берет следующую строку
            StringTokenizer pch = new StringTokenizer(mainStr, separator);
            while (pch.hasMoreTokens()) {
                token = pch.nextToken();
                if (token.contains("<"))
                    boot.add(token);
            }
        }
        fr.close();

        ArrayList<String> boot2 = new ArrayList<String>();
        separator = "<>";
        for (String item : boot) {
            StringTokenizer pch = new StringTokenizer(item, separator);
            while (pch.hasMoreTokens()) {
                token = pch.nextToken();
                boot2.add("<" + token + ">");
            }
        }
        // вывод в файл
        FileWriter fw = new FileWriter("output1.txt");

        for (String item : boot2) {
            fw.write(item + "\n");
        }
        fw.close();


        Collections.sort(boot2, new sort_String());


        boot2 = (ArrayList<String>) boot2.stream().distinct().collect(Collectors.toList());

        fw = new FileWriter("output2.txt");
        for (String item : boot2) {
            fw.write(item + "\n");
        }
        fw.close();
    }
}
