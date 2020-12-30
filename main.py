import os
import urllib
import base64
import requests
import time

path = "C:\\Users\\hahahahaha\\Documents\\Code\\hdu_auto_ac1\\srccode"  # 文件夹目录
files = os.listdir(path)

codepath = []

src = {}

for root, dirs, files in os.walk(path):
    for file in files:
        if os.path.join(root, file).find("cpp") != -1:
            codepath.append(os.path.join(root, file))

for i in codepath:
    f = open(i, mode='r', encoding='UTF-8')
    code = f.read()
    p = os.path.split(i)
    p1 = os.path.split(p[0])
    code = urllib.parse.quote(code)
    code = bytes(code, encoding="utf8")
    code = base64.b64encode(code)
    src[p1[1]] = str(code, encoding="utf-8")

url = "http://acm.hdu.edu.cn/submit.php?action=submit"

headers = {
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9',
    'accept-encoding': 'gzip, deflate',
    'accept-language': 'zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6',
    'cache-control': 'max-age=0',
    'content-type': 'application/x-www-form-urlencoded',
    'cookie': 'PHPSESSID=xxxxxxxxxxxxxxx; exesubmitlang=0',
    'host': 'acm.hdu.edu.cn',
    'origin': 'http://acm.hdu.edu.cn',
    'proxy-connection': 'keep-alive',
    'referer': 'http://acm.hdu.edu.cn/submit.php?action=submit',
    'upgrade-insecure-requests': '1',
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/87.0.4280.88 Safari/537.36 Edg/87.0.664.66'
}

for k in src:
    payload = "check=0&_usercode=" + \
        urllib.parse.quote(src[k])+"&problemid="+k+"&language=0"

    response = requests.request("POST", url, headers=headers, data=payload)
    time.sleep(10)
