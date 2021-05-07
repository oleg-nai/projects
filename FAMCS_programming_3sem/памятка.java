// Найдович Олег 7гр. 

package com.company;
import static java.lang.Integer.parseInt;
import java.lang.reflect.Array;
import java.util.List;
import java.util.Comparator;
import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.Collections;
import java.util.ArrayList;
import java.text.NumberFormat;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import java.io.File;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;

import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.DocumentReader;
import com.thoughtworks.xstream.io.xml.DomDriver;
import com.thoughtworks.xstream.security.AnyTypePermission;

import java.io.*;

public class Main {

    public static void main(String[] args) throws Exception {

        // ===========================================
        //               РАБОТА С ФАЙЛАМИ

        // ----------------------------------------
        //      Через Scanner и FileReader

        // открытие файла
        Filereader fr; 
        try {
            fr = new FileReader("test.txt");
            System.out.print("\nФайл открыт!");
        } catch (FileNotFoundException e) {
            System.out.print("Не удалось открыть файл, имя ошибки:\n" + e);
            return;
        }

        
        // чтение с файла, проход по файлу для прочтения
        Scanner scan = new Scanner(fr);
        while(scan.hasNextLine()) {
            String tmp = scan.nextLine(); // берет следующую строку
        }
        fr.close();

        // вывод в файл
        FileWriter fw = new FileWriter("write.txt");
        fw.write("hello world");
        fw.close();


        // --------------------------------------
        //       через RandomAccessFile

        // чтение с файла
        public void readFromFile(String path) throws IOException {
            RandomAccessFile file = new RandomAccessFile(path, "r");
            String str = file.readLine();
            while (str != null) {
                this.storage.add(Horse.strToHorse(str));
                str = file.readLine();
            }
            file.close();
        }

        // запись в файл
        public void writeToFile(String path) throws IOException {
            RandomAccessFile file = new RandomAccessFile(path, "rw");
            String str;
            for (Horse item : this.storage) {
                str = item.name + item.year + item.experience +
                        item.owner + item.data_owner + "\n";
                file.write(str.getBytes());
            }
            file.close();
        }


        // ------------------------------------------------------
        // сериализация для записи и чтения бинарного файла файла и XML файла

        class Serialization {

            // запись в бинарный файл файл
            public void write_to_binary(String path, HorseStorage horses) throws IOException {
                ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(path));
                output.writeObject(horses);
                output.close();
            }
            // считывание с бинарного файла
            public HorseStorage read_from_binary(String path) throws IOException, ClassNotFoundException {
                HorseStorage horses = new HorseStorage();
                ObjectInputStream input = new ObjectInputStream(new FileInputStream(path));
                horses = (HorseStorage) input.readObject();
                input.close();
                return horses;
            }

               // подключаем библиотеку XStream и реализуем запись в файл xml.
            public void write_to_xml(String path, HorseStorage horses) throws IOException {
                XStream xstream = new XStream(new DomDriver());
                FileOutputStream output = new FileOutputStream(path);
                xstream.alias("HorseStorage", HorseStorage.class);
                xstream.alias("Horse", Horse.class);
                output.write(xstream.toXML(horses).getBytes());
                output.close();
            }

            // чтение с файла
            public HorseStorage read_from_xml(String path) throws IOException, ClassNotFoundException {
                XStream xstream = new XStream(new DomDriver());
                xstream.addPermission(AnyTypePermission.ANY);
                HorseStorage horses = new HorseStorage();
                xstream.alias("HorseStorage", HorseStorage.class);
                xstream.alias("Horse", Horse.class);
                horses = ((HorseStorage) xstream.fromXML(new File(path)));
                return horses;
            }
        }
        // а в основном классе пишем: 

        public void write_bin(String path) throws IOException {
            Serialization serial = new Serialization();
            serial.write_to_binary(path, this);
        }
    
        public void readFromBin(String path) throws IOException, ClassNotFoundException {
            Serialization serial = new Serialization();
            this.storage.addAll(serial.read_from_binary(path).storage);
        }


        // ===========================================
        //          Работа с классами

        

    // абстрактный класс "Animal"
    abstract class Animal implements Serializable {

        public String name;         // кличка лошади
        public String year;         // возраст лошади

        public Animal(String name, String year, String data_owner, String owner) {
            this.name = name;
            this.year = year;
        }
    }

    // Класс "Horse", унаследованный от абстрактного класса "Animal"
    class Horse extends Animal implements Serializable {

        public String experience;   // стаж участия в соревнованиях

        public Horse(String name, String year, String data_owner, String owner, String experience) {
            super(name, year, data_owner, owner);
            this.experience = experience;
        }
    }


    abstract class AnimalStorage implements Serializable {

        public ArrayList<Animal> storage; // создание типо базы данных из animal 
    
        public void add_object(Object object) {
            storage.add((Animal) object);
        }
    
        public void printAll() {
            System.out.print("\nОбъекты нашего хранилища:\n");
            storage.forEach(horse -> horse.print());
        }
    
    }

    // для прикола реализуем интерфейс
    interface Storage {
        public void printAll();
        public void add_object(Object object);
    }

    class HorseStorage extends AnimalStorage implements Storage, Serializable {

        public ArrayList<Horse> storage;
    
        public HorseStorage() {
            super();
            storage = new ArrayList<Horse>();
        }
    
        public HorseStorage(ArrayList<Horse> boot) {
            storage = boot;
        }

        @Override
        public void printAll() {
            System.out.print("\nОбъекты нашего хранилища:\n");
            storage.forEach(horse -> horse.print());
        }
    
        @Override
        public void add_object(Object object) {
            storage.add((Horse) object);
        }
    
    }


    
        // ===========================================
        // работа с регулярными выражениями

        String str = "sdafoqenbqerqoenfaskdnfqwe;"
        Pattern ptrn = Pattern.compile("(^([0-9A-Fa-f]{2}[:-]){5}([0-9A-Fa-f]{2})$)");
        Matcher matcher = ptrn.matcher(str);
        if(matcher.find()) { // если есть совпадения
            matcher.group(0);
        }

        // --------------------------------




        // ===========================================
        //            Работа со строками
        
        // Ввод строки
        Scanner s = new Scanner(System.in);
        System.out.print("Введите строку: ");
        String str = s.nextLine();

        // Проход по строке, разделение на лексемы
        String mainStr, seoarator, token;

        StringTokenizer pch = new StringTokenizer(mainStr, separator);
        while(pch.hasMoreTokens()) {
            token = pch.nextToken();
        }

        // --------------------------------


        // ===========================================
        //              BigInteger, BigDecimal
        int k = 4;
        BigInteger k_big = BigInteger.valueof(k);

        
        

    }
}