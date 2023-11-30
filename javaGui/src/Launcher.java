import main.PCController;

public class Launcher{
    
	public static void main(String[] args) throws Exception {
		new PCController(args[0], 9600);
		// channel = new SerialCommChannel(args[0],9600);	
		// // CommChannel channel = new SerialCommChannel("/dev/cu.usbmodem1411",9600);	
		// // CommChannel channel = new SerialCommChannel("/dev/cu.isi00-DevB",9600);	
		
		// /* attesa necessaria per fare in modo che Arduino completi il reboot */
		// System.out.println("Waiting Arduino for rebooting...");		
		// Thread.sleep(4000);
		// System.out.println("Ready.");		

		
		// while (true){
		// 	System.out.println("Sending ping");
		// 	channel.sendMsg("ping");
		// 	String msg = channel.receiveMsg();
		// 	System.out.println("Received: "+msg);	
        //     if (msg.equals("pong")){
        //         System.out.println("\n\n\n");
        //     }	
		// 	Thread.sleep(500);
		// }
	}

	// @Override
	// public void notifySolvedProblem() {
	// 	String mess = "o-";
	// 	channel.sendMsg("ping");
	// 	// TODO Auto-generated method stub
	// 	throw new UnsupportedOperationException("Unimplemented method 'notifySolvedProblem'");
	// }

}
