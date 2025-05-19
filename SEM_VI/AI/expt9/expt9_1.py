import numpy as np
def activation(f):
    if f<2.5:
        return 0
    else:
        return 1
def neuron(x,w,b):
    r=np.dot(x,w)+b
    return activation(r)
def ANDgate(x):
    w=np.array([1,1])
    b=0.5
    return neuron(x,w,b)
eg1=np.array([0,0])
eg2=np.array([0,1])
eg3=np.array([1,0])
eg4=np.array([1,1])
print("AND(0,0)",ANDgate(eg1))
print("AND(0,1)",ANDgate(eg2))
print("AND(1,0)",ANDgate(eg3))
print("AND(1,1)",ANDgate(eg4))
