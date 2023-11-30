package javaGui;

import javax.swing.*;
import java.awt.*;

public class Gui extends JFrame {
    private JButton button;

    public Gui() {
        setTitle("Car Washing Machine");

        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();

        int width = (int) (screenSize.getWidth() * 0.75);
        int height = (int) (screenSize.getHeight() * 0.75);
        setSize(width, height);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));

        add(createLabeledTextField("Amount car washed:"));
        add(createLabeledTextField("Temperature value:"));
        add(createLabeledTextField("Actual state of car washing machine:"));

        button = new JButton("Problem solved");
        button.setFont(new Font("Arial", Font.PLAIN, 20));
        add(Box.createVerticalGlue());  
        add(button);

        setLocationRelativeTo(null); 
        setVisible(true);
    }

   
private JPanel createLabeledTextField(String labelText) {
    JPanel panel = new JPanel();
    panel.setLayout(new FlowLayout(FlowLayout.LEFT));

    JLabel label = new JLabel(labelText);
    label.setFont(new Font("Arial", Font.PLAIN, 20));
    JTextField textField = new JTextField(15);
    textField.setFont(new Font("Arial", Font.PLAIN, 20));
    textField.setEditable(false);

    panel.add(label);
    panel.add(textField);

    return panel;
}
}
