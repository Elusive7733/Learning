from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# Getting Id and Password from file
f = open("C:\\Users\\HP-ZUE-5\\Desktop\\test\\BrightreeTransport.txt", "r")
password = f.readline()
id = "wyounas"
f.close()

# Setting up the driver
PATH = "C:\Program Files (x86)\chromedriver.exe"
driver = webdriver.Chrome(PATH)
driver.get("https://mobiledelivery.brightree.net")

try:
    username = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.NAME, "username"))
    )
    username.send_keys(id)
    driver.find_element_by_name("password").send_keys(password)
    driver.find_element_by_name("signIn").click()
except:
    driver.quit()

try:
    menu = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, "gn-menu"))
    )
    menu.click()
except:
    driver.quit()

try:
    sideMenu = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CLASS_NAME, "gn-menu"))
    )
    sideMenuItems = sideMenu.find_elements_by_tag_name("li")
    sideMenuItems[5].click()
except:
    driver.quit()

try:
    nav = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.CLASS_NAME, "nav-pills"))
    )
    navItems = nav.find_elements_by_tag_name("li")
    navItems[1].click()
except:
    driver.quit()


sleep(3)
driver.quit()

