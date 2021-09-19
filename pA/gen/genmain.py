#!/usr/bin/env python3

from functools  import reduce
from pathlib  import Path
import random
import subprocess

from _gen  import runTest
from _gen.generator  import Generator, genStart
from _gen.present  import Entry, List, SpaceContainer, LineContainer

class TestGenerator(Generator):
	def presentTest(self):
		return List([
			Entry(end='\n'),
			SpaceContainer(end='\n')
		])
	
	def presentAns(self):
		return Entry(end='\n')
	
	def nativeSolve(self, file):
		solution = './sol_debug.exe'
		# proc = subprocess.run([solution], stdin=file, capture_output=True, check=True)
		proc = subprocess.run([solution], stdin=file, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True)
		ans = proc.stdout.decode().strip()
		
		if proc.stderr:
			print('[sol_debug]: {}'.format(proc.stderr.decode()))
		
		return int(ans)
	
	def postProcess(self, test, checkfunc, **kwargs):
		checkfunc(test)
		return
	
	def newTest(self, *args, **kwargs):
		super().newTest(*args, **kwargs, native_solve=True)

def checkAll(test):
	n, w = test
	
	assert( 1 <= n <= 8000 )
	
	assert( len(w) == n )
	assert( all(1 <= wi <= 10**9)  for wi in w ) 

def checkSub1(test):
	n, w = test
	
	assert( n <= 20 )

def checkSub2(test):
	n, w = test
	
	assert( n <= 500 )

def checkSub3(test):	
	n, w = test
	
	assert( sum(w) <= 10**6 )

def checkSub4(test):
	n, w = test
	
	assert( n <= 800 )

def genSample1():
	return [
		5,
		[1, 2, 2, 1, 3]
	]

def genSample2():
	return [
		9,
		[8, 3, 3, 5, 2, 1, 5, 3, 3]
	]

def genSample3():
	return [
		5,
		[1, 2, 4, 8, 16]
	]

def genSample4():
	return [
		7,
		[999999999, 999999999, 999999999, 999999998, 999999997, 999999996, 6]
	]

def _randSplit(N, sz):
	pos = sorted([0, *random.sample(range(1, N), sz-1), N])
	return [pos[i+1]-pos[i]  for i in range(sz)]

def genRandom(nrange, wrange):
	n = random.randint(*nrange)
	w = [random.randint(*wrange)  for i in range(n)]
	
	return [n, w]

def genSplitNum(nmax, k, szrange):
	minsz, maxsz = szrange
	
	w = []
	while nmax-len(w) >= minsz:
		gsz = random.randint(minsz, min(nmax-len(w), maxsz))
		if gsz == 1:
			w.append(k)
		else:
			peak = random.randint(k//(2/1), k//(3/2))
			S = k - peak
			
			nw = [peak, *_randSplit(S, gsz-1)]
			random.shuffle(nw)
			w.extend(nw)
	
	return [len(w), w]

def genProd(seq):
	prod = reduce(lambda x, y: x*y, seq)
	
	w = []
	for x in seq:
		w.extend([prod//x]*x)
	
	return [len(w), w]

def genSumFixed(n, S, wrange):
	assert( n*wrange[0] <= S <= n*wrange[1] )
	
	w = [(S//n + (S%n > i))  for i in range(n)]
	random.shuffle(w)
	
	for i in range(n):
		j = random.randint(0, i)
		
		lws = max(wrange[0]-w[i], w[j]-wrange[1])
		ups = min(wrange[1]-w[i], w[j]-wrange[0])
		
		if lws <= ups:
			s = random.randint(lws, ups)
			w[i], w[j] = w[i]+s, w[j]-s
	
	return [len(w), w]

def _alldiv(N):
	v = []
	for i in range(1, N):
		if i*i > N:
			break
		elif i*i == N:
			v.append(i)
		elif N%i == 0:
			v.append(i)
			v.append(N//i)
	
	return sorted(v)

# 139675536000 	# (2*2*2*2) * (5*5) * (3*3) * (2*2) * 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19
# 2248776129600 # hcn100 = 2**6 * 3**3 * 5**2 * 7**2 * 11 * 13 * 17 * 19 * 23
# 735134400 	# hcn66 = 2**6 * 3**3 * 5**2 * 7 * 11 * 13 * 17

HCN66 = 735134400
DIV_HCN66 = _alldiv(HCN66)

def genHCN66Div(n):
	divs = sorted([0, *random.sample(DIV_HCN66[:1304], n-1)])
	w = [divs[i+1]-divs[i]  for i in range(n-1)]
	w.append(HCN66 - sum(divs))
	
	return [n, w]

def genMain():
	random.seed(20210918 ** 1657)
	
	test_format = str('manual/{subtask}-{testid:0>2}.{ext}')
	
	gen = TestGenerator()
	gen.config(debug=False, test_format=test_format)
	
	subtasks = ['samples', 'sub1', 'sub2', 'sub3', 'sub4', 'all']
	
	
	print('[genMain]: Gen #samples')
	gen.newTest('samples', 1, genSample1, opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('samples', 1, genSample2, opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('samples', 1, genSample3, opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('samples', 1, genSample4, opt_postProcess=dict(checkfunc=checkAll))
	
	
	print('[genMain]: Gen #sub1')
	gen.newTest('sub1', 2, genRandom, opt_gen=dict(nrange=(18, 20), wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub1))
	
	gen.newTest('sub1', 1, genSplitNum, opt_gen=dict(nmax=20, k=999855251, szrange=(9, 11)),
				opt_postProcess=dict(checkfunc=checkSub1))
	gen.newTest('sub1', 1, genSplitNum, opt_gen=dict(nmax=20, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub1))
	
	gen.newTest('sub1', 1, genProd, opt_gen=dict(seq=[2, 3, 5, 7]),
				opt_postProcess=dict(checkfunc=checkSub1))
	gen.newTest('sub1', 1, genProd, opt_gen=dict(seq=[7, 11]),
				opt_postProcess=dict(checkfunc=checkSub1))
	
	gen.newTest('sub1', 1, genSumFixed, opt_gen=dict(n=20, S=19999853947, wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub1))
	
	gen.newTest('sub1', 1, genHCN66Div, opt_gen=dict(n=20),
				opt_postProcess=dict(checkfunc=checkSub1))
	
	
	print('[genMain]: Gen #sub2')
	gen.newTest('sub2', 2, genRandom, opt_gen=dict(nrange=(400, 500), wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub2))
	
	gen.newTest('sub2', 1, genSplitNum, opt_gen=dict(nmax=500, k=999855251, szrange=(240, 260)),
				opt_postProcess=dict(checkfunc=checkSub2))
	gen.newTest('sub2', 1, genSplitNum, opt_gen=dict(nmax=500, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub2))
	gen.newTest('sub2', 1, genSplitNum, opt_gen=dict(nmax=360, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub2))
	
	gen.newTest('sub2', 1, genProd, opt_gen=dict(seq=[2, 3, 5, 7, 11, 13, 17, 19, 23]),
				opt_postProcess=dict(checkfunc=checkSub2))
	gen.newTest('sub2', 1, genProd, opt_gen=dict(seq=[151, 163, 157]),
				opt_postProcess=dict(checkfunc=checkSub2))
	
	gen.newTest('sub2', 1, genSumFixed, opt_gen=dict(n=500, S=499999850993, wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub2))
	
	gen.newTest('sub2', 1, genHCN66Div, opt_gen=dict(n=500),
				opt_postProcess=dict(checkfunc=checkSub2))
	
	
	print('[genMain]: Gen #sub3')
	gen.newTest('sub3', 1, genRandom, opt_gen=dict(nrange=(7000, 8000), wrange=(1, 100)),
				opt_postProcess=dict(checkfunc=checkSub3))
	
	gen.newTest('sub3', 2, genSumFixed, opt_gen=dict(n=7700, S=999067, wrange=(1, 10**6)),
				opt_postProcess=dict(checkfunc=checkSub3))
	gen.newTest('sub3', 2, genSumFixed, opt_gen=dict(n=7700, S=720720, wrange=(1, 10**6)),
				opt_postProcess=dict(checkfunc=checkSub3))
	
	gen.newTest('sub3', 1, genSplitNum, opt_gen=dict(nmax=5000, k=199, szrange=(5, 10)),
				opt_postProcess=dict(checkfunc=checkSub3))
	gen.newTest('sub3', 1, genSplitNum, opt_gen=dict(nmax=7560, k=131, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub3))
	
	gen.newTest('sub3', 1, genProd, opt_gen=dict(seq=[2, 3, 5, 7, 11, 13]),
				opt_postProcess=dict(checkfunc=checkSub3))
	gen.newTest('sub3', 1, genProd, opt_gen=dict(seq=[59, 67, 61]),
				opt_postProcess=dict(checkfunc=checkSub3))
	
	
	print('[genMain]: Gen #sub4')
	gen.newTest('sub4', 2, genRandom, opt_gen=dict(nrange=(700, 800), wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub4))
	
	gen.newTest('sub4', 1, genSplitNum, opt_gen=dict(nmax=800, k=999855251, szrange=(480, 520)),
				opt_postProcess=dict(checkfunc=checkSub4))
	gen.newTest('sub4', 1, genSplitNum, opt_gen=dict(nmax=800, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub4))
	gen.newTest('sub4', 1, genSplitNum, opt_gen=dict(nmax=360, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkSub4))
	gen.newTest('sub4', 1, genSplitNum, opt_gen=dict(nmax=800, k=1249999, szrange=(5, 10)),
				opt_postProcess=dict(checkfunc=checkSub4))
	
	gen.newTest('sub4', 1, genProd, opt_gen=dict(seq=[2, 3, 5, 7, 11, 13, 17, 19, 23]),
				opt_postProcess=dict(checkfunc=checkSub4))
	gen.newTest('sub4', 1, genProd, opt_gen=dict(seq=[251, 263, 257]),
				opt_postProcess=dict(checkfunc=checkSub4))
	
	gen.newTest('sub4', 1, genSumFixed, opt_gen=dict(n=800, S=799999924121, wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkSub4))
	
	gen.newTest('sub4', 1, genHCN66Div, opt_gen=dict(n=800),
				opt_postProcess=dict(checkfunc=checkSub4))
	
	
	print('[genMain]: Gen #all')
	gen.newTest('all', 3, genRandom, opt_gen=dict(nrange=(7000, 8000), wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkAll))
	
	gen.newTest('all', 1, genSplitNum, opt_gen=dict(nmax=8000, k=999855251, szrange=(4950, 5050)),
				opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('all', 1, genSplitNum, opt_gen=dict(nmax=8000, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('all', 1, genSplitNum, opt_gen=dict(nmax=7560, k=999855277, szrange=(1, 1)),
				opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('all', 1, genSplitNum, opt_gen=dict(nmax=8000, k=124991, szrange=(5, 10)),
				opt_postProcess=dict(checkfunc=checkAll))
	
	gen.newTest('all', 1, genProd, opt_gen=dict(seq=[2, 3, 5, 7, 11, 13, 17, 19, 23]),
				opt_postProcess=dict(checkfunc=checkAll))
	gen.newTest('all', 1, genProd, opt_gen=dict(seq=[2657, 2663, 2659]),
				opt_postProcess=dict(checkfunc=checkAll))
	
	gen.newTest('all', 1, genSumFixed, opt_gen=dict(n=8000, S=7999999997833, wrange=(1, 10**9)),
				opt_postProcess=dict(checkfunc=checkAll))
	
	gen.newTest('all', 1, genHCN66Div, opt_gen=dict(n=1300),
				opt_postProcess=dict(checkfunc=checkAll))
	
	
	runTest.config(test_dir='manual')
	with open('data', 'w') as gendata:
		caseMap = {}
		for cprefix, cin, cout in runTest.getCases():
			inpath = Path(cin).name
			subtask, *_ = inpath.split('-')
			if not subtask in caseMap:
				caseMap[subtask] = []
			
			caseMap[subtask].append(str(inpath))
		
		print(caseMap)
		for subtask in subtasks:
			assert( subtask in caseMap )
			
			gendata.write('@subtask {}\n'.format(subtask))
			for inpath in caseMap[subtask]:
				gendata.write('manual {}\n'.format(inpath))
			
			gendata.write('\n')

if __name__ == "__main__":
	genStart(genMain)