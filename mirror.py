# coding:gbk
import numpy as np
import sys

mirror = np.zeros((10,10),dtype=int)

cond = []

for line in sys.stdin:
	if not line:
		break
	cond.append(line.replace('\n',''))

def GetMirrorCount(mirror):
	ret = 0
	n = len(mirror)
	for i in range(n):
		for j in range(n):
			if mirror[i][j]=='/' or mirror[i][j]=='\\':
				ret += 1
	return ret 
	
def Solver(mirror, cond):
	if len(cond)==0:
		return True
	if GetMirrorCount(mirror)>5:
		return False
	while len(cond)!=0:
		c = cond.pop(0)
		
print cond