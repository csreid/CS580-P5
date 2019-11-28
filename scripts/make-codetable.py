import sys
from huffman import codebook

if len(sys.argv) < 2:
	print('Give an input file')
	exit()

filename = sys.argv[1]

freqs = []
with open(filename, 'r') as f:
	for line in f:
		freq = tuple(line.split(' '))
		freq = (freq[0], freq[1].strip())
		freqs.append(freq)

ct = codebook(freqs)
for f in ct:
	print(f'{f}: {ct[f]}')
