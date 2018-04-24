package net.sourceforge.lept4j;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.PointerByReference;
import java.util.Arrays;
import java.util.List;
/**
 * Array of arrays of pix<br>
 * <i>native declaration : pix.h:90</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class Pixaa extends Structure {
	/**
	 * number of Pixa in ptr array<br>
	 * C type : l_int32
	 */
	public int n;
	/**
	 * number of Pixa ptrs allocated<br>
	 * C type : l_int32
	 */
	public int nalloc;
	/**
	 * array of ptrs to pixa<br>
	 * C type : Pixa**
	 */
	public PointerByReference pixa;
	/**
	 * array of boxes<br>
	 * C type : Boxa*
	 */
	public net.sourceforge.lept4j.Boxa.ByReference boxa;
	public Pixaa() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("n", "nalloc", "pixa", "boxa");
	}
	/**
	 * @param n number of Pixa in ptr array<br>
	 * C type : l_int32<br>
	 * @param nalloc number of Pixa ptrs allocated<br>
	 * C type : l_int32<br>
	 * @param pixa array of ptrs to pixa<br>
	 * C type : Pixa**<br>
	 * @param boxa array of boxes<br>
	 * C type : Boxa*
	 */
	public Pixaa(int n, int nalloc, PointerByReference pixa, net.sourceforge.lept4j.Boxa.ByReference boxa) {
		super();
		this.n = n;
		this.nalloc = nalloc;
//		if ((pixa.length != this.pixa.length)) 
//			throw new IllegalArgumentException("Wrong array size !");
		this.pixa = pixa;
		this.boxa = boxa;
	}
	public Pixaa(Pointer peer) {
		super(peer);
		read();
	}
	public static class ByReference extends Pixaa implements Structure.ByReference {
		
	};
	public static class ByValue extends Pixaa implements Structure.ByValue {
		
	};
}
