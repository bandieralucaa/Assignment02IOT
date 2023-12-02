package main;
import java.util.Arrays;
import java.util.Map;

import comm.CommChannel;
import comm.SerialCommChannel;

public class PCController implements EasyControllerObserver{
    
    private CommChannel channel;
    private View myView;
    private final static boolean DEBUG = false;
    private Map<String, String> states = Map.of(
        "1", "Empty state",
        "2", "Entering state",
        "3", "Confirm state",
        "4", "Washing state",
        "5", "Error state",
        "6", "Lefting state"
    );;
    private Map<String, String> messages = Map.of(
        "1", "Empty - no car is in washing machine",
        "2", "A new car is entering",
        "3", "Wait user input",
        "4", "Washing car",
        "5", "Maintenance required",
        "6", "Car is washed, left the machine"
    );;
    
    

    public PCController(String protName, int baudRate) throws Exception {
        channel = new SerialCommChannel(protName, baudRate);
        myView = new Gui();
        this.myView.setController(this);

        System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		
		
		while (true){
            if(this.channel.isMsgAvailable()){
                this.executeCommand(this.channel.receiveMsg());
            }
            this.myView.refresh();
			Thread.sleep(150);
		}
    }

    @Override
    public void notifySolvedProblem() {
        if (DEBUG) {
            System.out.println("BHBH");
        }
        this.channel.sendMsg("_o:l");
        if (DEBUG) {
            System.out.println("post send");
        }
    }

    private void byStringToCommand(String command, String argument){
        switch (command.charAt(0)) {
            case 'c':
                this.myView.updateCars(Integer.parseInt(argument));
                break;

            case 't':
                this.myView.updateTemp(Double.parseDouble(argument));
                break;

            case 'e':
                this.myView.printError(states.get(argument), messages.get(argument));
                

            case 'm':
                this.myView.printMessage(states.get(argument), messages.get(argument));
            
            default:
                break;
        }
    }


    public void executeCommand(String command) {
        if (!command.contains("_")){
            return;
        }
        if (DEBUG) {
            System.out.println("## " + command);
        }
        String[] singleCommand = command.split("_");
        Arrays.stream(singleCommand).filter(s-> DEBUG).forEach(s -> System.out.println(s));
        String[] singleMessage;

        for (String string : singleCommand) {
            if(!string.isEmpty() && string.contains(":")){
                if (DEBUG) {
                    System.out.println(string);
                }
                singleMessage = string.split(":");
                Arrays.stream(singleMessage).filter(s-> DEBUG).forEach(s -> System.out.println("-> " + s));
                byStringToCommand(singleMessage[0], singleMessage[1]);
                if (DEBUG) {
                    System.out.println();
                }
            }

        }

    }

}
