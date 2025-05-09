import java.net.*;
import java.io.*;

public class socketserver {
    private Socket socket = null;
    private ServerSocket server = null;
    private DataInputStream in = null;
    private DataOutputStream out = null;
    private BufferedReader console = null;

    public socketserver(int port) {
        try {
            server = new ServerSocket(port);
            System.out.println("Server started");
            System.out.println("Waiting for a client...");

            socket = server.accept();
            System.out.println("Client connected");

            in = new DataInputStream(new BufferedInputStream(socket.getInputStream()));
            out = new DataOutputStream(socket.getOutputStream());
            console = new BufferedReader(new InputStreamReader(System.in));

            String received = "", toSend = "";

            while (!received.equals("over")) {
                received = in.readUTF();
                System.out.println("From Client: " + received);

                System.out.print("To Client: ");
                toSend = console.readLine();
                out.writeUTF(toSend);
            }

            System.out.println("Closing connection");
            socket.close();
            in.close();
            out.close();
            console.close();
        } catch (IOException i) {
            System.out.println(i);
        }
    }

    public static void main(String args[]) {
        new socketserver(8052);
    }
}
