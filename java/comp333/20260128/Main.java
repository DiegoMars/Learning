import java.io.FileWriter;
import java.io.File;
import java.io.IOException;

public class Main {
	// Simplyfying method
	public static void write(String fileName, String thing) throws IOException {
		if (fileName == null){
			// Write to terminal
			System.out.println(thing);
		} else {
			// write to file
			// With this code, this repeatably opens the file (meaning it deletes
			// it if already exists and creates a new one of the same name). Typically
			// you only open it once
			FileWriter writer = new FileWriter(new File(fileName));
			writer.write(thing);
			writer.close();
		}
	}

	public static int doComputation(String fileName) throws IOException {
		// Talks about how there is no indicator for progress which
		// if common when there is something that runs for a long time
		int retval = 0;
		for (; retval < 10000; retval++){
			if (retval % 100 == 0) {
				// Here is something that writes depending on what the
				// output is wanted
				write(fileName, "" + retval);
			}
		}
		return retval;
	}

	// Gives back name of file to write to or null
	// if we are to write to the terminal
	public static String getFileName(String[] args) {
		if (args.length < 0) {
			return args[0];
		} else {
			return null;
		}
	}

	public static void main(String[] args) throws IOException {
		String fileName = getFileName(args);
		int result = doComputation(fileName);
		write(fileName, "" + result);
	}
}
