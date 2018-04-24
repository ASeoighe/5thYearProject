package net.sourceforge.lept4j;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
/**
 * <i>native declaration : array.h:28</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class L_Dnaa extends Structure {
	/**
	 * size of allocated ptr array<br>
	 * C type : l_int32
	 */
	public int nalloc;
	/**
	 * number of L_Dna saved<br>
	 * C type : l_int32
	 */
	public int n;
	/**
	 * array of L_Dna<br>
	 * C type : L_Dna**
	 */
	public PointerByReference dna;
	public L_Dnaa() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("nalloc", "n", "dna");
	}
	/**
	 * @param nalloc size of allocated ptr array<br>
	 * C type : l_int32<br>
	 * @param n number of L_Dna saved<br>
	 * C type : l_int32<br>
	 * @param dna array of L_Dna<br>
	 * C type : L_Dna**
	 */
	public L_Dnaa(int nalloc, int n, PointerByReference dna) {
		super();
		this.nalloc = nalloc;
		this.n = n;
//		if ((dna.length != this.dna.length)) 
//			throw new IllegalArgumentException("Wrong array size !");
		this.dna = dna;
	}
	public L_Dnaa(Pointer peer) {
		super(peer);
		read();
	}
	public static class ByReference extends L_Dnaa implements Structure.ByReference {
		
	};
	public static class ByValue extends L_Dnaa implements Structure.ByValue {
		
	};
}
