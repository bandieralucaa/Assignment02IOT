import main.PCController;

public class Launcher{
    
	public static void main(String[] args) throws Exception {
		new PCController(args[0], 9600);
	}
}
