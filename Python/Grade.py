score = float(input("Enter Score: "))

if score > 1.0 or score < 0.0:
    print("Error - score is out of range\n")
elif score >= 0.9:
    print("A\n")
elif score >= 0.8:
    print("B\n")
elif score >= 0.7: 
    print("C\n")
elif score >= 0.6:
    print("D\n")
else:
    print("F\n")
