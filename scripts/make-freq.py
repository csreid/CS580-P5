import numpy as np
import collections

with open('clear.txt') as f:
	text = f.read()

freqs = collections.Counter(text.replace('\n','')).items()

for freq in freqs:
	print(f'{freq[0]} {freq[1]}')
