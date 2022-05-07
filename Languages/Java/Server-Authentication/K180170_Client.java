import java.io.*;
import java.net.Socket;
import java.util.Objects;
import java.util.Random;
import java.util.Scanner;

public class K180170_Client {

    public static boolean isAuth = false;

    public static void main(String[] args) throws IOException {

        try (Socket s = new Socket("localhost", 5001)) {

            // Variables to GET / POST information to the Server
            InputStreamReader in = new InputStreamReader(s.getInputStream());
            BufferedReader bf = new BufferedReader(in);
            PrintWriter pw = new PrintWriter(s.getOutputStream());


            signIn(pw, bf);

            if(isAuth){
                //Sending a message to Server
                sendMessage(pw,"Hello");

                //Expecting a Response from the server
                receiveMessage(bf);
            }

            else {
                System.out.println("403 - Not Authenticated");
            }
        }
    }

    //Chooses a Random User
    public static String chooseRandomUser(File f) throws FileNotFoundException
    {
        String result = null;
        Random rand = new Random();
        int n = 0;
        for(Scanner sc = new Scanner(f); sc.hasNext(); )
        {
            ++n;
            String line = sc.nextLine();
            if(rand.nextInt(n) == 0)
                result = line;
        }
        return result;
    }

    //Function used to signIn
    private static void signIn(PrintWriter pw, BufferedReader bf) throws IOException {
        String randomUser = chooseRandomUser(new File("C:\\Users\\Elusive\\IdeaProjects\\EH-K180170\\src\\users.txt"));
        System.out.println("Invalid User: " + "AbdullahRaheel");

        //Signing in as a Random User
        pw.println("AbdullahRaheel:Password123");
        pw.flush();

        String response = bf.readLine();
        if(Objects.equals(response, "200 - Client Authenticated")) {
            isAuth = true;
        }
        System.out.println("server: " + response + "\n");
        System.out.println("Authentication Status: " + isAuth);
    }

    //Utility Function for receiving a message
    private static void receiveMessage(BufferedReader bf) throws IOException {
        String response = bf.readLine();
        System.out.println("Server: " + response);
    }

    //Utility Function for sending a message
    private static void sendMessage(PrintWriter pw, String message) throws IOException {
        pw.println(message);
        pw.flush();
    }
}
