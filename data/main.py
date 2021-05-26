from dbmain import new_connection
from dbmain import new_table
valueName = ["type","datalength","searchlength","datatime","searchtime"]
valueType = f"(id serial PRIMARY KEY, {valueName[0]} VARCHAR(50), {valueName[1]} INTEGER, {valueName[2]} INTEGER, {valueName[3]} float(6), {valueName[4]} float(6))"
c = new_connection()
file = open("../output/result.txt")
if c.check_table_exist("tt") == False:
    s = new_table("tt",c,valueType)
    s.create_table()
else:
    s = new_table("tt",c,valueType)
listOfString = file.read().splitlines()
for var in listOfString:
    token = var.split(" ")
    # print(token)
    s.insert_five_values(token,valueName)
file.close()
c.close_connection()
