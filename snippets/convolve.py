ax.plot(timestamp, np.convolve(pitch, np.ones((100,)) / 100, mode='same'), color='green')
