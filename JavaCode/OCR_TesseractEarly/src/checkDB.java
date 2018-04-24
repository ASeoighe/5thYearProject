import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.swing.JTextArea;

public class checkDB {
	private Connection connection;
	private boolean connected = true;
	private boolean regExists = false;

	private JTextArea statusBar;
	private String dbURL = null;

	private String data = null;
	private Person employee = new Person();

	public checkDB() {
		//connection = null;
	}

	public void connect() {
		try {

			// Load the MySQL JDBC driver

			String driverName = "com.mysql.jdbc.Driver";


			try {
				Class.forName(driverName).newInstance();
			} catch (InstantiationException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			}

			// Create a connection to the database

			String url = "jdbc:mysql://" + dbURL;

			String username = "root";

			String password = "root";

			try {
				connection = DriverManager.getConnection(url, username, password);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

			statusBar.setText("Successfully Connected to the database!\n");
			statusBar.setText(connection.toString());
			connected = true;

		} catch (ClassNotFoundException e) {
			
			//statusBar.setText("Could not find the database driver " + e.getMessage());
		}
	}

	public void checkData(String reg) {

		// Get a result set containing all data from test_table
		//connect();
		
		//Statement statement;
		// Get a result set containing all data from test_table
try {
	reg = reg.replaceAll("\n", "");
	reg = reg.replaceAll("\\s+", "");
		Statement statement = connection.createStatement();

		ResultSet results = statement.executeQuery("SELECT * FROM userdata WHERE RegistrationPlate = '"+reg+"'");


		// For each row of the result set ...

		while (results.next()) {


		  // Get the data from the current row using the column index - column data are in the VARCHAR format

		  String data = results.getString(1);

		 // System.out.println("Fetching data by column index for row " + results.getRow() + " : " + data);


		  // Get the data from the current row using the column name - column data are in the VARCHAR format

		  //data = "\nEmployee Name: "+results.getString("Name")+"\nEmployee Registration: "+results.getString("RegistrationPlate")+"\nLast Activity: "+results.getString("LastActivity")+" Accessed Front Gate";
		  
		  employee.setName(results.getString("Name"));
		  employee.setReg(results.getString("RegistrationPlate"));
		  employee.setLastActivity(results.getString("LastActivity"));
		  //System.out.println("Fetching data by column name for row " + results.getRow() + " : " + data);


		}

				if (!results.isBeforeFirst()) {
					regExists = false;
				}
			}catch(Exception e) {
				e.printStackTrace();
			}
	}
		
	

	public void setUrl(String url) {
		dbURL = url;
	}

	public boolean doesRegExist() {
		return regExists;
	}

	public boolean isConnected() {
		return connected;
	}

	public Person getEmployee() {
		return employee;
	}

	public void setStatusPane(JTextArea sqlStatus) {
		statusBar = sqlStatus;
	}

}
