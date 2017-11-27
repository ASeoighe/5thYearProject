package net.sourceforge.lept4j;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.FloatByReference;
import java.util.Arrays;
import java.util.List;
/**
 * Pix with float array<br>
 * <i>native declaration : pix.h:183</i><br>
 * This file was autogenerated by <a href="http://jnaerator.googlecode.com/">JNAerator</a>,<br>
 * a tool written by <a href="http://ochafik.com/">Olivier Chafik</a> that <a href="http://code.google.com/p/jnaerator/wiki/CreditsAndLicense">uses a few opensource projects.</a>.<br>
 * For help, please visit <a href="http://nativelibs4java.googlecode.com/">NativeLibs4Java</a> or <a href="http://jna.dev.java.net/">JNA</a>.
 */
public class FPix extends Structure {
	/**
	 * width in pixels<br>
	 * C type : l_int32
	 */
	public int w;
	/**
	 * height in pixels<br>
	 * C type : l_int32
	 */
	public int h;
	/**
	 * 32-bit words/line<br>
	 * C type : l_int32
	 */
	public int wpl;
	/**
	 * reference count (1 if no clones)<br>
	 * C type : l_uint32
	 */
	public int refcount;
	/**
	 * image res (ppi) in x direction<br>
	 * C type : l_int32
	 */
	public int xres;
	/**
	 * image res (ppi) in y direction<br>
	 * C type : l_int32
	 */
	public int yres;
	/**
	 * the float image data<br>
	 * C type : l_float32*
	 */
	public FloatByReference data;
	public FPix() {
		super();
	}
	protected List<? > getFieldOrder() {
		return Arrays.asList("w", "h", "wpl", "refcount", "xres", "yres", "data");
	}
	/**
	 * @param w width in pixels<br>
	 * C type : l_int32<br>
	 * @param h height in pixels<br>
	 * C type : l_int32<br>
	 * @param wpl 32-bit words/line<br>
	 * C type : l_int32<br>
	 * @param refcount reference count (1 if no clones)<br>
	 * C type : l_uint32<br>
	 * @param xres image res (ppi) in x direction<br>
	 * C type : l_int32<br>
	 * @param yres image res (ppi) in y direction<br>
	 * C type : l_int32<br>
	 * @param data the float image data<br>
	 * C type : l_float32*
	 */
	public FPix(int w, int h, int wpl, int refcount, int xres, int yres, FloatByReference data) {
		super();
		this.w = w;
		this.h = h;
		this.wpl = wpl;
		this.refcount = refcount;
		this.xres = xres;
		this.yres = yres;
		this.data = data;
	}
	public FPix(Pointer peer) {
		super(peer);
		read();
	}
	public static class ByReference extends FPix implements Structure.ByReference {
		
	};
	public static class ByValue extends FPix implements Structure.ByValue {
		
	};
}
