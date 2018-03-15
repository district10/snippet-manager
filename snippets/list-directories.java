public static File[] listDirectories(String path) {
    return new File(path).listFiles(File::isDirectory); // isFile
}

// recursively
public static List<File> listAllFiles(String path) {
    List<File> all = new ArrayList<>();
    File[] list = new File(path).listFiles();
    if (list != null) {  // In case of access error, list is null
        for (File f : list) {
            if (f.isDirectory()) {
                all.addAll(listAllFiles(f.getAbsolutePath()));
            } else {
                all.add(f.getAbsoluteFile());
            }
        }
    }
    return all;
}
