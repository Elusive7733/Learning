from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from datetime import datetime, timedelta
import time

# Getting Id and Password
id = "your_id"
password = "Your_Brightree_Password"

# Setting up the driver
PATH = "C:\Program Files (x86)\chromedriver.exe"
driver = webdriver.Chrome(PATH)
driver.get("https://login.brightree.net")
driver.maximize_window()

# Wait for website to load
while True:
    username = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, "Username"))
    )
    username.clear()
    username.send_keys(id)
    driver.find_element_by_id("Password").send_keys(password)
    driver.find_element_by_id("LogInBtn").click()
    sleep(2)

    # Check if login was successful
    try:
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "menuToggle"))
        )
        break
    except:
        driver.quit()


# Navigate to reports
menuToggle = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "menuToggle"))
)
menuToggle.click()

WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "mainMenu_sbmi_10000"))
).click()

WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "mainMenu_mmi_171"))
).click()

WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.CLASS_NAME, "rpExpandHandle"))
).click()


category = WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "m_ctl00_c_c_rpbFilters_i0_txtCategory"))
)

category.send_keys("bi")

WebDriverWait(driver, 10).until(
    EC.presence_of_element_located((By.ID, "m_ctl00_c_c_rpbFilters_i0_FilterButton_input"))
).click()

# # Wait for login to complete
# try:
#     menu = WebDriverWait(driver, 10).until(
#         EC.presence_of_element_located((By.ID, "gn-menu"))
#     )
#     menu.click()
# except:
#     print(".............Error 0.............")
#     driver.quit()

# # Wait for menu to load
# try:
#     sideMenu = WebDriverWait(driver, 10).until(
#         EC.presence_of_element_located((By.CLASS_NAME, "gn-menu"))
#     )
#     sideMenuItems = sideMenu.find_elements_by_tag_name("li")
#     sleep(1)
#     sideMenuItems[5].click()
# except:
#     print(".............Error 1.............")
#     driver.quit()

# # Wait for Reports page to load
# try:
#     nav = WebDriverWait(driver, 10).until(
#         EC.presence_of_element_located((By.CLASS_NAME, "nav-pills"))
#     )
#     navItems = nav.find_elements_by_tag_name("li")
#     navItems[1].click()
# except:
#     print(".............Error 2.............")
#     driver.quit()

# # Wait for Agent Activity page to load
# try:
#     date = WebDriverWait(driver, 10).until(
#         EC.presence_of_element_located((By.NAME, "date"))
#     )
#     date.clear()

#     # Get Yesterdays date
#     yesterday = datetime.now() - timedelta(1)
#     yesterday = yesterday.strftime("%m/%d/%Y")
#     date.send_keys(yesterday)
#     date.send_keys(Keys.RETURN)
#     selection = driver.find_element_by_name("driver")
    
#     selection.click()
#     # selection.s   
#     driver.find_element_by_name("search").click()
# except:
#     print(".............Error 3.............")
#     driver.quit()


# # Wait for Agent Activity CSV to download
# try:
#     table = driver.find_element_by_id("activityGrid")
#     div = table.find_element_by_tag_name("div")
#     # Wait for table to load
#     table = WebDriverWait(driver, 15).until(
#         EC.presence_of_element_located((By.ID, "activityGrid"))
#     )
#     # anchors = table.find_elements_by_tag_name("a")
#     # print(anchors[0].text)

# except:
#     print(".............Error 4.............")
#     driver.quit()

# sleep(5)
# driver.quit()

