with open("fake_log.txt", "w") as file:
    for i in range(20):
        file.write("blá")
    file.write("\n")

    file.write("palavra-mágica")
    
    file.write("\n")

    for i in range(20):
        file.write("blá")
