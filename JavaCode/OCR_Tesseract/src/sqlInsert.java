import java.sql.*;

import javax.swing.JTextArea;
import javax.swing.JTextField;
//import javax.swing.JTextPane;
//import javax.swing.text.BadLocationException;
//import javax.swing.text.StyledDocument;

/**
 * JdbcInsert1.java - Demonstrates how to INSERT data into an SQL
 *                    database using Java JDBC.
 */
class sqlInsert {
   // reference to database connection
   private Connection connection;  
   
   boolean connected;
   Person employee;
   // reference to prepared statement for locating entry
   private PreparedStatement sqlQueryEmployee;
   private JTextArea sqlStatus;
   String SQLUrl;
   
   PreparedStatement pstmt;
   ResultSet rs;
   //JTextPane textPane = new JTextPane();
  
   
    public void connect(JTextArea sqlStatusPane, JTextField sql_Url ) throws Exception{

        Class.forName("com.mysql.jdbc.Driver").newInstance();
        
        SQLUrl = sql_Url.getText();
        sqlStatus = sqlStatusPane;
        
        connection = DriverManager.getConnection("jdbc:mysql://"+SQLUrl,"root","root");
        sqlQueryEmployee = connection.prepareStatement("SELECT * FROM userdata WHERE RegistrationPlate = ?");

        
		if(connection !=null) {
        	sqlStatus.append("Connected to Database\n");
        	connected = true;
        }
        else {
        	sqlStatus.append("Failed to Connect\n");
        	connected = false;
        }
        
    }
    public boolean checkPlate(String data) {

	      // insert person in database
	      try {
	         int result =0;
	         data = data.replace("\n", "");
	         data = data.replace("\r", "");
	         data = data.replaceAll("\\s+","");

	         pstmt = connection.prepareStatement(
	        		  "SELECT * FROM userdata "); 
	        		                                  // Create a PreparedStatement object    1 
    		//pstmt.setString(1,data);      // Assign value to input parameter      2 

    		rs = pstmt.executeQuery();        // Get the result table from the query  3 
    		while (rs.next()) {               // Position the cursor                  4 
    			employee.setName(rs.getString("Name"));
            	employee.setReg(rs.getString("RegistrationPlate"));
            	employee.setLastActivity(rs.getString("lastActivity"));                             // Print the column values
            	System.out.print("Data: "+employee.getName()+employee.getReg());
    		}
    		rs.close();                       // Close the ResultSet                  5 
    		pstmt.close();                    // Close the PreparedStatement          6 

	         if(rs.equals(null)) {
	            connection.rollback(); // rollback insert
	            sqlStatus.append("\nAccess Denied, No Database Record Found!");
	            return false;         // insert unsuccessful   
	         }
	         
	      } catch (Exception e) {
            sqlStatus.append("SQL EXCEPTION: "+e.getMessage());
            
        }
		return true;
        
    }

}