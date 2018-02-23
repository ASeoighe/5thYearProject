import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class writeToFile {

	public String writeToFile(String input) {
		BufferedWriter bw = null;
	    try {
		 
	       //Specify the file name and path here
		 File file = new File("C:\\Users\\Aaron Scally Seoighe\\Documents\\GitHub\\5thYearProject\\testImages\\OutputFiles\\outPut.txt");

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
		return input;
	}
	
	}

