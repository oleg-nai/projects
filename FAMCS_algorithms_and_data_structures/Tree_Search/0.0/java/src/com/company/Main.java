package com.company;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner; // Import the Scanner class to read text files
import java.util.TreeSet;
//import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        TreeSet<Long> massive = new TreeSet<Long>();
//        ArrayList<Long> massive = new ArrayList<Long>();
        BigInteger sum = BigInteger.valueOf(0);
        String check = "";
        long data_int;
        try {
            File fin = new File("input.txt");
            Scanner reader = new Scanner(fin);
            while (reader.hasNextLine()) {
                check = reader.nextLine();
                if(check.equals(""))
                    break;
                data_int = Long.valueOf(check);
                if (massive.contains(data_int))
                    continue;
                massive.add(data_int);
                sum = sum.add(BigInteger.valueOf(data_int));
            }
            reader.close();
        }
        catch (FileNotFoundException e) { }

        try{
            FileWriter fout = new FileWriter("output.txt");
            fout.write(sum.toString());
            fout.close();
        }
        catch (IOException e) { }

    }
}