import urllib.request
import json

endpoint = 'https://maps.googleapis.com/maps/api/directions/json?'
api_key = 'AIzaSyBUtjczBJvhIgOoPqaZxsDhINDvukuIU94'

start = input("Starting point: ").replace(' ', '+')
end = input("Ending point: ").replace(' ', '+')

nav_req = start + '&' + end + '&' + api_key 
request = endpoint + nav_req
response = urllib.request.urlopen(request).read()

directions = json.load(response)
print(directions)
