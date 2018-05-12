package main.classes;
import java.awt.Component;
import java.awt.Desktop;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Image;

import de.javasoft.plaf.synthetica.SyntheticaAluOxideLookAndFeel;
import de.javasoft.plaf.synthetica.SyntheticaBlackStarLookAndFeel;
import de.javasoft.plaf.synthetica.SyntheticaStandardLookAndFeel;

import javax.swing.JFrame;
import net.sourceforge.tess4j.ITesseract;
import net.sourceforge.tess4j.Tesseract;
import net.sourceforge.tess4j.TesseractException;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingUtilities;
import javax.swing.Timer;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import javax.swing.JLabel;
import javax.swing.Icon;
//import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;

import java.awt.event.ActionListener;
//import java.awt.event.FocusEvent;
//import java.awt.event.FocusListener;
import java.awt.image.BufferedImage;
import java.awt.image.DataBufferByte;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.lang.String;
import java.net.ConnectException;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URISyntaxException;
import java.sql.SQLException;
import java.text.ParseException;
import java.awt.event.ActionEvent;
import javax.swing.JProgressBar;
import javax.swing.JScrollPane;

import java.awt.Color;
import javax.swing.JTextPane;
import javax.swing.border.LineBorder;
//import java.awt.SystemColor;
import javax.swing.JTextArea;
//import javax.swing.border.BevelBorder;
import javax.swing.border.EtchedBorder;

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

import org.opencv.core.Core;
//import org.opencv.*;
import org.opencv.core.Mat;
import org.opencv.core.Size;
import org.opencv.imgproc.*;
//import org.opencv.objdetect.*;
import org.opencv.imgcodecs.Imgcodecs;
import javax.swing.JSeparator;
import javax.swing.JSlider;
//import org.opencv.highgui.Highgui;

//import ch.qos.logback.classic.filter.ThresholdFilter;

public class ImageViewer {
	File chosenFile;

	boolean connectPressed = false;
	private int connectPress =0;
	private JFrame frame;

	public static boolean isRecursionEnable = false;

	List<String> Config = new ArrayList<String>();
	private JLabel inputImage;
	private JPanel outputPanel;
	private JPanel imageViewPanel;
	private JPanel textOutputPanel;
	private JTextArea sqlDataArea;
	private JTextField streamUname;
	private JPanel processedImagePane;
	private JSlider slider;
	private JLabel threshVal;

	private sftpFile imageStream = new sftpFile();

	JButton btnViewFeed;
	JTextPane outPutTextPane;
	JLabel lblTextReadFrom;
	JLabel errorLabel;

	static JTextArea sqlStatus;
	JScrollPane sp;
	private static String IMG_PATH = null;
	private String OutputDirectory = null;
	ITesseract instance = new Tesseract();
	writeToFile fileWriter = new writeToFile();
	Person Employee;

	File img;

	static checkDB mySQL = new checkDB();
	private JPanel SQL_Panel;
	private static JTextField SQLUrl;
	JButton btnConnectToDatabase;
	private JSeparator separator_1;
	private JTextField streamPassword;
	private JLabel lblStreamIp;
	private JTextField streamIP;
	private JLabel processedImageIcon;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {

		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					// File opencvLibrary = new File("opencv_java300.dll");

					// System.out.println(opencvLibrary.getAbsolutePath());

					// System.load(Core.NATIVE_LIBRARY_NAME);

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

	private void cropImage() throws IOException {
		Runtime rt = Runtime.getRuntime();
		String[] commands = {"D:\\5thYearProject\\workspace\\OCR_Tesseract\\exe\\PlateCrop.exe",
							  Integer.toString(slider.getValue()),
							 "D:\\5thYearProject\\workspace\\OCR_Tesseract\\exe\\haarcascade_numberplate.xml",
							 "D:\\5thYearProject\\workspace\\OCR_Tesseract\\exe\\inputImage.png",
							 "D:\\5thYearProject\\workspace\\OCR_Tesseract\\exe\\b.png"};
		Process proc = rt.exec(commands);
		
		
		BufferedReader stdInput = new BufferedReader(new 
		     InputStreamReader(proc.getInputStream()));

		BufferedReader stdError = new BufferedReader(new 
		     InputStreamReader(proc.getErrorStream()));

		// read the output from the command
		System.out.println("Here is the standard output of the command:\n");
		String s = null;
		while ((s = stdInput.readLine()) != null) {
		    System.out.println(s);
		}

		// read any errors from the attempted command
		System.out.println("Here is the standard error of the command (if any):\n");
		while ((s = stdError.readLine()) != null) {
		    System.out.println(s);
		}

	}

	public void convertText(String imgDir) {

		inputImage.repaint();

		try {
			String result = null;
			File inputFile = new File("./exe/"+imgDir);
			if (inputFile.exists()) {
				instance.setLanguage("reg");
				result = instance.doOCR(inputFile);
				lblTextReadFrom.setVisible(true);
				outPutTextPane.setVisible(true);
				outPutTextPane.setCaretPosition(0);
				if(!result.isEmpty()){
					outPutTextPane.setText(result);
					checkResult(result);
				}
			} else {
				outPutTextPane.setVisible(true);
			}

		} catch (TesseractException T) {

			T.getMessage();
		}
		// System.out.println(result);
		// fileWriter.writeToFile(result, OutputDirectory);

	}

	public void checkResult(String result) {

		try {

			if (mySQL.isConnected()) {
				mySQL.checkData(result);
				Employee = mySQL.getEmployee();
				errorLabel.setVisible(true);
				if (!Employee.getName().isEmpty()) {
					errorLabel.setForeground(Color.GREEN);
					errorLabel.setText("Access Granted");
					sqlDataArea.setBackground(Color.GRAY);
					sqlDataArea.setForeground(Color.GREEN);
					sqlDataArea.setText(Employee.toString());
				} else if (Employee.getName().isEmpty()) {
					errorLabel.setForeground(Color.RED);
					errorLabel.setText("Access Denied");
					sqlDataArea.setBackground(Color.WHITE);
					sqlDataArea.setForeground(Color.RED);
					sqlDataArea.setText("No Employee Info Found");
				}

			} else if (mySQL.isConnected() == false) {
				errorLabel.setVisible(true);
				errorLabel.setForeground(Color.ORANGE);
				errorLabel.setText("Not connected to Database.");
				sqlDataArea.setBackground(Color.GRAY);
				sqlDataArea.setForeground(Color.ORANGE);
				sqlDataArea.setText("No Database Connected!.");
			} else if (Employee.getName() == null) {
				errorLabel.setVisible(true);
				errorLabel.setForeground(Color.RED);
				errorLabel.setText("Database Insert Failed!");
			}
		} catch (NullPointerException sqlE) {
			//sqlE.getMessage();
			sqlDataArea.setBackground(Color.WHITE);
			sqlDataArea.setForeground(Color.RED);
			sqlDataArea.setText("Nothing to Query.");
		}

	}

	public void displayImage() {

		// progressBar.updateBar(percent);
		try {
			BufferedImage img, img2;

			/********** STARTS C PROGRAM FOR CROPPING ***********/
			/*
			 * try { cropImage(IMG_PATH); } catch (IOException e) { System.out.
			 * println("Error!: Couldnt Launch C Code Excecutable");
			 * e.printStackTrace(); } /
			 **************************************************/

			// Mat InputImage = Imgcodecs.imread(IMG_PATH);
			// Mat InputImage = imageStream.getImage();
			// img = (BufferedImage) toBufferedImage(InputImage);

			threshVal.setText((Integer.toString(slider.getValue())));
			img = imageStream.getImage();
			Image image = img.getScaledInstance(360, 240, Image.SCALE_SMOOTH);

			ImageIcon imageIcon = new ImageIcon(image);

			File outputfile = new File("./exe/inputImage.png");
			ImageIO.write(img, "png", outputfile);
			inputImage.setIcon(imageIcon);
			img2 = ImageIO.read(new File("./exe/b.png"));
			Image prcImage = img2.getScaledInstance(300, 100, Image.SCALE_SMOOTH);

			processedImageIcon = new JLabel(new ImageIcon(prcImage));
			processedImagePane.removeAll();
			processedImagePane.add(processedImageIcon);
			processedImagePane.revalidate();
			processedImagePane.repaint();
			try {
				cropImage();

			} catch (IOException e) {
				System.err.println("Image Crop Failed!,\n - Proceeding using no Crop.");
			}
			//BufferedImage processedIcon = ImageIO.read(new File("./exe/b.png"));
			
			
			convertText("b.png");

		} catch (Exception e) {
			e.getStackTrace();
		}

	}

	protected void setOutputDirectory() {
		// TODO Auto-generated method stub
		// OutputDirectory = IMG_PATH.substring(0, IMG_PATH.lastIndexOf("\\") +
		// 1);
		// OutputDirectory = OutputDirectory.concat("JavaOutputText.txt");
		OutputDirectory = "./exe/";
		// System.out.println("TextFile Output Directory: "+OutputDirectory);
		// IMG_PATH = IMG_PATH.substring(0, IMG_PATH.lastIndexOf("\\") + 1);
		// IMG_PATH = IMG_PATH.concat("B.png");
		// System.out.println("Cropped \"C-Code\" Output Image Directory:
		// "+IMG_PATH);
	}

	void runInBackground() {

	}

	public void connectToFeed() {

		connectPressed = true;
		try {
			imageStream.connect(streamUname.getText(), streamIP.getText(), streamPassword.getText());
		} catch (ConnectException e) {
			errorLabel.setVisible(true);
			errorLabel.setForeground(Color.ORANGE);
			errorLabel.setText("No server found, Couldnt Connect.");
		}
		SwingUtilities.invokeLater(new Runnable() {
			public void run() {
				displayImage();
			}
		});
		// New timer which works!
		int delay = 1000; // milliseconds
		ActionListener taskPerformer = new ActionListener() {
			public void actionPerformed(ActionEvent evt) {
				if (connectPressed)
					displayImage();
			}
		};
		new Timer(delay, taskPerformer).start();

	}
	public void disconnectFeed() {
		imageStream.disconnect();
		
		errorLabel.setVisible(true);
		errorLabel.setForeground(Color.ORANGE);
		errorLabel.setText("Successful Disconnect from Stream.");
		connectPress = 0;
	}

	public void connectDatabase() {
		// SwingUtilities.invokeLater(new Runnable() {
		// public void run() {
		// try {
		mySQL.setUrl(SQLUrl.getText());
		mySQL.setStatusPane(sqlStatus);
		try {
			mySQL.connect();
		} catch (Exception e) {
			if (e instanceof MalformedURLException) {

				errorLabel.setVisible(true);
				errorLabel.setText(" ");
				errorLabel.setForeground(Color.ORANGE);
				errorLabel.setText("Invalid SQL Url. Didnt Attempt Connection.");
				errorLabel.repaint();
			} else if (!(e instanceof MalformedURLException)) {
				errorLabel.setVisible(true);
				errorLabel.setForeground(Color.RED);
				errorLabel.setText("SQL Error.");
				errorLabel.repaint();
			}
		}
		if (mySQL.isConnected()) {
			errorLabel.setVisible(true);
			errorLabel.setText(" ");
			errorLabel.setForeground(Color.GREEN);
			errorLabel.setText("SQL DataBase Connect Succesful.");
			errorLabel.repaint();
		}

	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		// Sets Look and feel
		try {

			try {
				// UIManager.setLookAndFeel(new
				// SyntheticaStandardLookAndFeel());
				UIManager.setLookAndFeel(new SyntheticaAluOxideLookAndFeel());
				// UIManager.setLookAndFeel(new
				// SyntheticaBlackStarLookAndFeel());
			} catch (ParseException e1) {
				// TODO Auto-generated catch block
				e1.printStackTrace();
			}

		} catch (UnsupportedLookAndFeelException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		frame = new JFrame();
		frame.setResizable(false);
		
		//Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		//setBounds(0,0,screenSize.width, screenSize.height); 
		
		frame.setBounds(100, 100, 750, 610);
		frame.setTitle("LicensePlate Reader");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);

		JPanel panel = new JPanel();
		panel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		panel.setBackground(Color.WHITE);
		panel.setLayout(null);
		panel.setBounds(0, 114, 744, 457);
		frame.getContentPane().add(panel);

		streamUname = new JTextField();
		streamUname.setColumns(10);
		streamUname.setBounds(336, 7, 167, 20);
		panel.add(streamUname);

		outputPanel = new JPanel();
		outputPanel.setBackground(Color.WHITE);
		outputPanel.setLayout(null);
		outputPanel.setBounds(10, 70, 724, 376);
		panel.add(outputPanel);

		imageViewPanel = new JPanel();
		imageViewPanel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		imageViewPanel.setBackground(Color.WHITE);
		imageViewPanel.setBounds(0, 0, 364, 273);
		inputImage = new JLabel("", null, JLabel.CENTER);
		inputImage.setHorizontalAlignment(JLabel.CENTER);
		inputImage.setVerticalAlignment(JLabel.CENTER);
		imageViewPanel.add(inputImage);
		outputPanel.add(imageViewPanel);

		textOutputPanel = new JPanel();
		textOutputPanel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		textOutputPanel.setBackground(Color.WHITE);
		textOutputPanel.setBounds(374, 0, 350, 376);
		outputPanel.add(textOutputPanel);
		textOutputPanel.setLayout(null);

		outPutTextPane = new JTextPane();
		outPutTextPane.setEditable(false);
		outPutTextPane.setVisible(false);
		outPutTextPane.setBounds(10, 41, 295, 45);
		textOutputPanel.add(outPutTextPane);

		lblTextReadFrom = new JLabel("Text Read From Image");
		lblTextReadFrom.setBounds(105, 11, 170, 14);
		lblTextReadFrom.setVisible(false);
		textOutputPanel.add(lblTextReadFrom);

		sqlDataArea = new JTextArea();
		sqlDataArea.setBounds(10, 125, 330, 240);
		sqlDataArea.setEditable(false);
		sqlDataArea.setLineWrap(true);
		sqlDataArea.setWrapStyleWord(true);
		sqlDataArea.setFont(new Font("Calibri", Font.PLAIN, 12));
		textOutputPanel.add(sqlDataArea);
		
		processedImagePane = new JPanel();
		processedImagePane.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		processedImagePane.setBackground(Color.WHITE);
		processedImagePane.setBounds(0, 273, 364, 103);
		outputPanel.add(processedImagePane);
		
		processedImageIcon = new JLabel();
		processedImagePane.add(processedImageIcon);

		JPanel ErrorPanel = new JPanel();
		ErrorPanel.setBorder(new LineBorder(new Color(0, 0, 0)));
		ErrorPanel.setBackground(Color.WHITE);
		ErrorPanel.setLayout(null);
		ErrorPanel.setBounds(10, 39, 221, 20);
		panel.add(ErrorPanel);

		JLabel error = new JLabel("Status: ");
		error.setForeground(Color.RED);
		// error.setEnabled(false);
		error.setVisible(false);
		error.setBounds(10, 0, 46, 14);
		ErrorPanel.add(error);

		errorLabel = new JLabel("");
		// errorLabel.setEnabled(false);
		errorLabel.setVisible(false);
		errorLabel.setBounds(54, 0, 210, 14);
		ErrorPanel.add(errorLabel);

		JLabel directoryLabel = new JLabel("Stream Username");
		directoryLabel.setBounds(231, 10, 120, 14);
		panel.add(directoryLabel);

		// Create a file chooser
		// final JFileChooser fileChooser = new JFileChooser();
		// fileChooser.setBackground(Color.WHITE);

		JButton chooseButton = new JButton("Connect Feed");
		chooseButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent buttonPressed) {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						connectPress++;
						if(connectPress == 1)
							connectToFeed();
						else if(connectPress == 2)
							disconnectFeed();
						// displayImage();

						/*
						 * int returnVal =
						 * fileChooser.showOpenDialog((Component)
						 * buttonPressed.getSource()); if (returnVal ==
						 * JFileChooser.APPROVE_OPTION) { File file =
						 * fileChooser.getSelectedFile(); try { IMG_PATH =
						 * file.getPath(); System.err.println(IMG_PATH);
						 * directoryText.setText("Image Chosen: " +
						 * file.getPath()); chosenFile = file; } catch
						 * (Exception ex) { //
						 * System.out.println("problem accessing file"+file.
						 * getAbsolutePath()); } } else {
						 * error.setVisible(true); errorLabel.setVisible(true);
						 * errorLabel.setText("File access cancelled by user.");
						 * //
						 * System.out.println("File access cancelled by user.");
						 * }
						 */
					}
				});
			}

		});
		chooseButton.setBounds(512, 6, 113, 23);
		panel.add(chooseButton);

		JButton btnReadImage = new JButton("Convert Image");
		btnReadImage.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						 File file = new File("./exe/b.png");
				         
					        if(file.delete())
					        {
					            System.out.println("File deleted successfully");
					        }
					        else
					        {
					            System.out.println("Failed to delete the file");
					        }
						convertText("inputImage.png");
						// displayImage();
					}
				});
			}
		});
		btnReadImage.setBounds(512, 34, 113, 23);
		panel.add(btnReadImage);

		streamPassword = new JTextField();
		streamPassword.setColumns(10);
		streamPassword.setBounds(336, 35, 167, 20);
		panel.add(streamPassword);

		JLabel lblPassword = new JLabel(" Password");
		lblPassword.setBounds(231, 39, 70, 14);
		panel.add(lblPassword);

		lblStreamIp = new JLabel("Stream IP:");
		lblStreamIp.setBounds(12, 14, 120, 14);
		panel.add(lblStreamIp);

		streamIP = new JTextField();
		streamIP.setColumns(10);
		streamIP.setBounds(75, 11, 156, 20);
		panel.add(streamIP);
		
		slider = new JSlider();
		slider.setValue(125);
		slider.setPaintTicks(true);
		slider.setPaintLabels(true);
		slider.setMaximum(255);
		slider.setBounds(630, 48, 104, 20);
		panel.add(slider);
		
		JLabel lblManualThresh = new JLabel("Manual Thresh");
		lblManualThresh.setBounds(636, 10, 98, 14);
		panel.add(lblManualThresh);
		threshVal = new JLabel(Integer.toString(slider.getValue()));
		threshVal.setBounds(663, 25, 33, 20);
		panel.add(threshVal);

		SQL_Panel = new JPanel();
		SQL_Panel.setBorder(new EtchedBorder(EtchedBorder.LOWERED, null, null));
		SQL_Panel.setBackground(Color.WHITE);
		SQL_Panel.setBounds(0, 0, 744, 113);
		frame.getContentPane().add(SQL_Panel);
		SQL_Panel.setLayout(null);

		SQLUrl = new JTextField();
		/*
		 * SQLUrl.addFocusListener(new FocusListener() { public void
		 * focusGained(FocusEvent e) { SQLUrl.setText(""); }
		 * 
		 * public void focusLost(FocusEvent e) {
		 * SQLUrl.setText("Example: http://127.0.0.1/database"); } });
		 */
		// SQLUrl.setText("Example: http://127.0.0.1/database");
		SQLUrl.setBounds(109, 12, 370, 20);
		SQL_Panel.add(SQLUrl);
		SQLUrl.setColumns(10);

		btnConnectToDatabase = new JButton("Connect");
		btnConnectToDatabase.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						connectDatabase();
					}
				});
				if (mySQL.isConnected()) {
					errorLabel.setVisible(true);
					errorLabel.setText(" ");
					errorLabel.setForeground(Color.GREEN);
					errorLabel.setText("SQL DataBase Connect Succesful.");
					errorLabel.repaint();
				}
			}
		});
		btnConnectToDatabase.setBounds(489, 11, 104, 62);
		SQL_Panel.add(btnConnectToDatabase);

		JLabel lblEnterSqlUrl = new JLabel("Enter SQL URL");
		lblEnterSqlUrl.setBounds(10, 12, 89, 17);
		SQL_Panel.add(lblEnterSqlUrl);

		JLabel lblSqlFeedback = new JLabel("SQL FeedBack");
		lblSqlFeedback.setBounds(10, 38, 89, 20);
		SQL_Panel.add(lblSqlFeedback);

		sqlStatus = new JTextArea();
		sqlStatus.setBounds(109, 43, 370, 60);
		sqlStatus.setEditable(false);
		sqlStatus.setLineWrap(true);
		sqlStatus.setWrapStyleWord(true);

		// sp = new JScrollPane(sqlStatus);
		SQL_Panel.add(sqlStatus);

		btnViewFeed = new JButton("View Feed");
		btnViewFeed.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				SwingUtilities.invokeLater(new Runnable() {
					public void run() {
						if (Desktop.isDesktopSupported()) {
							try {
								Desktop.getDesktop().browse(new URI("http://" + streamIP.getText() + ":8081"));
							} catch (IOException e) {
								e.printStackTrace();
							} catch (URISyntaxException e) {
								e.printStackTrace();
							}
						}
					}
				});
			}
		});
		btnViewFeed.setBounds(626, 50, 89, 23);
		SQL_Panel.add(btnViewFeed);

		JLabel lblOpenUpLive = new JLabel("   Open Live Video");
		lblOpenUpLive.setBounds(603, 14, 119, 17);
		SQL_Panel.add(lblOpenUpLive);

		JSeparator separator = new JSeparator();
		separator.setBounds(603, 12, 131, 2);
		SQL_Panel.add(separator);

		separator_1 = new JSeparator();
		separator_1.setBounds(603, 30, 131, 2);
		SQL_Panel.add(separator_1);

		JPanel panel_1 = new JPanel();
		panel_1.setBackground(Color.LIGHT_GRAY);
		panel_1.setBounds(603, 12, 131, 91);
		SQL_Panel.add(panel_1);

		// Updates look and feel for all components
		SwingUtilities.updateComponentTreeUI(frame);
	}

	public Image toBufferedImage(Mat m) {
		int type = BufferedImage.TYPE_BYTE_GRAY;
		if (m.channels() > 1) {
			type = BufferedImage.TYPE_3BYTE_BGR;
		}
		int bufferSize = m.channels() * m.cols() * m.rows();
		byte[] b = new byte[bufferSize];
		m.get(0, 0, b); // get all the pixels
		BufferedImage image = new BufferedImage(m.cols(), m.rows(), type);
		final byte[] targetPixels = ((DataBufferByte) image.getRaster().getDataBuffer()).getData();
		System.arraycopy(b, 0, targetPixels, 0, b.length);
		return image;

	}

	public Mat blur(Mat input, int numberOfTimes) {
		Mat sourceImage = new Mat();
		Mat destImage = input.clone();
		for (int i = 0; i < numberOfTimes; i++) {
			sourceImage = destImage.clone();
			Imgproc.GaussianBlur(sourceImage, destImage, new Size(3.0, 3.0), 0);
		}
		return destImage;
	}
}