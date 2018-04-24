
public class Person {

	private String name;
	private String Reg;
	private String lastActivity;
	
	
	public Person(String n,String r, String lA){
		setName(n);
		setReg(r);
		setLastActivity(lA);
	}


	public Person() {
		// TODO Auto-generated constructor stub
	}


	public String getLastActivity() {
		return lastActivity;
	}


	public void setLastActivity(String lastActivity) {
		this.lastActivity = lastActivity;
	}


	public String getReg() {
		return Reg;
	}


	public void setReg(String reg) {
		Reg = reg;
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}
	
	public String toString() {
		return "Employee Name: \t"+name+
				"\nRegistration: \t"+Reg+
				"\nLast Activity: \t"+lastActivity;
				
	}
}
