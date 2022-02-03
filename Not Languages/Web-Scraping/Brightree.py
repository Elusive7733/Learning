from selenium import webdriver

PATH = "C:\Program Files (x86)\chromedriver.exe"
driver = webdriver.Chrome(PATH)
driver.get("https://login.brightree.net")
print(driver.title)   # => "Brightree"
driver.quit()