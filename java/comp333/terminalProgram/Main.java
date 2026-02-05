import java.io.IOException;

public class Main {
	// public static FileWriter writer = null;
	//
	// // Simplyfying method
	// public static void write(String fileName, String thing) throws IOException {
	// 	if (fileName == null){
	// 		// Write to terminal
	// 		System.out.println(thing);
	// 	} else {
	// 		// write to file
	// 		// With this code, this repeatably opens the file (meaning it deletes
	// 		// it if already exists and creates a new one of the same name). Typically
	// 		// you only open it once
	// 		if (writer == null){
	// 			writer = new FileWriter(new File(fileName));
	// 		}
	// 		writer.write(thing);
	// 	}
	// }

	public static int doComputation(Writer writer) throws IOException {
		// Talks about how there is no indicator for progress which
		// if common when there is something that runs for a long time
		int retval = 0;
		for (; retval < 10000; retval++){
			if (retval % 100 == 0) {
				// Here is something that writes depending on what the
				// output is wanted
				writer.write("" + retval);
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
		Writer writer;
		// This doesn't work with overloading, not as intended at least
		if (fileName == null) {
			writer = new TerminalWriter();
		} else {
			writer = new MyFileWriter(fileName);
		}
		int result = doComputation(writer);
		writer.write("" + result);
		writer.close();
	}
}
