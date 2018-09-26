video_writer = cv2.VideoWriter("show.avi", cv2.cv.CV_FOURCC('X', 'V', 'I', 'D'), // opencv 2
        10, (1200, 1920))
video_writer = cv2.VideoWriter("show.avi", cv2.VideoWriter_fourcc('X', 'V', 'I', 'D'), // cv2.VideoWriter_fourcc // opencv 3
        10, (1200, 1920))
video_writer.write(img)
video_writer.release()
