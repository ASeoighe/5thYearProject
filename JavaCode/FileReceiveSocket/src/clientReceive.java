import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import javax.imageio.ImageIO;

public class clientReceive {
	public static void amain(String args[]) throws UnknownHostException, IOException {
		
		String ContentType;
		int ContentLength;
		int count = 0, bString =0;
		int i=0;
		
		File outputFile=new File("./images/"+i+".jpg");
		BufferedImage bufferedImage = null;
		String formatName="jpeg";
		
		byte []b = new byte[30000];
		
		List<Byte> imageBytes = new ArrayList<Byte>();
		
		Socket s = new Socket("192.168.1.18",8081);
		InputStream is = s.getInputStream();
		
		// Read response from web server, which will trigger the multipart HTTP request to be sent.
		BufferedReader httpResponseReader = new BufferedReader(new InputStreamReader(is));
		String lineRead;
		
		while((lineRead = httpResponseReader.readLine()) != null) {

			PrintStream out = new PrintStream(
				     new FileOutputStream("./images/"+i+".jpg", true)); 
			
			/*
			  	--BoundaryString
				Content-type: image/jpeg
				Content-Length:       26051
			 */
			if(lineRead.equalsIgnoreCase("--BoundaryString")) {
				lineRead = httpResponseReader.readLine();
				if(lineRead.equalsIgnoreCase("Content-type: image/jpeg")) {
					lineRead = httpResponseReader.readLine();
					if(lineRead.contains("Content-Length:")) {
						lineRead = httpResponseReader.readLine();
					
					//System.out.println(lineRead);
						while(!lineRead.equalsIgnoreCase("--BoundaryString")) {
							
							lineRead = httpResponseReader.readLine();
							bufferedImage = ImageIO.read(is);
							//imageBytes.add((byte) lineRead);
							//System.out.println(lineRead);
						    out.println(lineRead);
							//bufferedImage=ImageIO.read(is);
						}
						File outputfile = new File("./anew.png");
		                ImageIO.write(bufferedImage, "png", outputfile);
						//System.out.println(lineRead);
						//out.println(lineRead);
						
						//ImageIO.write(bufferedImage,formatName,outputFile);
						i++;
				    }
				}
			}
		}
			}
			//PrintStream out = new PrintStream(
			//	     new FileOutputStream("./i.txt", true)); 
	
		    
		    //out.println(lineRead);
	//	}
	//	
	//	FileOutputStream fos = new FileOutputStream("./i.jpg");
	//	is.read(b,0,b.length);
	//}
	


}
