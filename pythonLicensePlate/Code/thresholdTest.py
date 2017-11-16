
imgPath='C:\Users\Aaron Scally Seoighe\Desktop\pythonLicensePlate\\18.jpg'

import cv2
import numpy as np

img = cv2.imread('C:\Users\Aaron Scally Seoighe\Desktop\pythonLicensePlate\\18.jpg')
grayscaled = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
retval, threshold = cv2.threshold(grayscaled, 185, 255, cv2.THRESH_BINARY)
cv2.imshow('original',img)

cv2.imshow('threshold',threshold)
cv2.waitKey(0)
cv2.destroyAllWindows()
