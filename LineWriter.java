// LineWriter.java

import java.io.*;

/* @author Richard Stegman
 * @version 2.1, 1/5/07
 * 
 * LineWriter provides simple methods for opening and writing to text files.
 * 
 * Example:
 * 
 *      LineWriter lw = new LineWriter(foo.txt");
 *      lw.println("This is a string.");
 *      lw.println();
 *      lw.println(108);
 *      lw.close(); 
 *
 */

public class LineWriter {
    private PrintWriter outFile;
    
    /*
     * LineWriter constructor. 
     * Creates a new file or overwrites an existing file.
     * @param fileName name of the file to be created
     */
    
    public LineWriter(String fileName) {
        try {
            FileWriter fw = new FileWriter(fileName);
            BufferedWriter bw = new BufferedWriter(fw);
            outFile = new PrintWriter(bw);
        }    
        catch (IOException e) {
            System.out.println("LineWriter cannot open output file: " + fileName);
            e.printStackTrace();
        }
    }

    /*
     * LineWriter constructor. 
     * Creates a new file. If the file exists can append to it.
     * @param fileName name of the file to be created
     * @param mode if equal to "a" opens in append mode
     */
    
    public LineWriter(String fileName, String mode) {
        try {
            FileWriter fw = new FileWriter(fileName, "a".equals(mode));
            BufferedWriter bw = new BufferedWriter(fw);
            outFile = new PrintWriter(bw);
        }    
        catch (IOException e) {
            System.out.println("LineWriter cannot open output file: " + fileName);
            e.printStackTrace();
        }
    }

    /**
     * Outputs a string and newline to the file.
     * @param s string to be output
     */
     
    public void println(String s) {
        outFile.println(s);
    }

    /**
     * Outputs a string to the file.
     * @param s string to be output
     */
     
    public void print(String s) {
        outFile.print(s);
    }

    /**
     * Outputs an integer and newline to the file.
     * @param i integer to be output
     */
     
    public void println(int i) {
        outFile.println(i);
    }

    /**
     * Outputs an integer to the file.
     * @param i integer to be output
     */
     
    public void print(int i) {
        outFile.print(i);
    }

    /**
     * Outputs a long and newline to the file.
     * @param l long to be output
     */
     
    public void println(long l) {
        outFile.println(l);
    }

    /**
     * Outputs a long to the file.
     * @param l long to be output
     */
     
    public void print(long l) {
        outFile.print(l);
    }

     /**
     * Outputs a short and newline to the file.
     * @param s short to be output
     */
     
    public void println(short s) {
        outFile.println(s);
    }

    /**
     * Outputs a short to the file.
     * @param s short to be output
     */
     
    public void print(short s) {
        outFile.print(s);
    }
    
    /**
     * Outputs a byte and newline to the file.
     * @param b byte to be output
     */
     
    public void println(byte b) {
        outFile.println(b);
    }

    /**
     * Outputs a byte to the file.
     * @param b byte to be output
     */
     
    public void print(byte b) {
        outFile.print(b);
    }
    
    /**
     * Outputs a boolean and newline to the file.
     * @param b boolean to be output
     */
     
    public void println(boolean b) {
        outFile.println(b);
    }

    /**
     * Outputs a boolean to the file.
     * @param b boolean to be output
     */
     
    public void print(boolean b) {
        outFile.print(b);
    }

    /**
     * Outputs a float and newline to the file.
     * @param f float to be output
     */
     
    public void println(float f) {
        outFile.println(f);
    }

    /**
     * Outputs a float to the file.
     * @param f float to be output
     */
     
    public void print(float f) {
        outFile.print(f);
    }

    /**
     * Outputs a double and newline to the file.
     * @param d double to be output
     */
     
    public void println(double d) {
        outFile.println(d);
    }

    /**
     * Outputs a double to the file.
     * @param d double to be output
     */
     
    public void print(double d) {
        outFile.print(d);
    }

    /**
     * Outputs a character and newline to the file.
     * @param c char to be output
     */
     
    public void println(char c) {
        outFile.println(c);
    }

    /**
     * Outputs a character to the file.
     * @param c char to be output
     */
     
    public void print(char c) {
        outFile.print(c);
    }

    /**
     * Outputs an object and newline to the file.
     * @param o object to be output
     */
     
    public void println(Object o) {
        outFile.println(o);
    }

    /**
     * Outputs an object to the file.
     * @param o object to be output
     */
     
    public void print(Object o) {
        outFile.print(o);
    }
    
    /**
     * Outputs a newline character to the file.
     */
     
    public void println() {
        outFile.println();
    }

    /**
     * Closes the file.
     */
     
    public void close() {
        outFile.flush();
        outFile.close();
    }
}