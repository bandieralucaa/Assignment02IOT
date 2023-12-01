package main;


public class ConsoleView {

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

    
    public void printMessage(String msg) {
        this.msg = msg;
    }

    
    public void printError(String error) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printError'");
    }
    
}
