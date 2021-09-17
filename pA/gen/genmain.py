#!/usr/bin/env python3

from pathlib  import Path
import random
import subprocess

from _gen  import runTest
from _gen.generator  import Generator, genStart
from _gen.present  import Entry, List, SpaceContainer, LineContainer

from genstruct  import randomInserted, randomSegments, genHills

class TestGenerator(Generator):
	pass

def genMain():
	return

if __name__ == "__main__":
	genStart(genMain)