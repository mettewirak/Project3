import matplotlib.pyplot as plt
import matplotlib.axis
import numpy as np


def leser(filename):
	#Leser en fil og legger det til posisjon og hastighet. 
	with open(filename) as f:
	    lines = f.readlines()
	    planet=[line.split()[1] for line in lines]
	    x = [line.split()[3] for line in lines]
	    y = [line.split()[5] for line in lines]
	    vx = [line.split()[7] for line in lines]
	    vy= [line.split()[9] for line in lines]

	return planet,x,y,vx,vy

def sortere_planeter(planet,x,y,vx,vy):
	#Her sorteres verdiene etter hvilket objekt de tilhører. Og retunerer en array for hvert objekt. 
	n=len(planet)
	m=int(n/2) #Sett inn antall planeter
	i=0;me=0; v=0; k=0; ma=0; j=0; s=0; u=0;N=0; p=0;S=0
	Sun_x=np.zeros(m);Sun_y=np.zeros(m);Sun_vx=np.zeros(m);Sun_vy=np.zeros(m)  
	Me_x=np.zeros(m);Me_y=np.zeros(m);Me_vx=np.zeros(m);Me_vy=np.zeros(m)
	V_x=np.zeros(m);V_y=np.zeros(m);V_vx=np.zeros(m);V_vy=np.zeros(m)
	E_x=np.zeros(m);E_y=np.zeros(m);E_vx=np.zeros(m);E_vy=np.zeros(m)
	Ma_x=np.zeros(m);Ma_y=np.zeros(m);Ma_vx=np.zeros(m);Ma_vy=np.zeros(m)
	J_x=np.zeros(m);J_y=np.zeros(m);J_vx=np.zeros(m);J_vy=np.zeros(m)

	S_x=np.zeros(m);S_y=np.zeros(m);S_vx=np.zeros(m);S_vy=np.zeros(m)
	U_x=np.zeros(m);U_y=np.zeros(m);U_vx=np.zeros(m);U_vy=np.zeros(m)
	N_x=np.zeros(m);N_y=np.zeros(m);N_vx=np.zeros(m);N_vy=np.zeros(m)
	P_x=np.zeros(m);P_y=np.zeros(m);P_vx=np.zeros(m);P_vy=np.zeros(m)
	#x1,y1,vx1,vy2=leser(jupiter)
	print n
	for i in range(n):

		if planet[i]=="Mercury":
			Me_x[me]=x[i]
			Me_y[me]=y[i]
			Me_vx[me]=vx[i]
			Me_vy[me]=vy[i]
			me+=1
		elif planet[i]=="Sun":
			Sun_x[v]=x[i]
			Sun_y[v]=y[i]
			Sun_vx[v]=vx[i]
			Sun_vy[v]=vy[i]
			S+=1
		elif planet[i]=="Venus":
			V_x[v]=x[i]
			V_y[v]=y[i]
			V_vx[v]=vx[i]
			V_vy[v]=vy[i]
			v+=1		
		elif planet[i]=="Earth":
			E_x[k]=x[i]
			E_y[k]=y[i]
			E_vx[k]=vx[i]
			E_vy[k]=vy[i]
			k+=1
		elif planet[i]=="Mars":
			Ma_x[ma]=x[i]
			Ma_y[ma]=y[i]
			Ma_vx[ma]=vx[i]
			Ma_vy[ma]=vy[i]
			ma+=1
		elif planet[i]=="Jupiter":
			J_x[j]=x[i]
			J_y[j]=y[i]
			J_vx[j]=vx[i]
			J_vy[j]=vy[i]
			j+=1
		elif planet[i]=="Saturn":
			S_x[s]=x[i]
			S_y[s]=y[i]
			S_vx[s]=vx[i]
			S_vy[s]=vy[i]
			s+=1
		elif planet[i]=="Uranus":
			U_x[u]=x[i]
			U_y[u]=y[i]
			U_vx[u]=vx[i]
			U_vy[u]=vy[i]
			u+=1
		elif planet[i]=="Neptune":
			N_x[N]=x[i]
			N_y[N]=y[i]
			N_vx[N]=vx[i]
			N_vy[N]=vy[i]
			N+=1
		elif planet[i]=="Pluto":
			P_x[p]=x[i]
			P_y[p]=y[i]
			P_vx[p]=vx[i]
			P_vy[p]=vy[i]
			p+=1
		else:
		 print "Planet mangler",i,planet[i]
		
	return Sun_x,Sun_y,Me_x,Me_y,V_x,V_y,E_x,E_y,Ma_x,Ma_y,J_x,J_y, S_x,S_y, U_x,U_y,N_x,N_y,P_x,P_y


filename="build-Arnlaug-Desktop-Debug/Resultater.txt"


#Sender resultatfilen inn i lese og sorterings funksjonene. 
planet,x,y,vx,vy=leser(filename)
Sun_x,Sun_y,Me_x,Me_y,V_x,V_y,E_x,E_y,Ma_x,Ma_y,J_x,J_y, S_x,S_y, U_x,U_y,N_x,N_y,P_x,P_y=sortere_planeter(planet,x,y,vx,vy)

#Her plottes alle planetene
plt.plot(Me_x,Me_y, label="Mercury")
plt.plot(Sun_x,Sun_y,'o')

plt.plot(V_x,V_y, label="Venus")
plt.plot(E_x,E_y, label="Earth")
plt.plot(Ma_x,Ma_y, label="Mars")
plt.plot(S_x,S_y, label="Saturn")
plt.plot(J_x,J_y, label="Jupiter")
plt.plot(U_x,U_y, label="Uranus")
plt.plot(N_x, N_y, label="Neptune")
plt.plot(P_x,P_y, label="Pluto")
plt.xlabel('x-position (AU)')
plt.ylabel('y-position (AU)')
plt.legend()
plt.savefig("All_planets")
plt.show()

"""
plt.xlabel('x-position (AU)')
plt.ylabel('y-position (AU)')
plt.savefig("The_sun")
plt.show()
"""



