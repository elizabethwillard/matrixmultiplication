# !/usr/bin/python
import subprocess
subprocess.call(["./mmult 3 3 3 3"], shell=True)

subprocess.call(["./mmult 1000 1000 10"], shell = True)

subprocess.call(["./mmult 3 3 3"], shell = True)

subprocess.call(["./mmult 3 3 3 3 3"], shell = True)

subprocess.call(["./mmult cat 3 3 3"], shell = True)

subprocess.call(["./mmult 1000 1000 1000 1000"], shell = True)




