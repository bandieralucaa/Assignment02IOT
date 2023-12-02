package main;


public interface View {

    void setController(EasyControllerObserver c);

    void updateTemp(double newTemp);

    void updateCars(int newAmount);

    void updateState(String newState);

    void refresh();

    void printMessage(String state, String msg);

    void printError(String state, String error);

}
