# opencv read image or create
img = cv2.imread(input_path)
if img is None:
    img = np.zeros((1200, 1920, 3), np.uint8)
