import java.io.IOException;

public interface Writer {
    public void write(String thing) throws IOException;
    public void close() throws IOException;
}
