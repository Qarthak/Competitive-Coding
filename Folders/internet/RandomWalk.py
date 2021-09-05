import random

def random_walk(n):
	x,y=0,0
	for i in range(n):
		dx,dy=random.choice([(0,1),(0,-1),(1,0),(-1,0)])
		x+=dx
		y+=dy
	return(abs(x)+abs(y))

check_size=10000

for i in range(100):
	for j in range(check_size):
		x=random_walk(i)
		if()
