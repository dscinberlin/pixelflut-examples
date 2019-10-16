import java.net.*;
import java.io.*;

public class PixelflutClient {
    static PrintWriter writer;
    static Socket socket;

    static void setPixel(int x, int y, String color) {
        writer.println("CC " +  x + " " + y + " " + color);
    }

    public static void main(String[] args) {
        String hostname = "35.234.105.190";
        int port = 1234;
 
        try {
            socket = new Socket(hostname, port);
            var output = socket.getOutputStream();
            writer = new PrintWriter(output, true);

        } catch (UnknownHostException ex) {
 
            System.out.println("Server not found: " + ex.getMessage());
 
        } catch (IOException ex) {
 
            System.out.println("I/O error: " + ex.getMessage());
        }

        for(int x = 0; x < 1920; x++) {
            for(int y = 0; y < 1080; y++) {
                setPixel(x, y, "FF00BB");
            }
        }


    }
}