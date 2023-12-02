package main;

import java.util.Map;

public class ConsoleView implements View {

    private EasyControllerObserver c;
    private double temp;
    private int cars;
    private String state;
    private String msg;

    
    public void setController(EasyControllerObserver c) {
        this.c = c;
    }

   
    public void updateTemp(double newTemp) {
        this.temp = newTemp;
    }


    public void updateCars(int newAmount) {
        this.cars = newAmount;
    }

  
    public void updateState(String newState) {
        this.state = newState;
    }

    
    public void refresh() {
        System.out.println(this.state);
        System.out.println(this.cars);
        System.out.println(this.temp);
        System.out.println(this.msg);
    }

    public void send(){
        this.c.notifySolvedProblem();
    }


    @Override
    public void printMessage(String state, String msg) {
        this.msg = msg;
        this.state = state;
    }


    @Override
    public void printError(String state, String error) {
        printMessage(state, error);
        //sistema che abilita un sistema di avviso ad Arduino che è stato risolto il problema
    }
    
}
