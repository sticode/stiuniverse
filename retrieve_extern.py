#script to download library and dll needed for stiuniverse
#the purpose is to remove binary from git repository

import zipfile
import os
import urllib2
#hard coded url
url = 'https://docs.google.com/uc?id=0B_P5byse05MmUDRxajVFaXRQeE0&export=download'

def download(url):

    req = urllib2.Request(url)

    resp = urllib2.urlopen(req)

    output = 'stiuniverse_extern.zip'

    fp = open(output, 'wb')

    buf_size = 16384
    
    length = resp.info().getheaders('Content-Length')[0]
    length = int(length)
    current = 0
    print "Starting download"
    chunk = resp.read(buf_size)
    last_prc = None
    i = 0
    while len(chunk) == buf_size:
        current = current + len(chunk)
        prc = (current*100) / length

        if not prc == last_prc:
            prefix = ""
            nb = i / 5
            for x in range(nb):
                prefix = prefix + "="
            i = i + 1
            
            print prefix + "> " + str(prc) + "%"
            last_prc = prc

        fp.write(chunk)

        chunk = resp.read(buf_size)

    fp.write(chunk)
    
    fp.close()
    
    print "Download complete !"
    return output

def extract(zipname):

    zp = zipfile.ZipFile(zipname, 'r')

    names = zp.namelist()

    for n in names:
        if not n.endswith('/'):
            cdir = os.path.dirname(n)
            if not os.path.exists(cdir):
                os.makedirs(cdir)
            print "Extracting : " + n
            zp.extract(n)

    zp.close()

if __name__ == '__main__':
    output = download(url)
    extract(output)
