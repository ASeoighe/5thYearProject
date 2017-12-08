
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

import net.sourceforge.tess4j.*;

public class Main {
	public static void main(String[] args) {
		//String imgDir = "C:\\Users\\Aaron Scally Seoighe\\Google Drive\\Jswing.png";
		//String imgDir = "C:\\Users\\Aaron Scally Seoighe\\Documents\\Code\\5thYrProject\\JavaCode\\OCR_Tesseract\\images\\eurotext.png";
		String imgDir = "C:\\Users\\Aaron\\Documents\\GitHub\\5thYearProject\\testImages\\PlateImages\\21.png";
		File imageFile = new File (imgDir);
		ITesseract instance = new Tesseract();
		
		try {
			String result = instance.doOCR(imageFile);
			System.out.println(result);
			writeToFile(result);
		} catch(TesseractException e){
			System.out.println(e.getMessage());
		}
	}


public static void writeToFile(String input) {
	BufferedWriter bw = null;
    try {
	 
       //Specify the file name and path here
	 File file = new File("C:\\Users\\Aaron\\Documents\\GitHub\\5thYearProject\\testImages\\OutputFiles\\outPut.txt");

	 /* This logic will make sure that the file 
	  * gets created if it is not present at the
	  * specified location*/
	  if (!file.exists()) {
	     file.createNewFile();
	  }

	  FileWriter fw = new FileWriter(file);
	  bw = new BufferedWriter(fw);
	  bw.write(input);
        System.out.println("File written Successfully");

    } catch (IOException ioe) {
	   ioe.printStackTrace();
	}
	finally
	{ 
	   try{
	      if(bw!=null)
		 bw.close();
	   }catch(Exception ex){
	       System.out.println("Error in closing the BufferedWriter"+ex);
	    }
	}
}
}
