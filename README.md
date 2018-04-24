# Aaron Scally
# 5th Year Project
#BEng(Hons) Computer & Electronic Engineering

Access Control Project, using ANPR for Optical Character Recognition(O.C.R)  using MySQL, rPI, Java, Python

-------------------------------------------------------------------------------------------------------------------
As of: 11/12/2017
-------------------------------------------------------------------------------------------------------------------
Functionality includes:
  - Client Gui Application written on Java
  - Application uses Tesseract opensource Libraries to help with Optical Character Recognition (OCR) for coverting Images to plain Text
  - Writes Characters to outputtes .txt File as well as sending to a specified mySQL database Server
  - All fucntionality stated above i working with possible minor flaws / kinks.
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------
As of: 8/02/2018
-------------------------------------------------------------------------------------------------------------------
Functionality Includes:
  - working Java GUI executable from Jar file on a Windows OS
  - Image Plate Detection (Still Nedds tweaking, Nowhere near perfect)
  - process calling to a .exe program written in C++ from the java GUI which performs and Object Detect and Crop.
    This then feeds the image back into the Java GUI to perform the Optical Character Recognition (OCR) to extract raw text from the     image
-------------------------------------------------------------------------------------------------------------------
As of: 17/03/2018
-------------------------------------------------------------------------------------------------------------------
Functionality Includes:
  - IP Camera Server 
  - Includes Motion detection and Object Motion Tracking (Basic Not Optimised)
  - Port forwarded Ip address and Specific Port to be able to stream Anywhere.
  - GUI opening on linux but needs to be rebuilt on a linux machine for hava code to read proper dependency paths.
-------------------------------------------------------------------------------------------------------------------
As of: 06/04/2018
-------------------------------------------------------------------------------------------------------------------
  Actvity Log:
-------------------------------------------------------
Been Trying to Build and Compile openCv to work on Linux OS on the rPi. Ive ran into countless issues and compatibility errors and    roughly 100 SD Cards (Slight Exageration), due to corruption and unknnown errors. This step has been the most time consuming leg of the project. it has been almost a month in progress and still have yet to succesfully execute a build using MAKE on linux and perform the install. 
-------------------------------------------------------------------------------------------------------------------
As of: 24/04/2018
-------------------------------------------------------------------------------------------------------------------
  Actvity Log:
-------------------------------------------------------
Been going good, alo of work to get the Client program UI to work on the Pi and when it does its very laggy due to the low resources available. I have an earlier version runnning and the current version runnin on the DesktopPC.
I have acheived live Streaming from the pi to the browser and came up with a solution to get live feed into the gui. originally i was reading the page data separated by the --BoundaryString which separates each JPEG data file of the stream but this was unreliable and was reading in corrupt images. A succesful workaround with roughly 1 FPS is runnin a script on the Camera server to take a snapshot every 1 second. it then saves that file to a static directory wh9ch is then accessed by the gui constantly in a background procesws using SFTP to transfer the Image file. this is working very well and stores the Images without a hitch.
I also retrained Tesseract OCR with a specifin license plate font as well as created a Haar_Cascade XMl for successful plate detection.
It is working with a live video input but incorporating it into the Java Gui isnt working out well, an had to reWrite it for the 50th time to work with saticimages instead of a live video due to the SFTP File stream simulation live feed.
-------------------------------------------------------------------------------------------------------------------
Functionality Includes:
  - Camera server Stream into GUI
  - Updated Graphical User Interface for Clien program
  - Re-written C++ programs to crop image to Plate region of interest
  - HaarCascade for Object detection 
  - Tesseract Accuracy improved greatly with Retraining with Specific Plate fonts.
  
-------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------

