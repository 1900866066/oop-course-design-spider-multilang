import requests
from lxml import html
import csv
import sys
BASE_URL=f"https://www.hnieacm.com/"
#排行榜开始
start=0
#爬取页数1-80
page=sys.argv[1]
#爬取前150名学号和姓名
st_list = []
for i in range(int(page)):
    response=requests.get(f"https://www.hnieacm.com/ranklist.php?start={start}")
    re=html.fromstring(response.text)
    student_list=re.xpath("//*[@id='main_container']/table/tbody/tr")
    start+=50
    for s in student_list:
        st = {}
        name=s.xpath("./td[2]/div/a/text()")
        num=s.xpath("./td[4]/div/text()")
        st["name"]=name
        st["num"]=num
        print(name,num)
        st_list.append(st)
with open("湖南工程学院OJ学生信息.csv","w",encoding="utf-8",newline="") as f:
    writer=csv.writer(f)
    writer.writerow(["学号","姓名"])
    for a in st_list:
        writer.writerow([a["name"],a["num"]])