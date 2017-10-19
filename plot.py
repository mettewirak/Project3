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


filename="build-Arnlaug-Desktop-Debug/Earth.txt"
jupiter="build-Arnlaug-Desktop-Debug/Jupiter.txt"

x,y,vx,vy=leser(filename)
x1,y1,vx1,vy2=leser(jupiter)

plt.plot(x,y, 'r')
plt.plot(x1,y1, 'b')
plt.show()

