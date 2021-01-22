def hello_world():
    print("Hello world from sub_script")

print("indent = 0 at sub_script")

if __name__ == "__main__":
    print("sub_script run directly")
else:
    print("sub_script imported")