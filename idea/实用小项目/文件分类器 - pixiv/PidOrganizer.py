import os
import requests
import json
import time
import signal
import sys
import io
import locale

# 强制UTF-8环境
sys.stdin = io.TextIOWrapper(sys.stdin.buffer, encoding='utf-8')
sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')
sys.stderr = io.TextIOWrapper(sys.stderr.buffer, encoding='utf-8')
locale.setlocale(locale.LC_ALL, 'en_US.UTF-8')

# 配置
INPUT_FOLDER = "PATH"  # 填入你的文件路径
COOKIES = {"PHPSESSID": "XXXXXXXX"} # 填入你的cookie
DELAY = 2  # 请求间隔(秒)

def block_interrupt():
    signal.signal(signal.SIGINT, signal.SIG_IGN)

def allow_interrupt():
    signal.signal(signal.SIGINT, signal.SIG_DFL)

def get_uid_from_pid(pid):
    """增强版UID获取函数"""
    url = f"https://www.pixiv.net/ajax/illust/{pid}"
    headers = {
        "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64)",
        "Referer": "https://www.pixiv.net/",
        "Accept-Encoding": "gzip"
    }
    
    try:
        response = requests.get(url, headers=headers, cookies=COOKIES, timeout=15)
        if response.status_code != 200:
            return None
            
        data = response.json()
        return str(data["body"]["userId"])
    except Exception as e:
        print(f"| API Error | PID:{pid} | {str(e)[:50]}...")
        return None

def organize_files():
    """安全版文件整理"""
    stats = {"success":0, "deleted":0, "private":0, "failed":0}
    
    for filename in os.listdir(INPUT_FOLDER):
        try:
            pid = filename.split('_')[0]
            if not pid.isdigit():
                continue
                
            uid = get_uid_from_pid(pid)
            time.sleep(DELAY)
            
            if not uid:
                stats["failed"] += 1
                continue
                
            target_dir = os.path.join(INPUT_FOLDER, uid)
            os.makedirs(target_dir, exist_ok=True)
            
            src = os.path.join(INPUT_FOLDER, filename)
            dst = os.path.join(target_dir, filename)
            
            block_interrupt()
            os.rename(src, dst)
            allow_interrupt()
            
            stats["success"] += 1
            print(f"✓ {filename} → {uid}/")
            
        except Exception as e:
            print(f"✗ {filename} | {type(e).__name__}:{str(e)}")
            stats["failed"] += 1
            
    print(f"\n统计: 成功 {stats['success']} | 失败 {stats['failed']}")

if __name__ == "__main__":
    organize_files()