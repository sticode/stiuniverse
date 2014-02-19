#Sti universe post-build script
#Copying all dependency dll, except StiGame.dll
# StiGame.dll is copied by engine_copy.py

import shutil
import os
import sys

def copySDLdll(dest):

    if not os.path.exists(dest):
        os.makedirs(dest)

    files = os.listdir("../bin")
    fcount = 0
    for f in files:
        if f.endswith("dll"):
            src = os.path.join("../bin", f)
            dst = os.path.join(dest, f)
            if os.path.exists(dst):
                print "File : " + f + " already exists... skipping"
            else:
                print src + " -> " + dst
                shutil.copyfile(src, dst)
                fcount = fcount + 1
    print str(fcount) + " file(s) copied"

if __name__ == '__main__':
    print "Executables dependency dlls (Win32)"

    mode = 'release'
    #debug or release
    binfolder = "bin"
    dest = ''

    if len(sys.argv) >= 2:
        mode = sys.argv[1].lower()

    print "Current Configuration : " + mode

    if mode == 'release':
        dest = os.path.join(binfolder, "Release")
    elif mode == 'debug':
        dest = os.path.join(binfolder, "Debug")
    else:
        print "INVALID CONFIGURATION -> " + mode
        exit()

    print "Destination folder : " + dest

    copySDLdll(dest)
    
