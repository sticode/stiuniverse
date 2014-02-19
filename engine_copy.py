#Sti game post-build script
#Copy StiGame.dll into stiuniverse bin\mode directory
import shutil
import os
import sys


def copystigame(src, dst):

    if not os.path.exists(dst):
        os.makedirs(dst)

    src = os.path.join(src, "StiGame.dll")
    dst = os.path.join(dst, "StiGame.dll")

    print src + " -> " + dst
    shutil.copyfile(src, dst)
    

if __name__ == '__main__':
    print "StiGame engine post-build"

    mode = 'release'
    dest = ''
    dest2 = ''
    source = ''
    
    if len(sys.argv) >= 2:
        mode = sys.argv[1].lower()

    if mode == 'release':
        source = os.path.join("bin", "Release")
        dest = os.path.join(".." ,"stiuniverse", "bin", "Release")
        dest2 = os.path.join(".." ,"assettools", "bin", "Release")
    elif mode == 'debug':
        source = os.path.join("bin", "Debug")
        dest = os.path.join(".." ,"stiuniverse", "bin", "Debug")
        dest2 = os.path.join(".." ,"assettools", "bin", "Debug")
    else:
        print "UNKNOWN CONFIGURATION -> " + mode
        exit()

    print "Mode : " + mode
    
    copystigame(source, dest)
    copystigame(source, dest2)

