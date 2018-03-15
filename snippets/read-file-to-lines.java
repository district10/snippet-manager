public static List<String> readLines(String filename) throws IOException {
    return Files.readAllLines(new File(filename).toPath());
}
