import java.sql.*;

import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JTextPane;
import javax.swing.text.BadLocationException;
import javax.swing.text.StyledDocument;

/**
 * JdbcInsert1.java - Demonstrates how to INSERT data into an SQL
 *                    database using Java JDBC.
 */
class sqlInsert {
   // reference to database connection
   private Connection connection;  
   // reference to prepared statement for locating entry
   private PreparedStatement sqlInsertPlate;
   private JTextArea sqlStatus;
   String SQLUrl;
   //JTextPane textPane = new JTextPane();
  
   
   public sqlInsert(JTextArea sqlStatusPane, JTextField sql_Url ) throws Exception {
	  
	   sqlStatus = sqlStatusPane;
	   SQLUrl = sql_Url.getText();
	   System.out.println("URL IS: "+SQLUrl);
	   connect();
	   sqlInsertPlate = connection.prepareStatement("INSERT INTO platedata ( plateData ) VALUES (?)");	   
	   
   }
    public void connect() throws Exception{
    	// Cloudscape database driver class name
        Class.forName("com.mysql.jdbc.Driver").newInstance();
        //Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3307/books?user=root");
        //localhost:3306/licenseplates
        //System.out.println("##### "+SQLUrl);
        connection = DriverManager.getConnection("jdbc:mysql://"+SQLUrl,"root","root");

        System.out.println("connected to sqlDatabase");
        sqlStatus.append("\n"+connection);
        // connect to database
        //connection = DriverManager.getConnection( url );

        // Require manual commit for transactions. This enables
        // the program to rollback transactions that do not
        // complete and commit transactions that complete properly.
        //connection.setAutoCommit( false );
    }
    public boolean insertPlate(String data) {

	      // insert person in database
	      try {
	         int result =0;
	         //data = "hello";
	         // insert first and last name in names table
	         //System.out.println("LicensePlate Data : "+data);
	         sqlInsertPlate.setString( 1, data );
	        // sqlInsertPlate.

	         result = sqlInsertPlate.executeUpdate();
	         
	         // if insert fails, rollback and discontinue 
	         if ( result == 0 ) {
	            connection.rollback(); // rollback insert
	            sqlStatus.append("\nError with SQL Update, Update Not Succesfull");
	            return false;          // insert unsuccessful   
            
        }} catch (Exception e) {
            System.err.println("Got an exception! ");
            sqlStatus.append("SQL EXCEPTION: "+e.getMessage());
            System.err.println(e.getMessage());
            return false;
        }
	      sqlStatus.append("\nUpdate Successful, License Plate added to Database.");
		return true;
        
    }

}