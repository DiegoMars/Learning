import java.io.IOException;

public class TerminalWriter implements Writer {
    public TerminalWriter() {}

    public void write(String thing) throws IOException {
        System.out.println(thing);
    }

    public void close() throws IOException {}
}
