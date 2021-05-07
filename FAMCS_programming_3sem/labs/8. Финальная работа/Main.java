/*
8 лабораторная работа
Найдович Олег
3 Вариант

Задание:
1. Создать файлы для хранения данных , в каждом - не меньше 6 записей (предметов, людей и т.д).
Для каждого поля типа String в файле должно быть выделено по максимуму одинаковое количество байт во всех строках.
2. Данные для коллекций (List  или Map). читаются из текстового файла.
3. Создать абстрактные классы, создать классы-наследники, которые переопределяет некоторые методы (хотя бы 1 метод).
4. Разработать собственные интерфейсы и реализовать их методы.
5. Использовать для частичного чтения и изменения информации в файле класс RandomAccessFile, использовать метод seek.
6.	Использовать сериализацию объектов в(из) бинарный формат (файл).
7.	Использовать сериализацию объектов в(из) XML формат(а). Использовать XStream или XMLEncoder/XMLDecoder.
8.	Использовать запись в XML формат с помощью DOM.

4. Ипподром
Управление ипподромом должно иметь сведения о лошадях:
кличка лошади, возраст, стаж участия в соревнованиях, владелец, дата рождения

 */

package com.company;

import com.thoughtworks.xstream.XStream;
import com.thoughtworks.xstream.io.xml.DocumentReader;
import com.thoughtworks.xstream.io.xml.DomDriver;
import com.thoughtworks.xstream.security.AnyTypePermission;

import java.io.*;
import java.util.ArrayList;

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


class Serialization {
    public void write_to_binary(String path, HorseStorage horses) throws IOException {
        ObjectOutputStream output = new ObjectOutputStream(new FileOutputStream(path));
        output.writeObject(horses);
        output.close();
    }

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

    public HorseStorage read_from_xml(String path) throws IOException, ClassNotFoundException {
        XStream xstream = new XStream(new DomDriver());
        xstream.addPermission(AnyTypePermission.ANY);
        HorseStorage horses = new HorseStorage();
        xstream.alias("HorseStorage", HorseStorage.class);
        xstream.alias("Horse", Horse.class);
        horses = ((HorseStorage) xstream.fromXML(new File(path)));
        return horses;
    }

    public void write_to_xml_dom(String path, HorseStorage horses) throws ParserConfigurationException, TransformerException {

        DocumentBuilderFactory docFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder docBuilder = docFactory.newDocumentBuilder();

        // root elements
        Document doc = docBuilder.newDocument();
        Element rootElement = doc.createElement("HorseStorage");
        doc.appendChild(rootElement);


        for (int i = 0; i < horses.storage.size(); i++) {

            // staff elements
            Element horse = doc.createElement("Horse");
            rootElement.appendChild(horse);

            Attr attr = doc.createAttribute("id");
            attr.setValue(String.valueOf(i));
            horse.setAttributeNode(attr);

            // name
            Element name = doc.createElement("name");
            name.appendChild(doc.createTextNode(horses.storage.get(i).name));
            horse.appendChild(name);

            // year
            Element year = doc.createElement("year");
            name.appendChild(doc.createTextNode(horses.storage.get(i).year));
            horse.appendChild(year);

            // experience
            Element experience = doc.createElement("experience");
            name.appendChild(doc.createTextNode(horses.storage.get(i).experience));
            horse.appendChild(experience);

            // owner
            Element owner = doc.createElement("owner");
            name.appendChild(doc.createTextNode(horses.storage.get(i).owner));
            horse.appendChild(owner);

            // data_owner
            Element data_owner = doc.createElement("data_owner");
            name.appendChild(doc.createTextNode(horses.storage.get(i).data_owner));
            horse.appendChild(data_owner);

        }

        // write to content to xml file
        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = null;
        try {
            transformer = transformerFactory.newTransformer();
        } catch (TransformerConfigurationException e) {
            e.printStackTrace();
        }
        DOMSource source = new DOMSource(doc);
        StreamResult result = new StreamResult(new File(path));
        transformer.transform(source, result);

    }
}

interface Storage {
    public void printAll();
    public void add_object(Object object);
}

// абстрактный класс "Animal"
abstract class Animal implements Serializable {

    public String name;         // кличка лошади
    public String year;         // возраст лошади
    public String owner;        // имя владелеца
    public String data_owner;   // дата рождения владельца

    public Animal(String name, String year, String data_owner, String owner) {
        this.name = name;
        this.year = year;
        this.owner = owner;
        this.data_owner = data_owner;
    }

    public void print() {
        System.out.print(this.name + this.year +
                this.owner + this.data_owner + "\n");
    }
}

// абстрактный класс "AnimalStorage", который является хранилищем для множества классов "Animal"
abstract class AnimalStorage implements Serializable {

    public ArrayList<Animal> storage;

    public void add_object(Object object) {
        storage.add((Animal) object);
    }

    public void printAll() {
        System.out.print("\nОбъекты нашего хранилища:\n");
        storage.forEach(horse -> horse.print());
    }

}


// Класс "Horse", унаследованный от абстрактного класса "Animal"
class Horse extends Animal implements Serializable {

    public String experience;   // стаж участия в соревнованиях

    public Horse(String name, String year, String data_owner, String owner, String experience) {
        super(name, year, data_owner, owner);
        this.experience = experience;
    }

    public void print() {
//        System.out.print(this.name + "\t" + this.year + "\t" +
//                this.experience + "\t" + this.owner + "\t" + this.data_owner);
        System.out.print(this.name + this.year +
                this.experience + this.owner + this.data_owner + "\n");
    }

    public static Horse strToHorse(String str) {
        return new Horse(str.substring(0, 14),  // name
                str.substring(14, 24),          // year
                str.substring(54, 64),          // data_owner
                str.substring(34, 54),          // owner
                str.substring(24, 34));         // experience
    }
}

// Класс "HorseStorage", унаследованный от абстрактного класса "AnimalStorage",
// который вляется хранилищем для множества классов "Horse"
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

    public void readFromFile(String path) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "r");
        String str = file.readLine();
        while (str != null) {
            this.storage.add(Horse.strToHorse(str));
            str = file.readLine();
        }
        file.close();
    }

    // читает определенные строки из файла
    public void readFromFile_From_to(int num1, int num2, String path) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "rw");
        String str;
        int i = num1;
        file.seek((num1 - 1) * 65);
        str = file.readLine();
        while (i != num2 + 1) {
            this.storage.add(Horse.strToHorse(str));
            str = file.readLine();
            i++;
        }
    }


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

    public void rewriteToFile(String path, Horse ex) throws IOException {
        RandomAccessFile file = new RandomAccessFile(path, "rw");
        file.seek((this.storage.size() - 1) * 65);
        file.write((ex.name + ex.year + ex.experience +
                ex.owner + ex.data_owner + "\n").getBytes());
        file.close();
    }

    public void write_bin(String path) throws IOException {
        Serialization serial = new Serialization();
        serial.write_to_binary(path, this);
    }

    public void readFromBin(String path) throws IOException, ClassNotFoundException {
        Serialization serial = new Serialization();
        this.storage.addAll(serial.read_from_binary(path).storage);
    }


    public void write_xml(String path) throws IOException {
        Serialization serial = new Serialization();
        serial.write_to_xml(path, this);
    }

    public void read_xml(String path) throws IOException, ClassNotFoundException {
        Serialization serial = new Serialization();
        this.storage.addAll(serial.read_from_xml(path).storage);
    }


    public void write_xml_dom(String path) throws ParserConfigurationException, TransformerException {
        Serialization serial = new Serialization();
        serial.write_to_xml_dom(path, this);
    }
}


public class Main {

    public static void main(String[] args) throws IOException, ClassNotFoundException, ParserConfigurationException, TransformerException {

        HorseStorage horses = new HorseStorage();    // создаем хранилище(Б.Д.) для класса лошадей
        horses.readFromFile("input.txt");      // заносим данные из файла input в хранилище
        horses.printAll();                           // выводим все данные на консоль
        horses.writeToFile("output.txt");      // выводим все данные в файл


        // проверка на добавление одного элемента в БД
        Horse example_horse = new Horse("Mars          ", "14        ",
                "02.05.1975", "Alex Grand          ", "4         "); // пример новой лошади

        horses.add_object(example_horse); // добавляем новую лошадь в хранилище
        horses.rewriteToFile("output.txt", example_horse); // дописываем в файл новую лошадь
        System.out.print("\nДобовляем в нашу БД новые данные и выводим:");
        horses.printAll(); // выводим все данные на консоль


        // реализуем частичное чтение на примере нового храшилища
        HorseStorage horses_ex_2 = new HorseStorage();

        horses_ex_2.readFromFile_From_to(2, 3, "output.txt"); // читает определенные строки из файла

        System.out.print("\nПроверка частичного считывания данных:");
        horses_ex_2.printAll(); // выводим все данные на консоль


        // реализуем запись и считывание бинарного файла
        HorseStorage horses_ex_3 = new HorseStorage(); // для проверки считывания с bin файла

        horses_ex_2.write_bin("output.bin");    // записываем в бинарный файл (используя сериализацию)
        horses_ex_3.readFromBin("output.bin");  // читаем с бинарного файла   (используя десериализацию)

        System.out.print("\nПроверка на считывание и запись bin файла:");
        horses_ex_3.printAll();


        // реализуем запись и считывание xml файла
        HorseStorage horses_ex_4 = new HorseStorage(); // для проверки считывания с xml файла

        horses_ex_2.write_xml("output.xml");
        horses_ex_4.read_xml("output.xml");

        System.out.print("\nПроверка на считывание и запись xml файла:");
        horses_ex_3.printAll();

        // реализуем запись в xml файл через DOM
        horses_ex_2.write_xml_dom("output_dum.xml");

    }
}
