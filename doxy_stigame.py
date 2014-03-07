
import os

if __name__ == '__main__':

    files = os.listdir('StiGame')
    lines = []
    lines.append("Doxy Blocks TO DO\n")
    lines.append("-------------------------------------\n")
    for f in files:

        if f.endswith('.h'):
            lines.append(f + "\n")

    fp = open("doxy_todo.txt", 'w')
    fp.writelines(lines)
    fp.close()
