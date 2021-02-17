from selenium import webdriver
from shutil import which
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as expect
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys

cpath = which("chromedriver")
print(cpath)

driver = webdriver.Chrome(cpath)
driver.get("http://flexstudent.nu.edu.pk/Login")
wait = WebDriverWait(driver, 20)

inputid = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='m_inputmask_4']")))
inputpass = wait.until(expect.visibility_of_element_located((By.XPATH, "//input[@id='pass']")))
captha_btn = wait.until(expect.visibility_of_element_located((By.XPATH, "//div[@class='recaptcha-checkbox-border']")))
submit_btn = wait.until(expect.visibility_of_element_located((By.XPATH, "//button[@id='m_login_signin_submit']")))

inputid.send_keys("18K-0170")
inputpass.send_keys("Doto4lyf")
captha_btn.click()
submit_btn.click()