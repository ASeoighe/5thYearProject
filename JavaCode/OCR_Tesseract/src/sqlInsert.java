import java.sql.*;

/**
 * JdbcInsert1.java - Demonstrates how to INSERT data into an SQL
 *                    database using Java JDBC.
 */
class sqlInsert {
   // reference to database connection
   private Connection connection;  
   // reference to prepared statement for locating entry
   private PreparedStatement sqlInsertPlate;
   
   public sqlInsert() throws Exception {
	  
	   connect();
	   sqlInsertPlate = connection.prepareStatement("INSERT INTO platedata ( plateData ) VALUES (?)");

	   
   }
    private void connect() throws Exception{
    	// Cloudscape database driver class name
        Class.forName("com.mysql.jdbc.Driver").newInstance();
        //Connection conn = DriverManager.getConnection("jdbc:mysql://localhost:3307/books?user=root");
        connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/licenseplates","root","root");

        System.out.println("connected to sqlDatabase");
        // connect to database
        //connection = DriverManager.getConnection( url );

        // Require manual commit for transactions. This enables
        // the program to rollback transactions that do not
        // complete and commit transactions that complete properly.
        connection.setAutoCommit( false );
    }
    public boolean insertPlate(String data) {

	      // insert person in database
	      try {
	         int result =0;
	         //data = "hello";
	         // insert first and last name in names table
	         sqlInsertPlate.setString( 1, data );
	        // sqlInsertPlate.

	         result = sqlInsertPlate.executeUpdate();
	
	         // if insert fails, rollback and discontinue 
	         if ( result == 0 ) {
	            connection.rollback(); // rollback insert
	            return false;          // insert unsuccessful   
            
        }} catch (Exception e) {
            System.err.println("Got an exception! ");
            System.err.println(e.getMessage());
            return false;
        }
		return true;
        
    }

}