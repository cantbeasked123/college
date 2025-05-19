import numpy as np
def activation(f):
    if f<=0.5:
        return 1
    else:
        return 0
def neuron(x,w,b):
    r=np.dot(x,w)+b
    return activation(r)
def NORgate(x):
    w=np.array([1,1])
    b=0.5
    return neuron(x,w,b)
eg1=np.array([0,0])
eg2=np.array([0,1])
eg3=np.array([1,0])
eg4=np.array([1,1])
print("NOR(0,0)",NORgate(eg1))
print("NOR(0,1)",NORgate(eg2))
print("NOR(1,0)",NORgate(eg3))
print("NOR(1,1)",NORgate(eg4))
