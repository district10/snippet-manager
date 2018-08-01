def invT(Tcw):
    Rcw = Tcw[:3, :3]
    t = Tcw[:3, 3]
    Ow = -Rcw.T.dot(t)
    Twc = np.identity(4)
    Twc[:3, :3] = Rcw.T
    Twc[:3, 3] = Ow
    return Twc
