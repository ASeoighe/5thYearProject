import java.awt.BorderLayout;
import java.awt.Image;
import java.io.BufferedInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.net.URL;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class testApache {
  public static void amain(String[] argv) throws Exception {
    URL url = new URL("http://192.168.1.18:8081");
    //Image image = ImageIO.read(url);

    InputStream in = new BufferedInputStream(url.openStream());
    ByteArrayOutputStream out = new ByteArrayOutputStream();
    byte[] buf = new byte[1024];
    int n =0;
    int cnt = 0;
    
    while(-1!=(n=in.read(buf))) {
    	out.write(buf,0,n);
    	cnt++;
    	if(cnt == 500)
    	{
    		break;
    	}
    }
    out.close();
    in.close();
    byte[] response = out.toByteArray();
    
    int i = 0;
    System.out.println(i);
    
  }
}
