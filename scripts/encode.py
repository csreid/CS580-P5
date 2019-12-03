codetable = {}

with open('./codetable.txt', 'r') as f:
	for line in f:
		c, code = line.split(' ')
		codetable[c] = code.strip()

with open('clear.txt', 'r') as f:
	clear = f.read()

with open('coded.txt', 'w') as f:
	for c in clear:
		f.write(f'{codetable[c]}')
