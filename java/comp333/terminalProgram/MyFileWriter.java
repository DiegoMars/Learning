import java.io.FileWriter;
import java.io.File;
import java.io.IOException;

public class MyFileWriter implements Writer {
    private final FileWriter writer;

    public MyFileWriter(String fileName) throws IOException {
        // Write to terminal
        writer = new FileWriter(new File(fileName));
    }

    public void write(String thing) throws IOException {
        writer.write(thing);
    }

    public void close() throws IOException {
        writer.close();
    }
}
