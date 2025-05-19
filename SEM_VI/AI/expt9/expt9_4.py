import numpy as np
def activation(f):
    if f<2.5:
        return 1
    else:
        return 0
def neuron(x,w,b):
    r=np.dot(x,w)+b
    return activation(r)
def NANDgate(x):
    w=np.array([1,1])
    b=0.5
    return neuron(x,w,b)
eg1=np.array([0,0])
eg2=np.array([0,1])
eg3=np.array([1,0])
eg4=np.array([1,1])
print("NAND(0,0)",NANDgate(eg1))
print("NAND(0,1)",NANDgate(eg2))
print("NAND(1,0)",NANDgate(eg3))
print("NAND(1,1)",NANDgate(eg4))
