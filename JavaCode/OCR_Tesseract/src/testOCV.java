import java.awt.EventQueue;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.imgcodecs.Imgcodecs;
import org.opencv.imgproc.Imgproc;

public class testOCV {
	private static String IMG_PATH = "C:\\Users\\Aaron Scally Seoighe\\Documents\\GitHub\\5thYearProject\\testImages\\PlateImages\\CroppedImages\\4.png";
	

	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
					//ImageViewer window = new ImageViewer();
					grayscale();
					//window.frame.setVisible(true);
  
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	 public static void grayscale() {
			
		Mat grayscaleResult = new Mat();
		Mat Gray = Imgcodecs.imread(IMG_PATH, Imgcodecs.IMREAD_GRAYSCALE);
		Imgproc.adaptiveThreshold(Gray, grayscaleResult, 255, Imgproc.ADAPTIVE_THRESH_GAUSSIAN_C, Imgproc.THRESH_BINARY, 15, 40);
	}
}
