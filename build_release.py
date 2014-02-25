import make
import os
import shutil
import packer
import sys

info = make.cpp_info()
info.set_env()

if not os.path.exists("deploy"):
    os.mkdir("deploy")

build_num = "0"
output_zip =  'stiuniverse.zip'
if len(sys.argv) > 1:
    build_num = sys.argv[1]
    output_zip =  'stiuniverse-'+build_num+'.zip'

#building stigame
info.includes.append("..\\include\\SDL2")
info.build_num = build_num
info.links.append("SDL2main")
info.links.append("SDL2")
info.links.append("SDL2_image")
info.links.append("SDL2_ttf")
info.links.append("SDL2_gfx")
info.link_args.append("-shared")
info.link_args.append("-Wl,--output-def=bin\Release\libStiGame.def")
info.link_args.append("-Wl,--out-implib=bin\Release\libStiGame.a")
info.link_args.append("-Wl,--dll")
info.link_args.append("-L..\\lib\\")
info.objs_prefix.append("-std=c++11")
info.objs_prefix.append("-Wall")
#info.objs_prefix.append("-g")
#info.objs_prefix.append("-DDEBUG")
info.objs_prefix.append("-O2")
info.objs_prefix.append("-DRELEASE")


bp = make.build_project("stigame", info, "Release")
bp.output = "..\\deploy\\StiGame.dll"
bp.scan_files()
bp.build_objects()
bp.link()


#building assettools
info = make.cpp_info()
info.build_num = build_num
info.includes.append("..\\include\\SDL2")
info.includes.append("..\\stigame")
info.links.append("mingw32")
info.links.append("SDL2main")
info.links.append("SDL2")
info.links.append("SDL2_image")
info.links.append("SDL2_ttf")
info.links.append("SDL2_gfx")
info.links.append("StiGame")
#info.link_args.append("-shared")
#info.link_args.append("-Wl,--output-def=bin\Debug\libStiGame.def")
#info.link_args.append("-Wl,--out-implib=bin\Debug\libStiGame.a")
#info.link_args.append("-Wl,--dll")
info.link_args.append("-s")
info.link_args.append("-L..\\lib\\")
info.link_args.append("-L..\\stigame\\bin\\Release\\")
info.objs_prefix.append("-std=c++11")
info.objs_prefix.append("-Wall")
#info.objs_prefix.append("-g")
#info.objs_prefix.append("-DDEBUG")
info.objs_prefix.append("-O2")
info.objs_prefix.append("-DRELEASE")


bp = make.build_project("assettools", info, "Release")
bp.output = "..\\deploy\\assettools.exe"
bp.scan_files()
bp.build_objects()
bp.link()

#building stiuniverse
info = make.cpp_info()
info.build_num = build_num
info.includes.append("..\\include\\SDL2")
info.includes.append("..\\stigame")
info.links.append("mingw32")
info.links.append("SDL2main")
info.links.append("SDL2")
info.links.append("SDL2_image")
info.links.append("SDL2_ttf")
info.links.append("SDL2_gfx")
info.links.append("StiGame")
#info.link_args.append("-shared")
#info.link_args.append("-Wl,--output-def=bin\Debug\libStiGame.def")
#info.link_args.append("-Wl,--out-implib=bin\Debug\libStiGame.a")
#info.link_args.append("-Wl,--dll")
info.link_args.append("-s")
info.link_args.append("-L..\\lib\\")
info.link_args.append("-L..\\stigame\\bin\\Release\\")
info.objs_prefix.append("-std=c++11")
info.objs_prefix.append("-Wall")
#info.objs_prefix.append("-g")
#info.objs_prefix.append("-DDEBUG")
info.objs_prefix.append("-O2")
info.objs_prefix.append("-DRELEASE")

bp = make.build_project("stiuniverse", info, "Release")
bp.output = "..\\deploy\\StiUniverse.exe"
bp.scan_files()
bp.build_objects()
bp.link()

#dlls dependency
dc = make.dll_copy()
dc.copy()

#assets copying
ac = make.assets_copy( 'assets', os.path.join('deploy', 'assets') )
ac.copy()

#assets building
sprites = ['a0', 'a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7', 'd0', 'd1']
dsprites = ['vessel0']

os.chdir('deploy')

for s in sprites:
    cmd = ['assettools', 'sprite', s]
    se = make.subexec(cmd)
    se.run()

    shutil.rmtree(os.path.join("assets","sprites", s))
    os.remove(os.path.join("assets", "sprites", s + ".spr"))
    
for ds in dsprites:
    cmd = ['assettools', 'dsprite', ds]
    se = make.subexec(cmd)
    se.run()

    shutil.rmtree(os.path.join("assets","sprites", ds))
    os.remove(os.path.join("assets", "sprites", ds + ".dspr"))

os.chdir('..')

#cleaning folder

shutil.rmtree(os.path.join("stigame", "bin"))
shutil.rmtree(os.path.join("stigame", "obj"))
shutil.rmtree(os.path.join("stiuniverse", "bin"))
shutil.rmtree(os.path.join("stiuniverse", "obj"))
shutil.rmtree(os.path.join("assettools", "bin"))
shutil.rmtree(os.path.join("assettools", "obj"))


pack = packer.packer('deploy', output_zip)
pack.pack()

print "Build endend !"

