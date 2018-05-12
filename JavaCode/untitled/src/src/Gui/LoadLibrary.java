package src.Gui;

import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

public class LoadLibrary {
public static void loadOpenCV() {
    try {
        InputStream inputStream = null;
        File fileOut = null;
        String osName = System.getProperty("os.name");
        System.out.println(osName);

        if (osName.startsWith("Windows")) {
            int bitness = Integer.parseInt(System.getProperty("sun.arch.data.model"));
            if (bitness == 32) {
                inputStream = LoadLibrary.class.getResourceAsStream("C:/Users/G00314077/OneDrive - GMIT/opencv300/build/java/x86/opencv_java300.dll");
                fileOut = File.createTempFile("lib", ".dll");
            } else if (bitness == 64) {
                inputStream = LoadLibrary.class.getResourceAsStream("C:/Users/G00314077/OneDrive - GMIT/opencv300/build/java/x64/opencv_java300.dll");
                fileOut = File.createTempFile("lib", ".dll");
            } else {
                inputStream = LoadLibrary.class.getResourceAsStream("C:/Users/G00314077/OneDrive - GMIT/opencv300/build/java/x86/opencv_java300.dll");
                fileOut = File.createTempFile("lib", ".dll");
            }
        } 

        if (fileOut != null) {
            OutputStream outputStream = new FileOutputStream(fileOut);
            byte[] buffer = new byte[1024];
            int length;
            try{
	            while ((length = inputStream.read(buffer)) > 0) {
	                outputStream.write(buffer, 0, length);
	            }
            }catch(java.lang.NullPointerException ANull){
            	System.out.print(" ");
            }

            inputStream.close();
            outputStream.close();
            System.load(fileOut.toString());
        }
    } catch (Exception e) {
        e.printStackTrace();
    }
}
}