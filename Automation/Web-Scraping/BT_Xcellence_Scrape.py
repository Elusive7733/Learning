from time import sleep
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait, Select
from selenium.webdriver.support import expected_conditions as EC
from datetime import datetime, timedelta
import time

def GetReport(driver, link, ReportName):
    sleep(2)
    driver.get(link)
    # if(ReportName == "AR By Payor"):
    #     # print(ReportName)
    #     WebDriverWait(driver, 10).until(
    #         EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_cbxChrgFilterOnGLPd_ctl00"))
    #     ).click()
    #     WebDriverWait(driver, 10).until(
    #         EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_cbxPmtFilterOnGLPd_ctl00"))
    #     ).click()
            
    #     try:
    #         print("Getting AR By Payor")
    #         Select(WebDriverWait(driver, 10).until(
    #             EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_ddlReportOutputType_cb"))
    #         )).select_by_value(4)

    #         sleep(5)

    #         Select(WebDriverWait(driver, 10).until(
    #             EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_ddlChrgGLPeriodFrom_cb"))
    #         )).select_by_value(317)

    #         Select(WebDriverWait(driver, 10).until(
    #             EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_ddlChrgGLPeriodTo_cb"))
    #         )).select_by_value(319)


    #         Select(WebDriverWait(driver, 10).until(
    #             EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_ddlPmtGLPeriodFrom_cb"))
    #         )).select_by_value(317)

    #         Select(WebDriverWait(driver, 10).until(
    #             EC.presence_of_element_located((By.ID, "ctl00_m_ctl00_c_c_c_ddlPmtGLPeriodTo_cb"))
    #         )).select_by_value(319)

    #         sleep(2)

    #         WebDriverWait(driver, 10).until(
    #             EC.presence_of_all_elements_located((By.ID, "ctl00_m_ctl00_c_c_btnPreview_input"))
    #         ).click()
            
    #         sleep(10)

    #     except:
    #         print(f"Couldn't Request {ReportName}")
    #         driver.quit()
    # else:
    try:
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "ctl00_c_ctl00_Refresh"))
        ).click()
    except:
        print(f"Couldn't Refresh {ReportName}")
        driver.quit()

    sleep(2)

    try:
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "ctl00_c_AdhocToolbarControl1_btnPreview"))
        ).click()
    except:
        print(f"Couldn't Request {ReportName}")
        driver.quit()

def Login(driver):
    # Getting Id and Password from file
    id = "raheel@nhmedsupply"
    f = open("C:\\Users\\HP-ZUE-5\\Desktop\\test\\Brightree.txt", "r")
    password = f.readline()
    f.close()

    driver.get("https://login.brightree.net")
    driver.minimize_window()

    # Wait for website to load
    while True:
        username = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "Username"))
        )
        username.clear()
        username.send_keys(id)
        driver.find_element_by_id("Password").send_keys(password)
        driver.find_element_by_id("LogInBtn").click()
        sleep(1)

        # Check if login was successful
        try:
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.ID, "menuToggle"))
            )
            break
        except:
            print("Couldn't Login")

def DeleteReport(driver, window):
    driver.get("https://brightree.net/F1/0320/NHMedSupply/SystemSetup/frmReportScheduleOutput.aspx")

    try:
        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "m_ctl00_c_c_dgResults_ctl00_ctl02_ctl01_ClientSelectColumnSelectCheckBox"))
        ).click()

        WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.ID, "m_ctl00_c_c_btnDelete_input"))
        ).click()
        
        driver.switch_to.window(window)
        sleep(5)
        driver.minimize_window()

        # driver.switch_to_frame("aspnetForm")
        # driver.switch_to_default_content()


        # WebDriverWait(driver, 10).until(
        #     EC.presence_of_element_located((By.ID, "ctl00_c_lbtnYes_input"))
        # ).click()

        # driver.find_element_by_xpath("//form[@id='aspnetForm']/input[0]").click()

        # yesbtn = driver.find_element_by_xpath("/html/body/form/div[3]/div[2]/span[1]/input[1]")
        # yesbtn.click()

    except:
        print("No Reports to Delete")
    
if __name__ == "__main__":
    # Setting up the driver
    PATH = "C:\Program Files (x86)\chromedriver.exe"
    driver = webdriver.Chrome(PATH)
    window = driver.current_window_handle

    Login(driver)

    sleep(1)

    DeleteReport(driver, window)

    # GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Reports/frmARActivityReportByPayor.aspx", "AR By Payor")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\Brightree+Invoice+number+and+SO+number", "BT Invoice Number and SO Number")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\BT+Analysis+SO+Details", "BT Analysis SO Details")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\Doctor+Detailed+List", "Doctor Detailed List")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\Patient+ID+and+Security+Group", "Patient ID and Security Group")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\Voided+Sales+Order+All+fields", "Voided Sales Order All Fields")
    GetReport(driver, "https://brightree.net/F1/0320/NHMedSupply/Home/frmMyAdhocViewer.aspx?rn=BI\Survey+Form+Notes", "Survey Form Notes")
