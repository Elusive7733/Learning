from selenium import webdriver
from shutil import which
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as expect
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

cpath = which("chromedriver")
print(cpath)

driver = webdriver.Chrome(cpath)
driver.get("https://accounts.google.com/signin/v2/identifier?continue=https%3A%2F%2Fmail.google.com%2Fmail%2F&service=mail&sacu=1&rip=1&flowName=GlifWebSignIn&flowEntry=ServiceLogin")
wait = WebDriverWait(driver, 10)

email = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@class='whsOnd zHQkBf']")))
next_btn = wait.until(expect.visibility_of_element_located((By.XPATH, "//div[@class='VfPpkd-RLmnJb']")))
email.send_keys("microsoftgreedyaf@gmail.com")
next_btn.click()

# inputid = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='eid']")))
# inputpass = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='pw']")))
# submit_btn = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='submit']")))
# inputid.send_keys("K180170")
# inputpass.send_keys("passwordhere")


# 