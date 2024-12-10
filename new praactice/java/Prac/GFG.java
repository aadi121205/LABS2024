
// Java program using label (swing)
// to display the message “GFG WEB Site Click”
import java.io.*;
import javax.swing.*;
import java.util.Scanner;

// Main class
class GFG {
    public static void ReadFile(String filename) {
        try {
            File myObj = new File(filename);
            Scanner myReader = new Scanner(myObj);
            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                System.out.println(data);
            }
            myReader.close();
        } catch (FileNotFoundException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }

    // Main driver method
    public static void main(String[] args) {

        ReadFile("/home/aadi/Projects/LABS2024/new praactice/java/Prac/input.txt");
        // Creating instance of JFrame
        JFrame frame = new JFrame();

        // Creating instance of JButton
        JButton button = new JButton(" GFG WebSite Click");

        // x axis, y axis, width, height
        button.setBounds(200, 150, 200, 40);

        // adding button in JFrame
        frame.add(button);

        // Setting Frame width and height
        frame.setSize(600, 400);
        // Adding action listener to the button
        button.addActionListener(e -> {
            JOptionPane.showMessageDialog(frame, "GFG WebSite Click");
        });

        // using no layout managers
        frame.setLayout(null);

        // making the frame visible
        frame.setVisible(true);

        // Reading file
    }
}