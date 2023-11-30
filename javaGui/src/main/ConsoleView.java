package main;


public class ConsoleView implements View {

    private EasyControllerObserver c;
    private double temp;
    private int cars;
    private String state;
    private String msg;

    @Override
    public void setController(EasyControllerObserver c) {
        this.c = c;
    }

    @Override
    public void updateTemp(double newTemp) {
        this.temp = newTemp;
    }

    @Override
    public void updateCars(int newAmount) {
        this.cars = newAmount;
    }

    @Override
    public void updateState(String newState) {
        this.state = newState;
    }

    @Override
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
    public void printMessage(String msg) {
        this.msg = msg;
    }

    @Override
    public void printError(String error) {
        // TODO Auto-generated method stub
        throw new UnsupportedOperationException("Unimplemented method 'printError'");
    }
    
}
