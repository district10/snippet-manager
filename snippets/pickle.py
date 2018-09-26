import pickle
import tempfile

dumped_path = tempfile.mktemp()
pickle.dump(slam_map, open(dumped_path, 'wb'))
slam_map = pickle.load(open(dumped_path, 'rb'))
