from pathlib import Path

import random
import subprocess
from math import log

from _gen import runTest
from _gen.generator  import Generator, genStart
from _gen.present  import Entry, List, SpaceContainer, LineContainer

GENDIR = Path(__file__).resolve().parent

class TestGenerator(Generator):
        def presentTest(self):
                return List(
                        [
                                List(
                                        [Entry(end=' '),Entry(end=' '),Entry(end='\n')]
                                ),
                                List(
                                        [Entry(end=' '),Entry(end='\n')]
                                ),
                                List(
                                        [Entry(end=' '),Entry(end='\n')]
                                ),
                        ]
                )

        def presentAns(self):
                return Entry(end='\n')

        def nativeSolve(self, file):
                solver = str(GENDIR / 'sol_debug.exe')
                proc = subprocess.run([solver], stdin=file, stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True)
                ans = proc.stdout.decode().strip()

                if proc.stderr:
                        print('[solver]: {}'.format(proc.stderr.decode()))

                return ans

        def postProcess(self, test):
                return

        def newTest(self, *args, **kwargs):
                super().newTest(*args, **kwargs, native_solve=True)

MAXN = 1000000000000000000
MAXP = 10000
MINV = -1000000000
MAXV = 1000000000

def genAll(genfunc):
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(abs(a) <= MAXV)
                assert(abs(b) <= MAXV)
                assert(abs(c) <= MAXV)
                assert(abs(a_0) <= MAXV)
                assert(abs(a_1) <= MAXV)
                assert(1 <= n and n <= MAXN)
                assert(1 <= p and p <= MAXP)

                return [[a, b, c], [a_0, a_1], [n, p]]

        return wrapfunc

############################## Gen 0 ##############################

def gen0(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen0
def gen0A():
        return [1, 5, -1, 0, -1, 9, 21]

@gen0
def gen0B():
        return [3, -3, 5, 6, 6, 10, 72]

@gen0
def gen0C():
        return [-3, -5, 2, 9, 9, 4, 35]

@gen0
def gen0D():
        a = random.randint(-3, 3)
        b = random.randint(-5, 5)
        c = random.randint(-7, 7)
        a_0 = random.randint(-9, 9)
        a_1 = random.randint(-11, 11)
        n = random.randint(3, 10)
        p = random.randint(10, 100)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 1 ##############################

def gen1(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(n <= 1000000)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen1
def gen1A():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, 1000000)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen1
def gen1B():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(950000, 1000000)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 2 ##############################

def gen2(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(a == 0)
                assert(c == 0)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen2
def gen2A():
        a = 0
        b = random.randint(MINV, MAXV)
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen2
def gen2B():
        a = 0
        b = random.randint(MINV, MAXV)
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 3 ##############################

def gen3(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(a == 0)
                assert(b == 0)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen3
def gen3A():
        a = 0
        b = 0
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen3
def gen3B():
        a = 0
        b = 0
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 4 ##############################

def gen4(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(a == 0)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen4
def gen4A():
        a = 0
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen4
def gen4B():
        a = 0
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 5 ##############################

def gen5(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(a == 1)
                assert(b == 0)
                assert(c == 0)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen5
def gen5A():
        a = 1
        b = 0
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen5
def gen5B():
        a = 1
        b = 0
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

primeA, primeB, primeC, primeD = 499, 599, 997, 9733

@gen5
def gen5C():
        mtp = random.randint(1, min(MAXP // primeA, MAXV // primeD))
        p = mtp * primeA
        ep = euler(p)
        a = 1
        b = 0
        c = 0
        a_0 = mtp * primeC
        a_1 = mtp * primeD
        n = random.randint(1, ep - 1)
        return [a, b, c, a_0, a_1, n, p]

@gen5
def gen5D():
        mtp = random.randint(1, min(MAXP // primeA, MAXV // primeD))
        p = mtp * primeA
        ep = euler(p)
        a = 1
        b = 0
        c = 0
        a_0 = mtp * primeB
        a_1 = mtp * primeD
        n = random.randint(int(.95 * MAXN), MAXN)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 6 ##############################

def gen6(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(b == 0)
                assert(c == 0)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen6
def gen6A():
        a = random.randint(MINV, MAXV)
        b = 0
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen6
def gen6B():
        a = random.randint(MINV, MAXV)
        b = 0
        c = 0
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

def euler(x):
        ans, i = x, 2
        while i * i <= x:
                if x % i == 0:
                        ans = ans // i * (i - 1)
                        while x % i == 0:
                                x //= i
                i += 1
        if x != 1:
                ans = ans / x * (x - 1)
        return ans

primeA, primeB, primeC, primeD = 89, 97, 101, 103

@gen6
def gen6C():
        mtp = random.randint(1, min(MAXP // primeA, MAXV // primeD))
        p = mtp * primeA
        ep = euler(p)
        a = mtp * primeB
        b = 0
        c = 0
        a_0 = mtp * primeC
        a_1 = mtp * primeD

        n = random.randint(1, ep - 1)
        return [a, b, c, a_0, a_1, n, p]

@gen6
def gen6D():
        mtp = random.randint(1, min(MAXP // primeA, MAXV // primeD))
        p = mtp * primeA
        ep = euler(p)
        a = mtp * primeB
        b = 0
        c = 0
        a_0 = mtp * primeC
        a_1 = mtp * primeD
        n = random.randint(int(.95 * MAXN), MAXN)
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 7 ##############################

def gen7(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)
                assert(p == 2)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen7
def gen7A():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = 2
        return [a, b, c, a_0, a_1, n, p]

@gen7
def gen7B():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = 2
        return [a, b, c, a_0, a_1, n, p]

stateSet = [127, 124, 123, 121, 120, 119, 117, 111, 110, 109, 103, 102, 101, 100, 96, 93, 90, 89, 87, 86, 85, 68, 64, 62, 60, 59, 58, 56, 55, 54, 53]
@gen7
def gen7C():
        state = stateSet[random.randint(0, len(stateSet) - 1)]

        n = random.randint(int(.95 * MAXN) // 2, MAXN // 2) * 2 + (state & 3) + 1
        state >>= 2
        a = random.randint(MINV // 2, MAXV // 2) * 2 + (state & 1)
        state >>= 1
        b = random.randint(MINV // 2, MAXV // 2) * 2 + (state & 1)
        state >>= 1
        c = random.randint(MINV // 2, MAXV // 2) * 2 + (state & 1)
        state >>= 1
        a_0 = random.randint(MINV // 2, MAXV // 2) * 2 + (state & 1)
        state >>= 1
        a_1 = random.randint(MINV // 2, MAXV // 2) * 2 + (state & 1)
        state >>= 1

        p = 2
        return [a, b, c, a_0, a_1, n, p]

############################## Gen 8 ##############################

def gen8(genfunc):
        @genAll
        def wrapfunc(**kwargs):
                [a, b, c, a_0, a_1, n, p] = genfunc(**kwargs)

                return [a, b, c, a_0, a_1, n, p]

        return wrapfunc

@gen8
def gen8A():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(1, MAXN)
        p = random.randint(1, MAXP)
        return [a, b, c, a_0, a_1, n, p]

@gen8
def gen8B():
        a = random.randint(MINV, MAXV)
        b = random.randint(MINV, MAXV)
        c = random.randint(MINV, MAXV)
        a_0 = random.randint(MINV, MAXV)
        a_1 = random.randint(MINV, MAXV)
        n = random.randint(int(.95 * MAXN), MAXN)
        p = random.randint(3, MAXP)
        return [a, b, c, a_0, a_1, n, p]

###################################################################

def main():
        random.seed(20210830 ** 1259)
        test_format = str(GENDIR.resolve() / 'manual' / '{subtask}-{testid:0>2}.{ext}')

        gen = TestGenerator()
        gen.config(debug=False, test_format=test_format)


        gen.newTest(0, 1, gen0A)
        gen.newTest(0, 1, gen0B)
        gen.newTest(0, 1, gen0C)
        # gen.newTest(0, 10, gen0D)

        gen.newTest(1, 2, gen1A)
        gen.newTest(1, 3, gen1B)

        gen.newTest(2, 2, gen2A)
        gen.newTest(2, 3, gen2B)

        gen.newTest(3, 2, gen3A)
        gen.newTest(3, 3, gen3B)

        gen.newTest(4, 2, gen4A)
        gen.newTest(4, 3, gen4B)

        gen.newTest(5, 2, gen5A)
        gen.newTest(5, 1, gen5B)
        gen.newTest(5, 3, gen5C)
        gen.newTest(5, 3, gen5D)

        gen.newTest(6, 2, gen6A)
        gen.newTest(6, 1, gen6B)
        gen.newTest(6, 3, gen6C)
        gen.newTest(6, 3, gen6D)

        gen.newTest(7, 2, gen7A)
        gen.newTest(7, 1, gen7B)
        gen.newTest(7, 10, gen7C)

        gen.newTest(8, 2, gen8A)
        gen.newTest(8, 3, gen8B)

        runTest.config(test_dir=str(GENDIR.resolve() / 'manual'))
        with open('data', 'w') as gendata:
                caseMap = {}
                for cprefix, cin, cout in runTest.getCases():
                        inpath = Path(cin).name
                        subtask, *_ = inpath.split('-')
                        if not subtask in caseMap:
                                caseMap[subtask] = []

                        caseMap[subtask].append(str(inpath))

                print(caseMap)
                for subtask in caseMap:
                        gendata.write('@subtask {}\n'.format('samples' if subtask == '0' else subtask))
                        for inpath in caseMap[subtask]:
                                gendata.write('manual {}\n'.format(inpath))

                        gendata.write('\n')

if __name__ == "__main__":
        genStart(main)
