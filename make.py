import os
import subprocess
import sys
import shutil
import datetime

class build_log:

    def __init__(self, bname, output):
        self.name = bname
        self.output = output
        self.header = '<html><head><title>'+self.name+' Build log</title><link rel="stylesheet" href="log.css" type="text/css" /></head><body><h2>'+self.name+'</h2>';
        self.datet = datetime.datetime.now()
        self.datestr = str(self.datet.day)+"-"+str(self.datet.month)+"-"+str(self.datet.year)+" "+str(self.datet.hour)+":"+str(self.datet.minute)
        self.content = ""
        self.footer = '<div class="footer">Build log : ' + self.datestr + '</div></body></html>'

    def add_obj(self, obj):
        self.content += '<div class="addobj">Adding Object : '+obj+'</div>'

    def end_proj(self, success = True):
        if success:
            self.content += '<div class="project_end">Project compiled !</div>'
        else:
            self.content += '<div class="project_error">Project building failed !</div>'

    def build_obj(self, cmd):
        self.content += '<div class="build_obj">'+cmd+'</div>'

    def std_err(self, err):
        self.content += '<div class="std_err">'+err+'</div>'

    def link_proj(self, cmd):
        self.content += '<div class="linking">'+cmd+'</div>'


    def save(self):
        fp = open(self.output, 'w')
        self.content = self.header + self.content + self.footer
        fp.write(self.content)
        fp.close()
        
class subexec:

    def __init__(self, args):
        self.args = args

    def run(self):
        p = subprocess.Popen(self.args , stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)

        line = p.stdout.readline()

        while len(line) > 0:
            print line
            line = p.stdout.readline()

        line = p.stderr.readline()

        while len(line) > 0:
            print line
            line = p.stderr.readline()
        
class dll_copy:
    def __init__(self):
        self.dlldir = "bin"
        self.deploy = "deploy"
    def copy(self):
        dlls = os.listdir(self.dlldir)
        for d in dlls:
            print "Copying : "+d
            if d.endswith(".dll"):
                shutil.copy(os.path.join(self.dlldir, d), os.path.join(self.deploy, d))
    

class assets_copy:

    def __init__(self, src, dst):
        self.src = src
        self.dst = dst

    def copy(self):
        files = os.listdir(self.src)

        if not os.path.exists(self.dst):
            os.makedirs(self.dst)

        for f in files:
            if os.path.isfile(os.path.join(self.src, f)):
                dst = os.path.join(self.dst, f)
                src = os.path.join(self.src, f)
                if not self.ignore_file(f):
                    print src + " -> " + dst
                    shutil.copy(src, dst)
                
            elif os.path.isdir(os.path.join(self.src, f)):
                self.copydir(f)

    def copydir(self, dname):

        files = os.listdir(os.path.join(self.src, dname))
        dstdir = os.path.join(self.dst, dname)

        if not os.path.exists(dstdir):
            os.makedirs(dstdir)
        
        for f in files:
            fpath = os.path.join(self.src, dname, f)
            if os.path.isfile(fpath):
                dst = os.path.join(dstdir, f)
                src = os.path.join(self.src, dname, f)
                if not self.ignore_file(f):
                    print src + " -> " + dst
                    shutil.copy(src, dst)
            elif os.path.isdir(fpath):
                self.copydir(os.path.join(dname, f))

    def ignore_file(self, fname):
        if fname.endswith('.bspr'):
            return True
        elif fname.endswith('.bdspr'):
            return True
        elif fname.endswith('.res'):
            return True
        return False
        

class cpp_info:

    def __init__(self):
        self.gpp = "i686-w64-mingw32-g++"
        self.gpp_path = 'C:\\cygwin64\\bin'
        self.includes = []
        self.links = []
        self.link_args = []
        self.objs_prefix = []
        self.build_num = "0"

    def set_env(self):
        os.environ["PATH"] += os.pathsep + self.gpp_path

class build_project:

    def __init__(self, projname, cppinfo, build = "Debug"):
        self.cppinfo = cppinfo
        self.projname = projname
        self.objs = []
        self.obj_dir = os.path.join("obj", build)
        self.bin_dir = os.path.join(projname, "bin", build)
        self.build = build
        self.bin_objs = []
        self.links = cppinfo.links
        self.output = ""
        self.objs_prefix = cppinfo.objs_prefix
        self.log = build_log(projname, projname+"-build-"+cppinfo.build_num+"-log.html")

        if not os.path.exists(os.path.join(projname, self.obj_dir)):
            os.makedirs(os.path.join(projname, self.obj_dir))
        if not os.path.exists(self.bin_dir):
            os.makedirs(self.bin_dir)

    def scan_files(self):

        files = os.listdir(self.projname)

        for f in files:
            if f.endswith('.cpp'):
                fname = f.split('.')[0]

                self.objs.append(fname)

                print "Adding object : " + fname
                
                self.log.add_obj(fname)

    def build_objects(self):
        build_failed = False
        os.chdir(self.projname)
        for o in self.objs:
            fout = os.path.join(self.obj_dir, o + ".o")
            fcpp = os.path.join(o + ".cpp")
            fcpp = os.path.abspath(fcpp)

            #building args
            args = []
            args.append(self.cppinfo.gpp)
            print "Building "+o+" with "+args[0]
            for a in self.objs_prefix:
                args.append(a)

            for i in self.cppinfo.includes:
                args.append("-I"+i)

            args.append("-c")
            args.append(fcpp)
            args.append("-o")
            args.append(fout)

            cmd = ""

            for a in args:
                cmd += a + " "
            print cmd
            self.log.build_obj(cmd)
            
            p = subprocess.Popen(args , stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)

            line = p.stdout.readline()

            while len(line) > 0:
                print line
                line = p.stdout.readline()

            errtxt = ""
            line = p.stderr.readline()

            while len(line) > 0:
                errtxt += line
                line = p.stderr.readline()

            if not errtxt.find("error:") == -1:
                build_failed = True
                self.log.std_err(errtxt)

            if build_failed:
                print "Build failed ! abort..."
                print errtxt
                self.log.end_proj(False)
                break;

            self.bin_objs.append(fout)

        os.chdir("..")

    def link(self):
        os.chdir(self.projname)
        #building args

        args = []
        args.append(self.cppinfo.gpp)

        for l in self.cppinfo.link_args:
            args.append(l)

        for o in self.bin_objs:
            args.append(o)

        args.append("-o")
        args.append(self.output)

        for l in self.cppinfo.links:
            args.append("-l"+l)

        cmd = ""

        for a in args:
            cmd += a + " "

        self.log.link_proj(cmd)
        print "Linking objects..."
        print cmd

        p = subprocess.Popen(args , stdout=subprocess.PIPE, stderr=subprocess.PIPE, shell=True)

        line = p.stdout.readline()

        while len(line) > 0:
            print line
            line = p.stdout.readline()

        errtxt = ""

        line = p.stderr.readline()

        while len(line) > 0:
            print line
            errtxt += line
            line = p.stderr.readline()

        if not errtxt.find("error:") == -1:
            print "Linking failed , abort"
            self.log.std_err(errtxt)
            self.log.end_proj(False)
            print errtxt
        else:
            self.log.end_proj()
            print "Build success !"

        os.chdir("..")

        self.log.save()
            
