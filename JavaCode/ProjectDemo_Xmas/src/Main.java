
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;

import net.sourceforge.tess4j.*;

public class Main {
	public static void main(String[] args) {
		
		File imageFile;
		ArrayList<File> directoryArray = new ArrayList<>();
        ArrayList<String> resultArray = new ArrayList<>();

		for(int i =1;i<28;i++){
			//DESKTOP DIRECTORY 
			String imgDir = "";
			// LAPTOP DIRECTORY
			
			imageFile= new File(imgDir);
			directoryArray.add(imageFile);
		}

		ITesseract instance = new Tesseract();
		Iterator iterator=directoryArray.iterator();
		int dirNum =0;

		try {
			while(iterator.hasNext()) {
				String result = null;
				System.out.println(directoryArray.get(dirNum));
				result = instance.doOCR(directoryArray.get(dirNum));

				System.out.println("Image "+(dirNum+1)+" Complete, Moving on..");
				//writeToFile(result, dirNum);
                resultArray.add(dirNum,result);
				dirNum++;
			}
		} catch(TesseractException e){
			System.out.println(e.getMessage());
		}
        writeToFile(resultArray);
	}

public static String getDirectory(){
		String directory=null;

		return directory;
}
public static void writeToFile(ArrayList<String> results) {
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

        Iterator iterator=results.iterator();
        int dirNum =0;

        FileWriter fw = null;
        try {
            fw = new FileWriter(file);
        } catch (IOException e) {
            e.printStackTrace();
        }
        bw = new BufferedWriter(fw);


            while(iterator.hasNext()) {
                bw.append("\r\n\r\nLicense Plate ("+dirNum+")"+results.get(dirNum));
                System.out.println("Plate ["+dirNum
                        +"] written Successfully");

                dirNum++;
            }
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
