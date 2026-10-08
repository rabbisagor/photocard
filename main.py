import datetime
import os

def main():
    print("==========================================")
    print(" Hello from GitHub Actions / Codespaces! ")
    print("==========================================")
    
    # বর্তমান তারিখ ও সময় প্রিন্ট
    now = datetime.datetime.now()
    print(f"রান হওয়ার সময়: {now.strftime('%Y-%m-%d %H:%M:%S')}")
    
    # পাইথন সংস্করণ যাচাই
    import sys
    print(f"পাইথন ভার্সন: {sys.version.split()[0]}")
    
    print("সফলভাবে কোডটি এক্সিকিউট হয়েছে!")

if __name__ == "__main__":
    main()
