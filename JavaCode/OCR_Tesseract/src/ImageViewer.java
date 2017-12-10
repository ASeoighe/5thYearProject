import java.awt.Component;
import java.awt.EventQueue;

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
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.awt.event.ActionEvent;
import javax.swing.JProgressBar;

import java.awt.Color;
import javax.swing.JTextPane;

public class ImageViewer {
	File chosenFile;
	String result =null;
	
	private JFrame frame;
	private JTextField directoryText;
	
	private JLabel inputImage;
	private JPanel outputPanel;
	private JPanel imageViewPanel;
	private JPanel textOutputPanel;
	JProgressBar progressBar;
	JTextPane outPutTextPane;
	JLabel lblTextReadFrom;
	JLabel errorLabel;
	
	JPanel progressBarPanel;
	private static String IMG_PATH = null;
	
	ITesseract instance = new Tesseract();
	writeToFile fileWriter = new writeToFile();
	static sqlInsert mySQL ;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					mySQL = new sqlInsert();
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
	public void displayImage() {
		SwingUtilities.invokeLater(new Runnable() {
	      public void run() {
	         //progressBar.updateBar(percent);
			 try {     
			 BufferedImage img;
			
				img = ImageIO.read(new File(IMG_PATH));
			
			 ImageIcon image = new ImageIcon(img);
			 inputImage.setIcon(image);
			 result = instance.doOCR(chosenFile);
			 
			 lblTextReadFrom.setVisible(true);
			 outPutTextPane.setVisible(true);
			 outPutTextPane.setText(result);
			 System.out.println(result);
			 fileWriter.writeToFile(result);
			 if(mySQL.insertPlate(result)) {
				 errorLabel.setVisible(true);
				 errorLabel.setForeground(Color.GREEN);
				 errorLabel.setText("Database Insert Succesful");
			 }
			 else {
				 errorLabel.setVisible(true);
				 errorLabel.setForeground(Color.RED);
				 errorLabel.setText("Databse Insert Failed!");
			 }
			 
		 } catch (IOException | TesseractException e) {
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
		frame.setBounds(100, 100, 680, 480);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBackground(Color.WHITE);
		panel.setLayout(null);
		panel.setBounds(0, 0, 670, 447);
		frame.getContentPane().add(panel);
		
		directoryText = new JTextField();
		directoryText.setEditable(false);
		directoryText.setColumns(10);
		directoryText.setBounds(170, 11, 370, 20);
		panel.add(directoryText);
		
		outputPanel = new JPanel();
		outputPanel.setBackground(Color.WHITE);
		outputPanel.setLayout(null);
		outputPanel.setBounds(10, 70, 650, 366);
		panel.add(outputPanel);
		
		imageViewPanel = new JPanel();
		imageViewPanel.setBackground(Color.WHITE);
		imageViewPanel.setBounds(0, 0, 325, 366);
		inputImage = new JLabel("", null, JLabel.CENTER);
		inputImage.setHorizontalAlignment(JLabel.CENTER);
		inputImage.setVerticalAlignment(JLabel.CENTER);
		imageViewPanel.add(inputImage);
		outputPanel.add(imageViewPanel);
		
		textOutputPanel = new JPanel();
		textOutputPanel.setBackground(Color.WHITE);
		textOutputPanel.setBounds(325, 0, 325, 366);
		outputPanel.add(textOutputPanel);
		textOutputPanel.setLayout(null);
		
		outPutTextPane = new JTextPane();
		outPutTextPane.setEditable(false);
		outPutTextPane.setVisible(false);
		outPutTextPane.setBounds(10, 41, 305, 314);
		textOutputPanel.add(outPutTextPane);
		
		lblTextReadFrom = new JLabel("Text Read From Image");
		lblTextReadFrom.setBounds(105, 11, 110, 14);
		lblTextReadFrom.setVisible(false);
		textOutputPanel.add(lblTextReadFrom);
		
		JPanel ErrorPanel = new JPanel();
		ErrorPanel.setBackground(Color.WHITE);
		ErrorPanel.setLayout(null);
		ErrorPanel.setBounds(10, 39, 264, 20);
		panel.add(ErrorPanel);
		
		JLabel error = new JLabel("Errors : ");
		error.setForeground(Color.RED);
		//error.setEnabled(false);
		error.setVisible(false);
		error.setBounds(0, 0, 46, 14);
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
			        	directoryText.setText(file.getPath());
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
		
		//Updates look and feel for all components
		SwingUtilities.updateComponentTreeUI(frame);
	}
}
