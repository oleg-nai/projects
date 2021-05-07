package com.company;

import java.io.*;
import java.util.*;


// Найдович ОЛег. 4 вариант. 7группа


class sort_students implements Comparator<Student> {
    @Override
    public int compare(Student o1, Student o2) {

        int i = o1.first_name.compareTo(o2.first_name);
        if (i == 0) {
            double i1_d = Double.valueOf(o1.id);
            double i2_d = Double.valueOf(o2.id);
            if (i1_d > i2_d)
                return 1;
            else if (i1_d == i2_d)
                return 0;
            else
                return -1;
        } else if (i > 1) {
            return 1;
        } else if (i < 0)
            return -1;
        return 0;
    }
}

interface Storage {
    public String toString();

    public void print_list();
}

class Student {

    //    фамилия, имя, дата рождения(число месяца,месяц,год),
//    средний бал , идентификационный номер(с буквой Е, е -это запись в экпоненциальном виде).
    public String first_name;
    public String second_name;
    public String date;
    public String average_score;
    public String id;

    public Student(String first_name, String second_name, String date, String average_score, String id) {
        this.first_name = first_name;
        this.second_name = second_name;
        this.date = date;
        this.average_score = average_score;
        this.id = id;
    }

    public Student() {
        this.first_name = null;
        this.second_name = null;
        this.date = null;
        this.average_score = null;
        this.id = null;
    }

    public static Student read_file(String str) {

        // Kuznecov;Ivan 12.15.85;5.0 898998963423412
        // Проход по строке, разделение на лексемы
        Student student = new Student();
        String separator = " ;_";
        String token = "";
        StringTokenizer pch = new StringTokenizer(str, separator);
        int i = 0;
        while (pch.hasMoreTokens()) {
            token = pch.nextToken();
            if (i == 0)
                student.first_name = token;
            if (i == 1)
                student.second_name = token;
            if (i == 2)
                student.date = token;
            if (i == 3)
                student.average_score = token;
            if (i == 4)
                student.id = token;
            i++;
        }
        return student;
    }

    public String getId() {
        return this.id;
    }

    @Override
    public String toString() {
        String str = this.first_name + " " + this.second_name + " " + this.date + " " +
                this.average_score + " " + this.id;
        return str;
    }

    public String toString_map() {
        String str = this.id + "    ----      " + this.first_name + " " + this.second_name + " " + this.date + " " +
                this.average_score;
        return str;
    }

}

class Serialization implements Serializable{
    // запись в бинарный файл файл
    public void write_to_binary(String path, ClassBD stud) throws IOException {
        ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(path));
        output.writeObject(stud);
        output.close();
    }

    // считывание с бинарного файла
    public ClassBD read_from_binary(String path) throws IOException, ClassNotFoundException {
        ClassBD horses = new ClassBD();
        ObjectInputStream input = new ObjectInputStream(new FileInputStream(path));
        horses = (ClassBD) input.readObject();
        input.close();
        return horses;
    }

}


class ClassBD implements Storage {

    public List<Student> storage_list;
    public Map<String, Student> storage_map;


    public ClassBD() {
        storage_list = new ArrayList<Student>();
        storage_map = new HashMap<String, Student>();
    }

    public ClassBD(List<Student> boot) {
        this.storage_list.clear();
        this.storage_list.addAll(boot);
    }

    public ClassBD(Map<String, Student> boot) {
        this.storage_map.clear();
        this.storage_map.putAll(boot);
    }


    public void read_file_list(String path) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "r");
        String str = file.readLine();
        while (str != null) {
            this.storage_list.add(Student.read_file(str));
            str = file.readLine();
        }
        file.close();
    }

    public void read_file_map(String path) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "r");
        String str = file.readLine();
        while (str != null) {
            Student student = Student.read_file(str);
            this.storage_map.put(student.id, student);
            str = file.readLine();
        }
        file.close();
    }

    public void sort_list_comparatop() {
        Collections.sort(this.storage_list, new sort_students());
    }

    @Override
    public String toString() {
        String str = null;
        for (Student tmp : storage_list) {
            str += tmp.toString() + "\n";
        }
        return str;
    }

    public String toString_map() {
        String str = null;
        for (Student tmp : storage_list) {
            str += tmp.toString_map() + "\n";
        }
        return str;
    }

    // запись в файл
    public void writeToFile(String path) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "rw");
        String str;
        for (Student item : this.storage_list) {
            str = item.toString();
            file.write(str.getBytes());
        }
        file.close();
    }

    public void write_bin(String path) throws IOException {
        Serialization serial = new Serialization();
        serial.write_to_binary(path, this);
    }

//    public void readFromBin(String path) throws IOException, ClassNotFoundException {
//        Serialization serial = new Serialization();
//        this.storage.addAll(serial.read_from_binary(path).storage);
//    }

    @Override
    public void print_list() {
        System.out.print(this.toString());
    }

    public void print_map() {
        System.out.print(this.toString_map());
    }
}


public class Main {

    public static void main(String[] args) throws IOException {


        System.out.print("\n----------------------------------------\n");
        System.out.print("Чтение с файла");
        System.out.print("\n----------------------------------------\n");
        ClassBD bd = new ClassBD();
        System.out.print("\nList\n");
        bd.read_file_list("test2.txt");
        bd.print_list();
        System.out.print("\n----------------------------------------\n");
        System.out.print("\nMap\n");
        bd.read_file_map("test2.txt");
        bd.print_map();

        System.out.print("\n----------------------------------------\n");
        System.out.print("Сортировка по компаратору");
        System.out.print("\n----------------------------------------\n");
        bd.sort_list_comparatop();
        bd.print_list();

        System.out.print("\n----------------------------------------\n");
        System.out.print("Запись в файл");
        System.out.print("\n----------------------------------------\n");
        bd.writeToFile("output1.txt");

        System.out.print("\n----------------------------------------\n");
        System.out.print("Запись в бинарный файл");
        System.out.print("\n----------------------------------------\n");

        bd.write_bin("output.bin");
    }
}
