//int main(int argc, char **argv) { // mock argc argv
int main(int ac, char **av) {
    int argc = 4;
    const char *argv[] = {
            av[0],
            CMAKE_SOURCE_DIR "/Vocabulary/ORBvoc.txt",
            CMAKE_SOURCE_DIR "/Examples/Monocular/TUM1.yaml",
            "/home/tzx/Data/TUM/rgbd_dataset_freiburg1_xyz"
    };
    // ...
}
