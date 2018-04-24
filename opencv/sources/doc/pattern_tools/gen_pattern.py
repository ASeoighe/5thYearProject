#!/usr/bin/env python

"""gen_pattern.py
<<<<<<< HEAD
To run:
-c 10 -r 12 -o out.svg
-T type of pattern, circles, acircles, checkerboard
-s --square_size size of squares in pattern
-u --units mm, inches, px, m
-w  page width in units
-h  page height in units
=======
Usage example:
python gen_pattern.py -o out.svg -r 11 -c 8 -T circles -s 20.0 -R 5.0 -u mm -w 216 -h 279

-o, --output - output file (default out.svg)
-r, --rows - pattern rows (default 11)
-c, --columns - pattern columns (default 8)
-T, --type - type of pattern, circles, acircles, checkerboard (default circles)
-s, --square_size - size of squares in pattern (default 20.0)
-R, --radius_rate - circles_radius = square_size/radius_rate (default 5.0)
-u, --units - mm, inches, px, m (default mm)
-w, --page_width - page width in units (default 216)
-h, --page_height - page height in units (default 279)
-H, --help - show help
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
"""

from svgfig import *

import sys
import getopt

class PatternMaker:
<<<<<<< HEAD
  def __init__(self, cols,rows,output,units,square_size,page_width,page_height):
=======
  def __init__(self, cols,rows,output,units,square_size,radius_rate,page_width,page_height):
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    self.cols = cols
    self.rows = rows
    self.output = output
    self.units = units
    self.square_size = square_size
<<<<<<< HEAD
    self.width = page_width
    self.height = page_height
    self.g = SVG("g") # the svg group container
  def makeCirclesPattern(self):
    spacing = self.square_size
    r = spacing / 5.0 #radius is a 5th of the spacing TODO parameterize
=======
    self.radius_rate = radius_rate
    self.width = page_width
    self.height = page_height
    self.g = SVG("g") # the svg group container

  def makeCirclesPattern(self):
    spacing = self.square_size
    r = spacing / self.radius_rate
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    for x in range(1,self.cols+1):
      for y in range(1,self.rows+1):
        dot = SVG("circle", cx=x * spacing, cy=y * spacing, r=r, fill="black")
        self.g.append(dot)

  def makeACirclesPattern(self):
    spacing = self.square_size
<<<<<<< HEAD
    r = spacing / 5.0
=======
    r = spacing / self.radius_rate
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    for i in range(0,self.rows):
      for j in range(0,self.cols):
        dot = SVG("circle", cx= ((j*2 + i%2)*spacing) + spacing, cy=self.height - (i * spacing + spacing), r=r, fill="black")
        self.g.append(dot)

  def makeCheckerboardPattern(self):
    spacing = self.square_size
<<<<<<< HEAD
    r = spacing / 5.0
    for x in range(1,self.cols+1):
      for y in range(1,self.rows+1):
        #TODO make a checkerboard pattern
        dot = SVG("circle", cx=x * spacing, cy=y * spacing, r=r, fill="black")
        self.g.append(dot)
=======
    for x in range(1,self.cols+1):
      for y in range(1,self.rows+1):
        if x%2 == y%2:
          dot = SVG("rect", x=x * spacing, y=y * spacing, width=spacing, height=spacing, stroke_width="0", fill="black")
          self.g.append(dot)

>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
  def save(self):
    c = canvas(self.g,width="%d%s"%(self.width,self.units),height="%d%s"%(self.height,self.units),viewBox="0 0 %d %d"%(self.width,self.height))
    c.inkview(self.output)

<<<<<<< HEAD
def makePattern(cols,rows,output,p_type,units,square_size,page_width,page_height):
    width = page_width
    spacing = square_size
    height = page_height
    r = spacing / 5.0
    g = SVG("g") # the svg group container
    for x in range(1,cols+1):
      for y in range(1,rows+1):
        if "circle" in p_type:
          dot = SVG("circle", cx=x * spacing, cy=y * spacing, r=r, fill="black")
        g.append(dot)
    c = canvas(g,width="%d%s"%(width,units),height="%d%s"%(height,units),viewBox="0 0 %d %d"%(width,height))
    c.inkview(output)

=======
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d

def main():
    # parse command line options, TODO use argparse for better doc
    try:
<<<<<<< HEAD
        opts, args = getopt.getopt(sys.argv[1:], "ho:c:r:T:u:s:w:h:", ["help","output","columns","rows",
                                                                      "type","units","square_size","page_width",
                                                                      "page_height"])
=======
        opts, args = getopt.getopt(sys.argv[1:], "Ho:c:r:T:u:s:R:w:h:", ["help","output=","columns=","rows=",
                                                                      "type=","units=","square_size=","radius_rate=",
                                                                      "page_width=","page_height="])
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    except getopt.error, msg:
        print msg
        print "for help use --help"
        sys.exit(2)
    output = "out.svg"
    columns = 8
    rows = 11
    p_type = "circles"
    units = "mm"
    square_size = 20.0
<<<<<<< HEAD
=======
    radius_rate = 5.0
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    page_width = 216    #8.5 inches
    page_height = 279   #11 inches
    # process options
    for o, a in opts:
<<<<<<< HEAD
        if o in ("-h", "--help"):
=======
        if o in ("-H", "--help"):
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
            print __doc__
            sys.exit(0)
        elif o in ("-r", "--rows"):
            rows = int(a)
        elif o in ("-c", "--columns"):
            columns = int(a)
        elif o in ("-o", "--output"):
            output = a
        elif o in ("-T", "--type"):
            p_type = a
        elif o in ("-u", "--units"):
            units = a
        elif o in ("-s", "--square_size"):
            square_size = float(a)
<<<<<<< HEAD
=======
        elif o in ("-R", "--radius_rate"):
            radius_rate = float(a)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
        elif o in ("-w", "--page_width"):
            page_width = float(a)
        elif o in ("-h", "--page_height"):
            page_height = float(a)
<<<<<<< HEAD
    pm = PatternMaker(columns,rows,output,units,square_size,page_width,page_height)
=======
    pm = PatternMaker(columns,rows,output,units,square_size,radius_rate,page_width,page_height)
>>>>>>> 4a5a6cfc1ba26f73cbd6c6fcaf561ca6dbced81d
    #dict for easy lookup of pattern type
    mp = {"circles":pm.makeCirclesPattern,"acircles":pm.makeACirclesPattern,"checkerboard":pm.makeCheckerboardPattern}
    mp[p_type]()
    #this should save pattern to output
    pm.save()

if __name__ == "__main__":
    main()
