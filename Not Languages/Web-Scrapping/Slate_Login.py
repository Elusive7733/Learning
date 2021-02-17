from selenium import webdriver
from shutil import which
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as expect
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

cpath = which("chromedriver")
print(cpath)

driver = webdriver.Chrome(cpath)
driver.get("http://slate.nu.edu.pk/portal")
wait = WebDriverWait(driver, 20)

inputid = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='eid']")))
inputpass = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='pw']")))
submit_btn = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='submit']")))
inputid.send_keys("K180170")
inputpass.send_keys("")
submit_btn.click()


# https://www.google.com/intl/en-GB/gmail/about/#