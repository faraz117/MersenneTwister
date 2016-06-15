import matplotlib.pyplot as plt
with open("randomNumbers.txt") as f:
	data=f.read()
data= data.split('\n')

y=data 
x=[x for x in range (len(data) - 1)]

del y[-1]
y=map(long,y)

plt.plot(x,y,'ro')
#n,bins,patches=plt.hist(y,50,normed=1,facecolor='green	',alpha=0.75)

plt.ylabel('PRNG values')
plt.xlabel('Loop Count')
plt.grid(True)
plt.show()