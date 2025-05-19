import numpy as np
def activation(f):
    if f<1.5:
        return 0
    else:
        return 1
def neuron(x,w,b):
    r=np.dot(x,w)+b
    return activation(r)
def ORgate(x):
    w=np.array([1,1])
    b=0.5
    return neuron(x,w,b)
eg1=np.array([0,0])
eg2=np.array([0,1])
eg3=np.array([1,0])
eg4=np.array([1,1])
print("OR(0,0)",ORgate(eg1))
print("OR(0,1)",ORgate(eg2))
print("OR(1,0)",ORgate(eg3))
print("OR(1,1)",ORgate(eg4))
