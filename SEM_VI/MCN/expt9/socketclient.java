
import java.net.*;
import java.io.*;

public class socketclient {
    private Socket socket = null;
    private BufferedReader input = null;
    private DataOutputStream out = null;
    private DataInputStream in = null;

    public socketclient(String address, int port) {
        try {
            socket = new Socket(address, port);
            System.out.println("Connected to Server");

            input = new BufferedReader(new InputStreamReader(System.in));
            out = new DataOutputStream(socket.getOutputStream());
            in = new DataInputStream(socket.getInputStream());

            String toSend = "", received = "";

            while (!toSend.equals("over")) {
                System.out.print("To Server: ");
                toSend = input.readLine();  // Now using BufferedReader
                out.writeUTF(toSend);

                received = in.readUTF();
                System.out.println("From Server: " + received);
            }

            input.close();
            out.close();
            in.close();
            socket.close();
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        new socketclient("localhost", 8052);
    }
}
