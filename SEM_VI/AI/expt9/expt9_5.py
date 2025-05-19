import numpy as np
def activation(f):
    if f<=0.5:
        return 1
    else:
        return 0
def neuron(x,w,b):
    r=np.dot(x,w)+b
    return activation(r)

def NOTgate(x):
    w=np.array([1])
    b=0.5
    return neuron(x,w,b)
eg1=np.array([0])
eg2=np.array([1])
print("NOT(0)",NOTgate(eg1))
print("NOT(1)",NOTgate(eg2))
