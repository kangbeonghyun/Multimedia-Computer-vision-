# Multimedia-Computer-vision-

• Implement a simple stereo matching algorithm by window- based matching.

  Use the given Tzukuba stereo image pair:
• DownloadthehalfsizeofTzukubaimagefrom
“ http://vision.middlebury.edu/stereo/data/scenes2001/ ”

• Leftimage:“scene1.row3.col2.png”
• Rightimage:“scene1.row3.col3.png”
• Groundtruthdisparitymap:“truedisp.row3.col3”
• Resolution:384x288pixels

• Instructions:
  Set the disparity search range as from 0 to 16 pixels.
  Matching cost computation: SSD (Sum of Squared Difference) between pixels in the left and right images
  Use WTA (winner-takes-all) method for the selection of the best match
