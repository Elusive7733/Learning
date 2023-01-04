import urllib.request, urllib.parse, urllib.error
import json
import ssl
sum = 0

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE

url = input("Enter JSON URL: ")
file = urllib.request.urlopen(url).read()

lst = json.loads(file)
# print(lst['comments'])

for item in lst['comments']:
        sum += int(item['count'])

print(sum)