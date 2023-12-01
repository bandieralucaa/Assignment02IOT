package main;
import javax.swing.*;

import java.awt.*;


public class Gui extends JFrame implements View {
    
    static int index = 0;

    private JButton button;

    private EasyControllerObserver c;

    private JTextField cars;
    private JTextField temp;
    private JTextField state;
    private JTextField message;

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
        add(createLabeledTextField("Message:"));


    
        button = new JButton("Problem solved");
        button.setFont(new Font("Arial", Font.PLAIN, 20));
        add(Box.createVerticalGlue());  
        add(button);

        button.addActionListener(e -> {
            System.out.println("BHBH");
            c.notifySolvedProblem();
            this.button.setEnabled(false);
        });        
        button.setEnabled(false);

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

        switch (index) {
            case 0:
                this.cars = textField;
                break;
            
            case 1:
                this.temp = textField;
                break;
        
            case 2:
                this.state = textField;
                break;

            case 3:
                this.message = textField;
                break;
        
            default:
                break;
        }

        index++;
        return panel;
    }


public void setController(EasyControllerObserver c){
    this.c = c;
}


public void updateTemp(double newTemp){
    this.temp.setText(Double.toString(newTemp));
}

public void updateCars(int newAmount){
    this.cars.setText(Integer.toString(newAmount));
}

public void updateState(String newState){
    this.state.setText(newState);
}

public void refresh(){}


public void printMessage(String state, String msg) {
    this.message.setText(msg);
    this.state.setText(state);
}


@Override
public void printError(String state, String error) {
    printMessage(state, error);
    this.button.setEnabled(true);
}

}
