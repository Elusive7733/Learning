import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Objects;
import java.util.Scanner;

public class K180170_Server {

    public static boolean clientAuthenticated = false;
    public static void main(String[] args) throws IOException {

        Socket s;
        try (ServerSocket ss = new ServerSocket(5001)) {
            s = ss.accept();

            System.out.println("Client Connected");

            // Variables to GET / POST information to the Client
            InputStreamReader in = new InputStreamReader(s.getInputStream());
            BufferedReader bf = new BufferedReader(in);
            PrintWriter pw = new PrintWriter(s.getOutputStream());


            //Authenticate Client
            authenticateClient(pw, bf);

            // Receive a Message if the Client is Authenticated
            if(clientAuthenticated) {
                //Expecting a message from Client
                receiveMessage(bf);

                //Sending a Response to the Client
                sendMessage(pw, "Message Received");
            }
            else{
                System.out.println("404-Invalid User");
            }

        }
    }

    private static boolean isUserValid(String user) throws IOException {
        //Reading the file / DB to check for Valid Users
        File f = new File("C:\\Users\\Elusive\\IdeaProjects\\EH-K180170\\src\\users.txt");

        for(Scanner sc = new Scanner(f); sc.hasNext(); )
        {
            String line = sc.nextLine();
            if(Objects.equals(line, user)) {
                return true; // Returns if a Valid User is found
            }
        }
        return false; // Returns if no Valid User found
    }

    private static void authenticateClient(PrintWriter pw, BufferedReader bf) throws IOException {
        String user = bf.readLine();

        //Checking is the user is Valid
        if(isUserValid(user)) {
            clientAuthenticated = true;
            pw.println("200 - Client Authenticated");
            pw.flush();
        }
        else{
            pw.println("404 - Invalid User");
            pw.flush();
        }
    }

    //Utility Function for sending a message
    private static void sendMessage(PrintWriter pw, String message) throws IOException {
        pw.println(message);
        pw.flush();
    }

    //Utility Function for receiving a message
    private static void receiveMessage(BufferedReader bf) throws IOException {
        String clientMsg = bf.readLine();
        System.out.println("client: " + clientMsg);
    }
}
