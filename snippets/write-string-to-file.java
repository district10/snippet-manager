BufferedWriter out = null;
try {
    out = new BufferedWriter(new FileWriter("filename", true));
    out.write("aString"); // write string to file
} catch (IOException e) {
    // error processing code
} finally {
    if (out != null) {
        out.close();
    }
}
