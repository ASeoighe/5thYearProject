import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import javax.imageio.ImageIO;
import javax.imageio.stream.ImageInputStream;

import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelSftp;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.JSchException;
import com.jcraft.jsch.Session;
import com.jcraft.jsch.SftpException;
import com.jcraft.jsch.UserInfo;

public class sftpFile {

	
		JSch jsch = new JSch();
        Session session = null;
        Channel channel;
        ChannelSftp sftpChannel;
        BufferedImage image;
        
        public void connect(String uname, String ip, String pswrd) {
        
        	try {
				session = jsch.getSession(uname, ip, 22);
			
            session.setConfig("StrictHostKeyChecking", "no");
            session.setPassword(pswrd);
            session.connect();

            channel = session.openChannel("sftp");
            channel.connect();
            sftpChannel = (ChannelSftp) channel;
            
        	} catch (JSchException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
        	
        }
        public BufferedImage getImage(){
        try {
            

            InputStream stream = sftpChannel.get("/home/pi/MotionMediaFiles/snapshot.jpg");
            try {
                image = ImageIO.read(stream);
                //String line;
                //File outputfile = new File("./saved.png");
                //ImageIO.write(image, "png", outputfile);
                

            } catch (IOException io) {
                System.out.println("Exception occurred during reading file from SFTP server due to " + io.getMessage());
                io.getMessage();

            } catch (Exception e) {
                System.out.println("Exception occurred during reading file from SFTP server due to " + e.getMessage());
                e.getMessage();

            }

            //sftpChannel.exit();
            //session.disconnect();
        } catch (SftpException e) {
            e.printStackTrace();
        }
		return image;
        }
}

