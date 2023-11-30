package main;
import comm.CommChannel;
import comm.SerialCommChannel;
import main.View;
import main.Gui;
import main.EasyControllerObserver;

public class PCController implements EasyControllerObserver{

    private static final int AMOUNT = 5;
    
    private CommChannel channel;
    private View myView;

    public PCController(String protName, int baudRate) throws Exception {
        channel = new SerialCommChannel(protName, baudRate);
        //myView = new ConsoleView();
        myView = new Gui();
        this.myView.setController(this);

        System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		

        int i = 0;
		
		while (true){
			//System.out.println("Sending ping");
			//channel.sendMsg("ping");

            /*while (this.channel.isMsgAvailable() && i<AMOUNT) {
            while (this.channel.isMsgAvailable()) {
                byStringToCommand(this.channel.receiveMsg());
                i++;
            }*/
            this.executeCommand(this.channel.receiveMsg());
			//String msg = channel.receiveMsg();
			//System.out.println("Received: "+msg);	
            //if (msg.equals("pong")){
            //    System.out.println("\n\n\n");
            //}	
            this.myView.refresh();
			Thread.sleep(500);
            i = 0;
		}
    }

    @Override
    public void notifySolvedProblem() {
        channel.sendMsg("o-");
    }

    private void byStringToCommand(String command, String argument){
       // if (input.length() > 2) {
          //  String argument = input.substring(2);
            switch (command.charAt(0)) {
                case 'c':
                    this.myView.updateCars(Integer.parseInt(argument));
                    break;
                
                case 's':
                    this.myView.updateState(argument);
                    break;
            
                case 't':
                    this.myView.updateTemp(Double.parseDouble(argument));
                    break;

                case 'e':
                    this.myView.printError(argument);

                case 'm':
                    this.myView.printMessage(argument);
                
                default:
                    break;
            }
      //  }
    }


    public void executeCommand(String command) {
        String[] singleCommand = command.split("$");
        String[] singleMessage;

        for (String string : singleCommand) {
            singleMessage = string.split("\\.");

            byStringToCommand(singleMessage[0], singleMessage[1]);


        }

    
        
       
    }

    


}
