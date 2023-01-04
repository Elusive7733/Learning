import urllib.request, urllib.parse, urllib.error
import xml.etree.ElementTree as ET
import ssl
sum = 0

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input("Enter XML URL: ")
file = urllib.request.urlopen(url).read()

commentinfo = ET.fromstring(file)
lst = commentinfo.findall('comments/comment')

for item in lst:
    sum += int(item.find('count').text)

print(sum)