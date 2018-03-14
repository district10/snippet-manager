File file = new File("file");
if (!file.exists()) {
    file.mkdir();
    // file.mkdirs();
    // file.createNewFile();
    System.out.println("Generated file " + file.getAbsolutePath());
}
