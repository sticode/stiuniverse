import os
import sys
#build assets




if __name__ == '__main__':

    sprites = ['a0', 'a1', 'a2', 'a3', 'a4', 'a5', 'a6', 'a7', 'd0', 'd1']
    dsprites = ['vessel0']
    mode = 'release'

    if len(sys.argv) > 1:
        mode = sys.argv[1]

    os.chdir('..')

    os.chdir('assettools')

    os.chdir('bin')

    if mode == 'debug':
        os.chdir('Debug')

    elif mode == 'release':
        os.chdir('Release')

    for s in sprites:

        cmd = "assettools sprite " + s
        os.system(cmd)

    for ds in dsprites:

        cmd = "assettools dsprite " + ds
        os.system(cmd)
	
	cmd = "assettools gui gui.var"
	os.system(cmd)
