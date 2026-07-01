import requests
import csv
from lxml import html
import re
import sys
import io
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='gbk')
BASE_URL="https://www.hnieacm.com/"
#所有问题的url
problem_list_url=[]

getPage=int(sys.argv[1])#爬取的页数
getPage+=1
#获取所有问题的url一共23页
for page in range(1,getPage):
    response=requests.get(f"https://www.hnieacm.com/problemset.php?page={page}")
    #解析响应
    rs=html.fromstring(response.text)
    url=rs.xpath("//a[@class='problem-title']/@href")
    for u in url:
        print(u)
        problem_list_url.append(BASE_URL+u)
        print(f"解析成功第{len(problem_list_url)}条url地址：{BASE_URL+u}")
    page+=1
dicts=[]
#访问所有问题url获取题目信息
for problem in problem_list_url:
    response=requests.get(problem)
    #解析响应数据
    rs=html.fromstring(response.text)
    #id+标题
    title=rs.xpath("//h1[@class='ui header']/text()")
    if title:
        title=title[0].strip()
        print(f"题目:{title}")
        match=re.match(r"(\d+):(.*)",title)
        if match:
            pid=match.group(1)
            pname=match.group(2).strip()
        print(f"解析到题目id:{pid}|题目名字:{pname}")
    #题目描述
    descr=rs.xpath("//*[@id='main_container']/div[2]/div[2]/div/div/text()")
    print(descr)
    #拼接题目
    pdescr=""
    for p in descr:
        pdescr+=p.strip()
    pdescr = pdescr.replace('\xa0', ' ')
    print(f"题目描述：{pdescr}")
    #输入格式
    scanf=rs.xpath("//*[@id='main_container']/div[2]/div[3]/div/div/text()")
    print(scanf)
    pscanf=""
    for p in scanf:
        pscanf+=p.strip()
    print(f"输入格式：{pscanf}")
    #输出格式
    printf=rs.xpath("//*[@id='main_container']/div[2]/div[4]/div/div/text()")
    print(printf)
    pprintf=""
    for p in printf:
        pprintf+=p.strip()
    print(f"输出格式：{pprintf}")
    #输入样例
    input_sample=rs.xpath("//*[@id='main_container']/div[2]/div[5]/div/div/pre/code/text()")
    print(input_sample)
    pinput_sample=""
    for p in input_sample:
        pinput_sample+=p.strip()
        print(f"输入样例：{pinput_sample}")
    #输出样例
    output_sample=rs.xpath("//*[@id='main_container']/div[2]/div[6]/div/div/pre/code/text()")
    poutput_sample=""
    print(output_sample)
    for p in output_sample:
        poutput_sample+=p.strip()
        print(f"输出样例：{poutput_sample}")
    #保存到湖南工程学院OJ题目.csv
    dict={"题目id":pid,"题目名字":pname,"题目描述":pdescr,"输入格式":pscanf,"输出格式":pprintf,"输入样例":pinput_sample,"输出样例":poutput_sample}
    dicts.append(dict)
with open("湖南工程学院OJ题目.csv","a",encoding="utf-8",newline="") as f:
    writer=csv.DictWriter(f,fieldnames=["题目id","题目名字","题目描述","输入格式","输出格式","输入样例","输出样例"])
    writer.writerows(dicts)
    print("保存成功")