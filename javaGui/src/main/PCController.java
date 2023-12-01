package main;
import java.util.Arrays;
import java.util.Map;

import comm.CommChannel;
import comm.SerialCommChannel;
import main.View;
import main.Gui;
import main.EasyControllerObserver;

public class PCController implements EasyControllerObserver{

    private static final int AMOUNT = 5;
    
    private CommChannel channel;
    private View myView;
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
        //myView = new ConsoleView();
        myView = new Gui();
        this.myView.setController(this);

        System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		

       // int i = 0;
		
		while (true){
			//System.out.println("Sending ping");
			//channel.sendMsg("ping");

            /*while (this.channel.isMsgAvailable() && i<AMOUNT) {
            while (this.channel.isMsgAvailable()) {
                byStringToCommand(this.channel.receiveMsg());
                i++;
            }*/
            if(this.channel.isMsgAvailable()){
                this.executeCommand(this.channel.receiveMsg());
            }
			//String msg = channel.receiveMsg();
			//System.out.println("Received: "+msg);	
            //if (msg.equals("pong")){
            //    System.out.println("\n\n\n");
            //}	
            this.myView.refresh();
			Thread.sleep(200);
            //i = 0;
		}
    }

    @Override
    public void notifySolvedProblem() {
        channel.sendMsg("_o:l");
    }

    private void byStringToCommand(String command, String argument){
       // if (input.length() > 2) {
          //  String argument = input.substring(2);

            switch (command.charAt(0)) {
                case 'c':
                    this.myView.updateCars(Integer.parseInt(argument));
                    break;
                
                // case 's':
                //     this.myView.updateState(argument);
                //     break;
            
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
      //  }
    }


    public void executeCommand(String command) {
        if (!command.contains("_")){
            return;
        }
        System.out.println("## " + command);
        String[] singleCommand = command.split("_");
        Arrays.stream(singleCommand).forEach(s -> System.out.println(s));
        String[] singleMessage;

        for (String string : singleCommand) {
            if(!string.isEmpty()){
                System.out.println(string);
                singleMessage = string.split(":");
                Arrays.stream(singleMessage).forEach(s -> System.out.println("-> " + s));
                byStringToCommand(singleMessage[0], singleMessage[1]);
                System.out.println();
            }

        }

    }

    


}
