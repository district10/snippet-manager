T = np.matrix([[np.cos(p[2]),-np.sin(p[2]),p[0]],
               [np.sin(p[2]), np.cos(p[2]),p[1]],
               [0           ,0            ,1   ]])
n  = np.size(src,0)
xt = np.ones([n,3])
xt[:,:-1] = src
xt = (xt*T.T).A
d  = np.zeros(np.shape(src))
d[:,0] = xt[:,0]-dst[:,0]
d[:,1] = xt[:,1]-dst[:,1]
