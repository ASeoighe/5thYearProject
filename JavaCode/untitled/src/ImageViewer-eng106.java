import java.awt.Component;
import java.awt.EventQueue;
import java.awt.Image;

import javax.swing.JFrame;
import net.sourceforge.tess4j.ITesseract;
import net.sourceforge.tess4j.Tesseract;
import net.sourceforge.tess4j.TesseractException;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JLabel;
import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.lang.String;
import java.awt.event.ActionEvent;
import javax.swing.JProgressBar;

import java.awt.Color;
import javax.swing.JTextPane;
import javax.swing.border.LineBorder;
import java.awt.SystemColor;
import javax.swing.JTextArea;
import javax.swing.border.BevelBorder;
import javax.swing.border.EtchedBorder;

import org.opencv.core.Core;
//import org.opencv.*;
import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.*;
import org.opencv.objdetect.*;
import org.opencv.imgcodecs.Imgcodecs;
//import org.opencv.highgui.Highgui;

import ch.qos.logback.classic.filter.ThresholdFilter;

public class ImageViewer {
	File chosenFile;
	String result =null;
	
	private JFrame frame;
	private JTextField directoryText;
	
	List<String> Config = new ArrayList<String>();
	private JLabel inputImage;
	private JPanel outputPanel;
	private JPanel imageViewPanel;
	private JPanel textOutputPanel;
	JProgressBar progressBar;
	JTextPane outPutTextPane;
	JLabel lblTextReadFrom;
	JLabel errorLabel;
	static JTextArea sqlStatus;
	
	
	
	JPanel progressBarPanel;
	private static String IMG_PATH = null;
	private String OutputDirectory = null;
	ITesseract instance = new Tesseract();
	writeToFile fileWriter = new writeToFile();
	static sqlInsert mySQL ;
	private JPanel SQL_Panel;
	private static JTextField SQLUrl;
	JButton btnConnectToDatabase;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					
					System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
					ImageViewer window = new ImageViewer();
					
					window.frame.setVisible(true);
  
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public ImageViewer() {
		initialize();
		
	}
	private void cropImage(String IMG_PATH) throws IOException {
		// TODO Auto-generated method stub
		Runtime runTime = Runtime.getRuntime();
		//Process process = runTime.exec("C:\\Users\\G00314077\\OneDrive - GMIT\\Project\\SquareCropTestCommandLine\\x64\\Debug\\SquareCropTestCommandLine.exe");
		Process process = new ProcessBuilder("C:\\Users\\G00314077\\OneDrive - GMIT\\Project\\SquareCropTestCommandLine\\x64\\Debug\\SquareCropTestCommandLine.exe",
				IMG_PATH).start();
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		
	}
	public void displayImage() {
		SwingUtilities.invokeLater(new Runnable() {
	      public void run() {
	         //progressBar.updateBar(percent);
			 try {     
			 BufferedImage img;
			 
			 /**********STARTS C PROGRAM FOR CROPPING ***********/
			 /*
			 try {
				cropImage(IMG_PATH);
			} catch (IOException e) {
				System.out.println("Error!: Couldnt Launch C Code Excecutable");
				e.printStackTrace();
			}
			 /**************************************************/
			 
			 

			 Mat InputImage = Imgcodecs.imread(IMG_PATH);
			 img = (BufferedImage) toBufferedImage(InputImage);
			 
			 ImageIcon image = new ImageIcon(img);
			 inputImage.setIcon(image);
			 
			 try{
			 List<String> configs = Arrays.asList("bazaar");
		     instance.setConfigs(configs);
			 }
			 catch(Exception bazaarException){
				 System.out.println("Bazaar OCR Config Cannot be Set");
			 }
			 try {
				cropImage(IMG_PATH);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				System.err.println("Image Crop Failed!");
				e.printStackTrace();
			}
			 Imgcodecs.
			 try{
				 setOutputDirectory();
			 }catch(Exception outDirErr){
				 System.out.println("Cannot Set outputDirectory using Input Image Directory.");
			 }
			 
		     //result = instance.doOCR(chosenFile);
		     result = instance.doOCR(img);
		     
			 lblTextReadFrom.setVisible(true);
			 outPutTextPane.setVisible(true);
			 outPutTextPane.setText(result);
			 System.out.println(result);
			 //fileWriter.writeToFile(result, OutputDirectory);
			try{ 
			 if(mySQL.SQLUrl != null){
				 if(mySQL.insertPlate(result)) {
					 errorLabel.setVisible(true);
					 errorLabel.setForeground(Color.GREEN);
					 errorLabel.setText("Database Insert Succesful");
				 }
				 else {
					 errorLabel.setVisible(true);
					 errorLabel.setForeground(Color.RED);
					 errorLabel.setText("Databse Insert Failed!");
				 }}}
				 catch(NullPointerException sqlE){
					 System.err.println("\n * MySQL URL is Undefined. * ");
				 }
		 } catch (TesseractException e) {
				// TODO Auto-generated catch block
			 System.err.println("\n * MySQL URL is Undefined. * ");
				//e.printStackTrace();
			}
     
		}
      });
	}
	protected void setOutputDirectory() {
		// TODO Auto-generated method stub
		 OutputDirectory = IMG_PATH.substring(0, IMG_PATH.lastIndexOf("\\")+1);
		 OutputDirectory = OutputDirectory.concat("JavaOutputText.txt");
		 System.out.println("TextFile Output Directory: "+OutputDirectory);
		 IMG_PATH = IMG_PATH.substring(0, IMG_PATH.lastIndexOf("\\")+1);
		 IMG_PATH = IMG_PATH.concat("B.png");
		 System.out.println("Cropped \"C-Code\" Output Image Directory: "+IMG_PATH);
	}

	public void connectDatabase() {
		SwingUtilities.invokeLater(new Runnable() {
	      public void run() {
	    	  try {
				mySQL = new sqlInsert(sqlStatus, SQLUrl);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			 }
      });
	}
        
	

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		//Sets Look and feel
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		frame = new JFrame();
		frame.setBounds(100, 100, 680, 600);
		frame.setTitle("LicensePlate Reader");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		panel.setBackground(Color.WHITE);
		panel.setLayout(null);
		panel.setBounds(0, 114, 664, 447);
		frame.getContentPane().add(panel);
		
		directoryText = new JTextField();
		directoryText.setEditable(false);
		directoryText.setColumns(10);
		directoryText.setBounds(170, 11, 370, 20);
		panel.add(directoryText);
		
		outputPanel = new JPanel();
		outputPanel.setBackground(Color.WHITE);
		outputPanel.setLayout(null);
		outputPanel.setBounds(10, 70, 644, 366);
		panel.add(outputPanel);
		
		imageViewPanel = new JPanel();
		imageViewPanel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		imageViewPanel.setBackground(Color.WHITE);
		imageViewPanel.setBounds(0, 0, 325, 366);
		inputImage = new JLabel("", null, JLabel.CENTER);
		inputImage.setHorizontalAlignment(JLabel.CENTER);
		inputImage.setVerticalAlignment(JLabel.CENTER);
		imageViewPanel.add(inputImage);
		outputPanel.add(imageViewPanel);
		
		textOutputPanel = new JPanel();
		textOutputPanel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		textOutputPanel.setBackground(Color.WHITE);
		textOutputPanel.setBounds(325, 0, 315, 366);
		outputPanel.add(textOutputPanel);
		textOutputPanel.setLayout(null);
		
		outPutTextPane = new JTextPane();
		outPutTextPane.setEditable(false);
		outPutTextPane.setVisible(false);
		outPutTextPane.setBounds(10, 41, 295, 314);
		textOutputPanel.add(outPutTextPane);
		
		lblTextReadFrom = new JLabel("Text Read From Image");
		lblTextReadFrom.setBounds(105, 11, 110, 14);
		lblTextReadFrom.setVisible(false);
		textOutputPanel.add(lblTextReadFrom);
		
		JPanel ErrorPanel = new JPanel();
		ErrorPanel.setBorder(new LineBorder(new Color(0, 0, 0)));
		ErrorPanel.setBackground(Color.WHITE);
		ErrorPanel.setLayout(null);
		ErrorPanel.setBounds(10, 39, 264, 20);
		panel.add(ErrorPanel);
		
		JLabel error = new JLabel("Status: ");
		error.setForeground(Color.RED);
		//error.setEnabled(false);
		error.setVisible(false);
		error.setBounds(10, 0, 46, 14);
		ErrorPanel.add(error);
		
		errorLabel = new JLabel("");
		//errorLabel.setEnabled(false);
		errorLabel.setVisible(false);
		errorLabel.setBounds(54, 0, 210, 14);
		ErrorPanel.add(errorLabel);
		
		progressBarPanel = new JPanel();
		progressBarPanel.setBackground(Color.WHITE);
		progressBarPanel.setLayout(null);
		progressBarPanel.setBounds(284, 39, 257, 23);
		panel.add(progressBarPanel);
		
		JLabel progressLabel = new JLabel("Reading Progress");
		progressLabel.setBounds(0, 0, 100, 14);
		progressBarPanel.add(progressLabel);
		
		progressBar = new JProgressBar();
		progressBar.setForeground(Color.GREEN);
		progressBar.setBounds(110, 0, 146, 14);
		progressBar.setMinimum(0);
		progressBar.setMaximum(100);
		progressBarPanel.add(progressBar);
		
		JLabel directoryLabel = new JLabel("Choose Your Picture Directory");
		directoryLabel.setBounds(10, 14, 160, 14);
		panel.add(directoryLabel);
		
		//Create a file chooser
		final JFileChooser fileChooser = new JFileChooser();
		fileChooser.setBackground(Color.WHITE);
		
		JButton chooseButton = new JButton("Choose Folder");
		chooseButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent buttonPressed) {
				int returnVal = fileChooser.showOpenDialog((Component)buttonPressed.getSource());
			    if (returnVal == JFileChooser.APPROVE_OPTION) {
			        File file = fileChooser.getSelectedFile();
			        try {
			        	IMG_PATH = file.getPath();
			        	System.err.println(IMG_PATH);
			        	directoryText.setText("Image Chosen: "+file.getPath());
			        	chosenFile = file;
			        } catch (Exception ex) {
			          System.out.println("problem accessing file"+file.getAbsolutePath());
			        }
			    } 
			    else {
			    	error.setVisible(true);
			    	errorLabel.setVisible(true);
			    	errorLabel.setText("File access cancelled by user.");
			        System.out.println("File access cancelled by user.");
			    }       
			}   
			
		});
		chooseButton.setBounds(550, 10, 110, 23);
		panel.add(chooseButton);	
		
		JButton btnReadImage = new JButton("Convert Image");
		btnReadImage.addActionListener(new ActionListener() { 
		    public void actionPerformed(ActionEvent e) { 
		        displayImage();
		    } 
		});
		btnReadImage.setBounds(551, 36, 109, 23);
		panel.add(btnReadImage);
		
		SQL_Panel = new JPanel();
		SQL_Panel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		SQL_Panel.setBackground(Color.WHITE);
		SQL_Panel.setBounds(0, 0, 664, 113);
		frame.getContentPane().add(SQL_Panel);
		SQL_Panel.setLayout(null);
		
		SQLUrl = new JTextField();
		/*
		SQLUrl.addFocusListener(new FocusListener() {
		    public void focusGained(FocusEvent e) {
		    	SQLUrl.setText("");
		    }

		    public void focusLost(FocusEvent e) {
		    	SQLUrl.setText("Example: http://127.0.0.1/database");
		    }
		});
		*/
		//SQLUrl.setText("Example: http://127.0.0.1/database");
		SQLUrl.setBounds(170, 11, 370, 20);
		SQL_Panel.add(SQLUrl);
		SQLUrl.setColumns(10);
		
		btnConnectToDatabase = new JButton("Connect");
		btnConnectToDatabase.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				connectDatabase();
			}
		});
		btnConnectToDatabase.setBounds(550, 10, 104, 62);
		SQL_Panel.add(btnConnectToDatabase);
		
		JLabel lblEnterSqlUrl = new JLabel("Enter SQL URL");
		lblEnterSqlUrl.setBounds(71, 11, 89, 17);
		SQL_Panel.add(lblEnterSqlUrl);
		
		JLabel lblSqlFeedback = new JLabel("SQL FeedBack");
		lblSqlFeedback.setBounds(71, 37, 89, 20);
		SQL_Panel.add(lblSqlFeedback);
		
		sqlStatus = new JTextArea();
		sqlStatus.setBounds(170, 42, 370, 60);
		SQL_Panel.add(sqlStatus);
		
		//Updates look and feel for all components
		SwingUtilities.updateComponentTreeUI(frame);
	}
	
	public Image toBufferedImage(Mat m){
	        int type = BufferedImage.TYPE_BYTE_GRAY;
	        if ( m.channels() > 1 ) {
	            type = BufferedImage.TYPE_3BYTE_BGR;
	        }
	        int bufferSize = m.channels()*m.cols()*m.rows();
	        byte [] b = new byte[bufferSize];
	        m.get(0,0,b); // get all the pixels
	        BufferedImage image = new BufferedImage(m.cols(),m.rows(), type);
	        final byte[] targetPixels = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();
	        System.arraycopy(b, 0, targetPixels, 0, b.length);  
	        return image;
	
	    }
	public Mat blur(Mat input, int numberOfTimes){
        Mat sourceImage = new Mat();
        Mat destImage = input.clone();
        for(int i=0;i<numberOfTimes;i++){
            sourceImage = destImage.clone();
            Imgproc.GaussianBlur(sourceImage, destImage, new Size(3.0,3.0), 0);
        }
        return destImage;
    }
}