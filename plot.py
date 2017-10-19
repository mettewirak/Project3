import matplotlib.pyplot as plt
import matplotlib.axis

def leser(filename):
	with open(filename) as f:
	    lines = f.readlines()
	    x = [line.split()[1] for line in lines]
	    y = [line.split()[3] for line in lines]
	    vx = [line.split()[5] for line in lines]
	    vy= [line.split()[7] for line in lines]

	return x,y,vx,vy


filename="\...\build-project3-test-Desktop_Qt_5_9_1_MinGW_32bit-Debug\Resultater.txt"

x,y,vx,vy=leser(filename)

plt.plot(x,y, 'r')
plt.plot(vx,vy, 'b')
plt.show()

