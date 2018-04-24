import java.io.FileInputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSend {
	public static void amain(String args[]) throws IOException {
		
		ServerSocket ss = new ServerSocket(8081);
		Socket s = ss.accept();
		FileInputStream fis = new FileInputStream("./");
		byte b[] = new byte[2000];
		fis.read(b,0,b.length);
		
		OutputStream os = s.getOutputStream();
		os.write(b,0,b.length);;
	}

}
