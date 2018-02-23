import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgcodecs.*;
import org.opencv.imgproc.Imgproc;

public class squareDetect {

    public static void main(String[] args) {
        try {
            System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
            String dir = "C:\\Users\\Aaron Scally Seoighe\\Documents\\GitHub\\5thYearProject\\testImages\\PlateImages\\18.png";
            Mat source = Imgcodecs.imread(dir, Imgcodecs.CV_LOAD_IMAGE_ANYCOLOR);
            Mat destination = new Mat(source.rows(), source.cols(), source.type());

            Imgproc.cvtColor(source, destination, Imgproc.COLOR_RGB2GRAY);
            int threshold = 100;

            Imgproc.Canny(source, destination, threshold, threshold*3);

            //Now find the contours in edge image.

            //Imgproc.findContours(edges, contours, hierarchy, Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_SIMPLE);
            Imgproc.equalizeHist(destination, destination);
            Imgproc.GaussianBlur(destination, destination, new Size(5, 5), 0, 0, Core.BORDER_DEFAULT);

            Imgproc.Canny(destination, destination, 50, 100);
            //Imgproc.adaptiveThreshold(destination, destination, 255, Imgproc.ADAPTIVE_THRESH_MEAN_C, Imgproc.THRESH_BINARY, 15, 40);
            Imgproc.threshold(destination, destination, 0, 255, Imgproc.THRESH_BINARY);

            if (destination != null) {
                Mat lines = new Mat();
                Imgproc.HoughLinesP(destination, lines, 1, Math.PI / 180, 50, 30, 10);
                Mat houghLines = new Mat();
                houghLines.create(destination.rows(), destination.cols(), CvType.CV_8UC1);

                //Drawing lines on the image
                for (int i = 0; i < lines.cols(); i++) {
                    double[] points = lines.get(0, i);
                    double x1, y1, x2, y2;
                    x1 = points[0];
                    y1 = points[1];
                    x2 = points[2];
                    y2 = points[3];

                    Point pt1 = new Point(x1, y1);
                    Point pt2 = new Point(x2, y2);

                    //Drawing lines on an image
                    Imgproc.line(source, pt1, pt2, new Scalar(0, 0, 255), 4);
                }

            }

            Imgcodecs.imwrite("rectangle_houghtransform.jpg", source);
            
            System.out.print("Complete!, Directory: "+source);
            
        } catch (Exception e) {
            System.out.println("error: " + e.getMessage());
        }
    }
}