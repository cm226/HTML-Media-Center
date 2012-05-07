#!/usr/bin/env python
import re
import urllib2
import sys


#searchTerm = raw_input("Type the movie you want to search: \n")

searchTerm = sys.argv[1];
## Split the given movie string
searchStr = '+'.join(searchTerm.split())
## Base URL with given movie attached
urlStr = "http://www.imdb.com/find?q=%s" % (searchStr)
#file = open("data.txt", "w")
file = open("C:\wamp\www\HTML-Media-Center\scripts\data.txt", "w")
res = open("res.txt", "w")
## Regex to match the /title/tt**** in the HTML source
regex = re.compile(r'/title/tt\w*')
countline = 0
resultline = 0

## Go through the fetched HTML source and find the instances
## of /title/tt****, once the first one is found (most popular)
## save it
try:
  fileHandle = urllib2.urlopen(urlStr)
  curline = ""
  for l in fileHandle.read():	
  	if "\n" not in l:
  		curline = curline+l
  	else:
  		titles = regex.findall(curline)
  		found = False
  		for title in titles:
  			res.write(title)
  			found = True
  		if (found):			
  			break
  		curline = ""		
except IOError:
  print 'Cannot open URL %s for reading' % urlStr
  str1 = 'error!'

## Add the matched title to the base URL
urlStrRes = "http://www.imdb.com%s" % (title)
print urlStrRes

## Regex that matches the rating for the movie
regexRating = re.compile(r'^[0-9]\.[0-9]$')

########## REGEX needs to be rebuild to handle titles #########
####### like WWE American Soldier (TV 2008) - IMDb ############
#now it accepts titles like WWE American soldier (2008) - IMDb#
regexTitle = re.compile(r'[a-zA-Z\s0-9]+\([a-zA-Z0-9\s]+?\d+[a-z\&\;0-9]+?\)\s[\-]\s[a-zA-Z]+')
################################################################

## Go through the movie's fetched HTML source
## find in there the rating 
## as well as the name of the movie that was picked up
try:
  fileHandleRes = urllib2.urlopen(urlStrRes)
  curline = ""
  for l in fileHandleRes.read():	
  	if "\n" not in l:
  		curline = curline+l
  	else:
  		countline = countline+1
  		ratings = regexRating.findall(curline)
  		titles = regexTitle.findall(curline)
  		res.write(curline)
  		for title in titles:
  			resultline = countline
  			found = True
  			if (found):			
  				break
  		for rating in ratings:
  			resultline = countline
  		curline = ""
  		
except IOError:
  print 'Cannot open URL %s for reading' % urlStr
  str1 = 'error!'  
title = title.replace("&ndash;", "-")
title = title.replace("&nbsp;", " ")
## Print results
print title[:-7]
print rating
