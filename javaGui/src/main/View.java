package main;


public interface View {

    void setController(EasyControllerObserver c);


    void updateTemp(double newTemp);

    void updateCars(int newAmount);

    void updateState(String newState);

    void refresh();

}
